//
// Created by hury on 16/08/2020.
//

#include <cstdlib>
#include <cstdio>

#include "../include/benchmark.h"

int main(int argc, char** argv) {
// give a number which should get checked as program parameter.
    if (argc < 2) {
        printf("Usage: %s <number to check>\n", argv[0]);
        printf("Parameter:\n "
               "<number to check>\n"
               "Enter a number to check\n\n"
               "-----------------------------------\n");
        return 1;
    }

    unsigned int long long value_llu;

    value_llu = strtoll(argv[1], nullptr, 10);
    printf("Number is %llu llu\r\n", value_llu);
    if(value_llu<=1) {
        printf("Given number is 1 or smaller invalid input! \r\n");
        return 1;
    }



    return 0;
}