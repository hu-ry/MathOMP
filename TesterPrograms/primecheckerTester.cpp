#include <omp.h>
#include <cstdbool>
#include <cstdlib>
#include <cstdio>
#include <cstring>

#include "mathomp.h"
//
// Created by ryanh on 08.12.2018.
//
#ifdef __linux__
#define LOG_FILE_PATH "log/primecheckerTester.log"

#elif _WIN32
#define LOG_FILE_PATH "log//primecheckerTester.log"

#else
#error "OS not supported!"
#endif

int main(int argc, char** argv) {
// give a number which should get checked as program parameter.
    if( argc < 3 )
    {
        printf( "Usage: %s <number to check> <Integer Variation>\n", argv[0] );
        printf( "Parameter:\n "
                "<number to check>\n"
                "Enter a number to check\n\n"
                "<Integer Variation>\n"
                "llu - unsigned int long long 64bit\n "
                "i - int 32bit\n "
                "-----------------------------------\n");
        return 1;
    }
// converts the given char(program parameter) into an unsigned 64bit integer
    FILE *file_p = fopen(LOG_FILE_PATH, "a+");


    unsigned int long long value_llu;
    int value_i;

    if(strcmp(argv[2], "llu") == 0) {

        value_llu = strtoll(argv[1], nullptr, 10);
        printf("Number is %llu llu\r\n", value_llu);
        fprintf(file_p, "Number is %llu llu\r\n", value_llu);

        if(value_llu<=1) {
            fclose(file_p);
            printf("Given number is 1 or smaller invalid input! \r\n");
            return 1;
        }
    } else if(strcmp(argv[2], "i") == 0) {

        value_i = atoi(argv[1]);
        printf("Number is %d i\r\n", value_i);
        fprintf(file_p, "Number is %d i\r\n", value_i);

        if(value_i<=1) {
            fclose(file_p);
            printf("Given number is 1 or smaller invalid input! \r\n");
            return 1;
        }
    } else {
        fclose(file_p);
        printf("Given type is an invalid input! %s , %s , %s\r\n", argv[0], argv[1] ,argv[2]);
        return 1;
    }


    // prints out the maximum number of threads on the current machine.
    fprintf(file_p, "Max number of threads: %d\n", omp_get_max_threads());
    printf("Max number of threads: %d\n", omp_get_max_threads());

    double start, end, delta;

    start = omp_get_wtime();
    // To calculate the time it takes till the number gets confirmed as prime number
    bool primOne = strcmp(argv[2], "llu") ? isPrimellu(&value_llu) : isPrimei(&value_i); // invoking isPrimellu() or
    // isPrimei(), depending on the the type, with number or not.
    end = omp_get_wtime();
    delta = end - start;

    fprintf(file_p, "Took %.10f seconds to finish!\n", delta);
    printf("Took %.10f seconds to finish!\n", delta); // prints out the time it took

    if(strcmp(argv[2], "llu") == 0) {
        fprintf(file_p, "The number %llu is %d prime!\n \n", value_llu, primOne);
        printf("The number %llu is %d prime!\n", value_llu, primOne);
    } else {
        fprintf(file_p, "The number %d is %d prime!\n \n", value_i, primOne);
        printf("The number %d is %d prime!\n", value_i, primOne);
    }
    // returns 0 or 1 if the number was a prime number.
    fclose(file_p); // Closes the writing into the file


    getchar();
    return 0;
}