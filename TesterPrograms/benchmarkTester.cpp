//
// Created by hury on 16/08/2020.
//

#include <cstdlib>
#include <cstdio>
#include <cmath>
#include <random>
#include <zconf.h>

#include "../mathomp.h"
#include "../include/benchmark.h"

void benchmarkSinus(Benchmark &marker) {
    double* TestingData = new double[50];
    //double* ResultingData = new double[50];

    for(int i=0; i<50; i++) {
        TestingData[i] = drand48();
    }

    printf("Generated Testing Data!\n");
    printf("#######################\n");
    sleep(1);

    for(int i=0; i<50; i++) {
        marker.startTiming("sin() took: %llu nsec\n");
        sin(TestingData[i]);
        marker.stopTiming();
    }

    sleep(1);

    for(int i=0; i<50; i++) {
        printf("For input: %f this is the result:  ", TestingData[i]);
        marker.printAt(i);
    }
    marker.reset();
    printf("#######################\n");

    sleep(1);

    for(int i=0; i<50; i++) {
        marker.startTiming("calcSin() took: %llu nsec\n");
        calcSin(TestingData[0]);
        marker.stopTiming();
    }

    sleep(1);

    for(int i=0; i<50; i++) {
        printf("For input: %f this is the result:  ", TestingData[i]);
        marker.printAt(i);
    }
    marker.reset();
    printf("#######################\n");
    //
    //sleep(1);
    //
    //for(int i=0; i<50; i++) {
    //    marker.startTiming("sinusInternet() took: %llu nsec\n");
    //    sinusInternet(TestingData[0]);
    //    marker.stopTiming();
    //}
    //
    //sleep(1);
    //
    //for(int i=0; i<50; i++) {
    //    printf("For input: %f this is the result:  ", TestingData[i]);
    //    marker.printAt(i);
    //}
    //marker.reset();
    printf("######## FINAL-SINUS #########\n");

    sleep(1);

    for(int i=0; i<50; i++) {
        marker.startTiming("sinus() took: %llu nsec\n");
        sinus(TestingData[0]);
        marker.stopTiming();
    }

    sleep(1);

    for(int i=0; i<50; i++) {
        printf("For input: %f this is the result:  ", TestingData[i]);
        marker.printAt(i);
    }
    marker.reset();
    printf("######### END ##########\n");

    double test = 3.1415926535897932384650288;

    printf("#########VVV##########\n");
    printf("\n sin(%4.9f) = %4.9f  \n", test, sin(test));
    printf("\n calcSin(%4.9f) = %4.9f  \n", 180.0, calcSin(180.0));
    printf("\n sinusInternet(%4.9f) = %4.9f  \n", test, sinusInternet(test));
    printf("\n sinus(%4.9f) = %4.9f  \n", test, sinus(test));

    printf("#########VVV##########\n");
    test = drand48();

    printf("\n sin(%4.9f) = %4.9f  \n", test, sin(test));
    printf("\n ________________  \n");
    printf("\n sinusInternet(%4.9f) = %4.9f  \n", test, sinusInternet(test));
    printf("\n sinus(%4.9f) = %4.9f  \n", test, sinus(test));

    printf("##########VVV#########\n");
    test = drand48();

    printf("\n sin(%4.9f) = %4.9f  \n", test, sin(test));
    printf("\n ____________________  \n");
    printf("\n sinusInternet(%4.9f) = %4.9f  \n", test, sinusInternet(test));
    printf("\n sinus(%4.9f) = %4.9f  \n", test, sinus(test));

    test = 10.00;

    printf("\n %4.9f^2 = %4.9f  \n", test, test*test);
    printf("\n inv_sqrt(%4.9f) = %4.9f  \n", test, inv_sqrt((float)test));
    printf("\n sqrt_aprox(%4.9f) = %4.9f  \n", test, sqrt_aprox((float)test));


    delete[]TestingData;
    //delete[]ResultingData;
}

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
    srand48((long)value_llu);

    Benchmark marker;

    benchmarkSinus(marker);

    return 0;
}
