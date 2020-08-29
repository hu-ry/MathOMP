cmake_minimum_required(VERSION 3.12)
project(MathOMP VERSION 0.1.0)
include(GNUInstallDirs)
SET(CMAKE_CXX_FLAGS "-lstdc++ -O3 -Wall -pthread -fcheck-new -g  ")
set(CMAKE_CXX_STANDARD 14)
find_package(OpenMP)

link_libraries(-lm -lbenchmark -lpthread)

include_directories("include/mathomp" "include")

SET(GOOGLE_BENCHMARK_SRC src/gbenchmark.cpp)

set(ARRAYTESTER_SOURCE TesterPrograms/ArrayTester.cpp)
set(BENCHMARKTESTER_SOURCE TesterPrograms/benchmarkTester.cpp)
set(PRIMETESTER_SOURCE TesterPrograms/primecheckerTester.cpp)
set(SINUSTESTER_SOURCE TesterPrograms/sinusCalcTester.cpp)

set(TESTER_SOURCE ${ARRAYTESTER_SOURCE} ${BENCHMARKTESTER_SOURCE}
        ${PRIMETESTER_SOURCE} ${SINUSTESTER_SOURCE})

set(SOURCE_FILES src/mathomp.cpp include/mathomp/mathomp.h)

add_executable(ArrayTester ${ARRAYTESTER_SOURCE})
add_executable(BenchmarkTester ${BENCHMARKTESTER_SOURCE})
add_executable(PrimeCheckerTester ${PRIMETESTER_SOURCE})
add_executable(SinusCalcTester ${SINUSTESTER_SOURCE})

add_executable(GBench ${GOOGLE_BENCHMARK_SRC})


add_library(MathOMP STATIC ${SOURCE_FILES})

if(OpenMP_CXX_FOUND)
    target_link_libraries(ArrayTester PUBLIC OpenMP::OpenMP_CXX MathOMP)
    target_link_libraries(BenchmarkTester PUBLIC OpenMP::OpenMP_CXX MathOMP)
    target_link_libraries(PrimeCheckerTester PUBLIC OpenMP::OpenMP_CXX MathOMP)
    target_link_libraries(SinusCalcTester PUBLIC OpenMP::OpenMP_CXX MathOMP)

    target_link_libraries(GBench PUBLIC OpenMP::OpenMP_CXX MathOMP)
endif()

install(TARGETS MathOMP DESTINATION lib)
install(FILES mathomp.h DESTINATION include)