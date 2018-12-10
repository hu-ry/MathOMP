#include <stdbool.h>
#include <stdlib.h>
#include <omp.h>
#include <iostream>
#include "mathomp.h"
//
// Created by ryanh on 08.12.2018.
//

int main(int argc, char** argv) {
// give a number which should get checked as program parameter.
    if( argc < 2 )
    {
        printf( "Usage: %s <number to check>\n", argv[0] );
        return 1;
    }
// converts the given char(program parameter) into an unsigned 64bit integer
    int one = atoll(argv[1]);

    printf("Number is %llu \r\n", one);
    if(one<=1) {
        printf("Given number is 1 or smaller invalid input! \r\n");
        return 0;
    }
    // prints out the maximum number of threads on the current machine.
    printf("Max number of threads: %d\n", omp_get_max_threads());

    double start, end, delta;

    start = omp_get_wtime();
    // To calculate the time it takes till the number gets confirmed as prime number
    bool primOne = isPrimei(one); // invoking isPrime() with number
    // or not.
    end = omp_get_wtime();
    delta = end - start;
    printf("%llu took %.10f to finish!\n", one, delta); // prints out the time it took

    printf("The number %llu is %d.\n",one , primOne);
    // returns 0 or 1 if the number was a prime number.
    getchar();
    return 0;
}