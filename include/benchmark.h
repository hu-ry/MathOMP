/* MathOMP, math library with OpenMP.
 * Copyright (c) 2021, Ryan Huth
 *
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 * 1. Redistributions of source code must retain the above copyright notice, this
 *    list of conditions and the following disclaimer.
 *
 * 2. Redistributions in binary form must reproduce the above copyright notice,
 *    this list of conditions and the following disclaimer in the documentation
 *    and/or other materials provided with the distribution.
 *
 * 3. Neither the name of the copyright holder nor the names of its
 *    contributors may be used to endorse or promote products derived from
 *    this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
 * DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
 * SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
 * CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
 * OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 * OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
 *
 * Created by hury on 16/08/2020.
 */

#ifndef MATHOMP_BENCHMARK_H
#define MATHOMP_BENCHMARK_H

#include <vector>
#include <chrono>
#include <atomic>
#include <cstring>

namespace HuBench {
    class HuTime {
        std::chrono::high_resolution_clock _clock;

    public:
        static inline uint64_t millisec() {
            return std::chrono::duration_cast<std::chrono::milliseconds>
                    (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        }

        static inline uint64_t microsec() {
            return std::chrono::duration_cast<std::chrono::microseconds>
                    (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        }

        static inline uint64_t nanosec() {
            return std::chrono::duration_cast<std::chrono::nanoseconds>
                    (std::chrono::high_resolution_clock::now().time_since_epoch()).count();
        }
    };


    class Benchmark {
#define BENCH_VECTOR_CAPACITY 250
#define T_ENTRY_LABEL_SIZE 50
        typedef struct TimeEntry {
            uint64_t time = 0U;
            char label[T_ENTRY_LABEL_SIZE]{};

            TimeEntry() = default;
        } TimeEntry;
        using darray = std::vector<TimeEntry>;
    public:
        Benchmark() : _ActiveTime(0) {
            _Timings.reserve(BENCH_VECTOR_CAPACITY);
        }

        inline void startTiming(const char *msg_fmt) {
            if (!_IsRunning) {
                _IsRunning.store(true);
                strncpy(_Timings[_CurIndex].label, msg_fmt, T_ENTRY_LABEL_SIZE);

                _ActiveTime = HuTime::nanosec();
            }
        }

        inline void stopTiming() {
            uint64_t time = HuTime::nanosec();
            if (_IsRunning) {
                _Timings[_CurIndex].time = time - _ActiveTime;

                _IsRunning.store(_CurIndex >= BENCH_VECTOR_CAPACITY - 1);
                _CurIndex += _CurIndex < BENCH_VECTOR_CAPACITY - 1;
            }
        }

        void printAll() {
            for (int i = 0; i <= _CurIndex; i++) {
                printf(_Timings[i].label, _Timings[i].time);
            }
            reset();
        }

        void reset() {
            size = _Timings.size();
            _CurIndex = 0;
            _Timings.clear();
        }

        void printAt(int index) const {
            if (index <= _CurIndex) {
                printf(_Timings[index].label, _Timings[index].time);
            } else {
                printf("Access out of bounds! No entry for this index available.\n");
            }
        }

    private:
        int size = BENCH_VECTOR_CAPACITY;
        int _CurIndex = 0;
        darray _Timings;

        std::atomic_bool _IsRunning{false};
        uint64_t _ActiveTime;
    };

}; // End of namespace HuBench

#endif //MATHOMP_BENCHMARK_H
