#include <stdbool.h>
#include <stdlib.h>
#include <omp.h>
#include <iostream>
#include <fstream>

#include "../mathomp.h"
using namespace std;
//
// Created by ryanh on 08.12.2018.
//

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
    FILE *file_p;
    file_p = fopen("log//primecheckerTester.log", "a+");


    unsigned int long long value_llu;
    int value_i;


    if((string)argv[2] == "llu") {

        value_llu = atoll(argv[1]);
        printf("Number is %llu llu\r\n", value_llu);
        fprintf(file_p, "Number is %llu llu\r\n", value_llu);

        if(value_llu<=1) {
            fclose(file_p);
            printf("Given number is 1 or smaller invalid input! \r\n");
            return 1;
        }
    } else if((string)argv[2] == "i") {

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
    bool primOne = (string)argv[2] == "llu" ? isPrimellu(&value_llu) : isPrimei(&value_i); // invoking isPrimellu() or
    // isPrimei(), depending on the the type, with number or not.
    end = omp_get_wtime();
    delta = end - start;

    fprintf(file_p, "Took %.10f seconds to finish!\n", delta);
    printf("Took %.10f seconds to finish!\n", delta); // prints out the time it took

    if((string)argv[2] == "llu") {
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