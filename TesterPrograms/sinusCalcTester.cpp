#include <stdlib.h>
#include <omp.h>
#include <iostream>
#include "../mathomp.h"
//
// Created by ryanh on 04/02/2019.
//

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