#include <stdlib.h>
#include <omp.h>
#include <iostream>
#include "../mathomp.h"
//
// Created by Guest on 05/02/2019.
//

int main(int argc, char** argv) {
// give a number which should get checked as program parameter.
    if( argc < 2 )
    {
        printf( "Usage: %s <number to check>\n", argv[0] );
        return 1;
    }
// converts the given char(program parameter) into an unsigned 64bit integer
    int arraylenght = atoi(argv[1]);

    printf("Number is %d \r\n", arraylenght);

    // prints out the maximum number of threads on the current machine.
    printf("Max number of threads: %d\n", omp_get_max_threads());

    double start, end, delta;

    start = omp_get_wtime();
    // To calculate the time it takes till the number gets confirmed as prime number
    int arrayOne[arraylenght], arrayTwo[arraylenght], arrayThree[arraylenght];
    // or not.
    int temp = arraylenght;
    while(arraylenght>0) {
        arrayOne[temp-arraylenght] = arraylenght;
        arrayTwo[temp-arraylenght] = arraylenght;
        arrayThree[temp-arraylenght] = arraylenght;
        arraylenght--;
    }
    // array output
    printf("\r\n Array1: ");
    while(temp>arraylenght) {
        printf(" %d ,", arrayOne[arraylenght]);
        arraylenght++;
    }
    arraylenght=0;
    printf("\r\n Array2: ");
    while(temp>arraylenght) {
        printf(" %d ,", arrayTwo[arraylenght]);
        arraylenght++;
    }
    arraylenght=0;
    printf("\r\n Array3: ");
    while(temp>arraylenght) {
        printf(" %d ,", arrayThree[arraylenght]);
        arraylenght++;
    }

    end = omp_get_wtime();
    delta = end - start;
    printf("\r\n");
    printf("Result: %d took %.10f to finish!\n", arraylenght, delta); // prints out the time it took

    getchar();
    return 0;
}