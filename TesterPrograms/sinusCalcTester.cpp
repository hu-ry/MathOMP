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
 * Created by hury on 04/02/2019.
 */

#include <cstdlib>
#include <omp.h>
#include <cstdio>
#include "mathomp.h"

int main(int argc, char** argv) {
// give a number which should get checked as program parameter.
    if( argc < 2 )
    {
        printf( "Usage: %s <number to check>\n", argv[0] );
        return 1;
    }
// converts the given char(program parameter) into an unsigned 64bit integer
    double one = atof(argv[1]);

    printf("Number is %.10f \r\n", one);

    // prints out the maximum number of threads on the current machine.
    printf("Max number of threads: %d\n", omp_get_max_threads());

    double sinResult;
    double start, end, delta;

    start = omp_get_wtime();
    // To calculate the time it takes till the number gets confirmed as prime number
    sinResult = calcSin(one);
    // or not.
    end = omp_get_wtime();
    delta = end - start;
    printf("Result: %f took %.15f to finish!\n", sinResult, delta); // prints out the time it took

    getchar();
    return 0;
}