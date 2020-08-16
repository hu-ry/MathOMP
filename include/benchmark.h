//
// Created by hury on 16/08/2020.
//

#ifndef MATHOMP_BENCHMARK_H
#define MATHOMP_BENCHMARK_H

#include <vector>
#include <chrono>
#include <atomic>
#include <cstring>

class HuTime {
    std::chrono::high_resolution_clock _clock;

public:
    inline uint64_t millisec() {
        return std::chrono::duration_cast<std::chrono::milliseconds>
                (_clock.now().time_since_epoch()).count();
    }

    inline uint64_t microsec() {
        return std::chrono::duration_cast<std::chrono::microseconds>
                (_clock.now().time_since_epoch()).count();
    }

    inline uint64_t nanosec() {
        return std::chrono::duration_cast<std::chrono::nanoseconds>
                (_clock.now().time_since_epoch()).count();
    }
};



class Benchmark {
#define BENCH_VECTOR_CAPACITY 250
#define T_ENTRY_LABEL_SIZE 30
    typedef struct TimeEntry{
        uint64_t time = 0U;
        char label[T_ENTRY_LABEL_SIZE] {};
        TimeEntry() = default;
    } TimeEntry;
    using darray = std::vector<TimeEntry>;
public:
    Benchmark() {
        _IsRunning.store(false);
        _Timings.reserve(BENCH_VECTOR_CAPACITY);
    }

    inline void startTiming(const char* msg_fmt) {
        if(!_IsRunning) {
            _IsRunning.store(true);
            strncpy(_Timings[_CurIndex].label, msg_fmt, T_ENTRY_LABEL_SIZE);

            _ActiveTime = _Timer.nanosec();
        }
    }
    inline void stopTiming() {
        if(_IsRunning) {
            _Timings[_CurIndex].time = _Timer.nanosec() - _ActiveTime;

            _IsRunning.store(_CurIndex >= BENCH_VECTOR_CAPACITY-1);
            _CurIndex += _CurIndex < BENCH_VECTOR_CAPACITY-1;
        }
    }

    void printAll() {
        for(int i=0; i <= _CurIndex; i++) {
            printf(_Timings[i].label, _Timings[i].time);
        }
        size = _Timings.size();
        _CurIndex = 0;
        _Timings.clear();
    }

private:
    int size = BENCH_VECTOR_CAPACITY;
    int _CurIndex = 0;
    darray _Timings;

    std::atomic_bool _IsRunning;
    uint64_t _ActiveTime;
    HuTime _Timer;
};

#endif //MATHOMP_BENCHMARK_H
