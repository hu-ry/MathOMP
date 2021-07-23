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
 * Created by hury on 19/08/2020.
 */

#include "googlebenchmark.h"
#include "mathomp.h"

#include <cmath>
#include <benchmark/benchmark.h>

const static int size = 50;
double TestingData[size] = {};

static void BM_StdSin(benchmark::State& state) {
    srand48(8597243);
    for(int i=0; i<size; i++) {
        TestingData[i] = drand48();
    }

    for (auto _ : state) {
        //TestingData[state.range(0)] = sin(TestingData[state.range(0)]);
        benchmark::DoNotOptimize(sin(TestingData[state.range(0)]));
    }
}

static void BM_InternetSinus(benchmark::State& state) {
    srand48(91723412);
    for(int i=0; i<size; i++) {
        TestingData[i] = drand48();
    }

    for (auto _ : state) {
        //TestingData[state.range(0)] = sinusInternet(TestingData[state.range(0)]);
        benchmark::DoNotOptimize(sinusInternet(TestingData[state.range(0)]));

    }
}

static void BM_CustomSinus(benchmark::State& state) {
    srand48(1389434);
    for(int i=0; i<size; i++) {
        TestingData[i] = drand48();
    }

    for (auto _ : state) {
        //TestingData[state.range(0)] = sinus(TestingData[state.range(0)]);
        benchmark::DoNotOptimize(sinus(TestingData[state.range(0)]));
    }
}

BENCHMARK(BM_StdSin)->Arg(15)->Arg(30)->Arg(50);

BENCHMARK(BM_InternetSinus)->Arg(15)->Arg(30)->Arg(50);

BENCHMARK(BM_CustomSinus)->Arg(15)->Arg(30)->Arg(50);

BENCHMARK_MAIN();