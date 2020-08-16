//
// Created by hury on 10/12/2018.
//

#include <stdbool.h>
#include <omp.h>
#include <cmath>
#include "mathomp.h"

const double PI=3.1415926535897932384650288;


bool isPrimellu(unsigned long long* pn) {
    bool primIndicator = true;
    unsigned long long pnHalfed;
    if (*pn > 2 && *pn%2!=0 && *pn%3!=0 && *pn%5!=0) {
        pnHalfed = (unsigned long long)sqrtl(*pn);
    }   else {
        return false;
    }
//checks if the number is high enough to make a difference in time for the calculation, because of the parallelization overhead.
    if(pnHalfed > 36500000) { // manually adjustable for the used CPU to get the best performance

#pragma omp parallel shared(primIndicator)
        {
#pragma omp for schedule(dynamic, 5000)
            for (unsigned long long i_counter = 7; i_counter <= pnHalfed; i_counter = i_counter+2) {
                if (*pn % i_counter == 0) {
                    primIndicator = false;
#pragma omp cancel for
                }
#pragma omp cancellation point for
            }
        }
    } else {
        for (unsigned long long i_counter = 7; i_counter <= pnHalfed; i_counter = i_counter+2) {
            if (*pn % i_counter == 0) {
                primIndicator = false;
                break;
            }
        }
    }
    return primIndicator;
}

bool isPrimei(int pn) {
    bool primIndicator = true;
    int pnHalfed;
    if (pn > 2 && pn%2!=0 && pn%3!=0 && pn%5!=0) {
        pnHalfed = pn / 2;
    }   else {
        return false;
    }
//checks if the number is high enough to make a difference in time for the calculation, because of the parallelization overhead.
    if(pnHalfed > 5000000) {

#pragma omp parallel shared(primIndicator)
        {
#pragma omp for
            for (int i_counter = 4; i_counter <= pnHalfed; i_counter++) {
                if (pn % i_counter == 0) {
                    primIndicator = false;
#pragma omp cancel for
                }
#pragma omp cancellation point for
            }
        }

    } else {

        for (int i_counter = 4; i_counter < pnHalfed; i_counter++) {
            if (pn % i_counter == 0) {
                primIndicator = false;
                break;
            }
        }
    }
    return primIndicator;
}

bool isPrimei(int* pn) {
    bool primIndicator = true;
    int pnHalfed;
    if (*pn > 2 && *pn%2!=0 && *pn%3!=0 && *pn%5!=0) {
        pnHalfed = *pn / 2;
    }   else {
        return false;
    }
//checks if the number is high enough to make a difference in time for the calculation, because of the parallelization overhead.
    if(pnHalfed > 5000000) {

#pragma omp parallel shared(primIndicator)
        {
#pragma omp for
            for (int i_counter = 4; i_counter <= pnHalfed; i_counter++) {
                if (*pn % i_counter == 0) {
                    primIndicator = false;
#pragma omp cancel for
                }
#pragma omp cancellation point for
            }
        }

    } else {

        for (int i_counter = 4; i_counter < pnHalfed; i_counter++) {
            if (*pn % i_counter == 0) {
                primIndicator = false;
                break;
            }
        }
    }
    return primIndicator;
}

int facult(int fac) {
    if(fac == 0)
        return fac;

    if(fac == 1)
        return fac;

    int i = 1;
    int result = 1;
    while (fac >= i) {
        result*=i;
        i++;
    }
    return result;
}

#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wstrict-aliasing"

inline float sqrt_aprox(float base) {
    int i;
    float x, y;
    x = base * 0.5;
    y = base;
    i = * (int * ) &y;
    i = 0x5f3759df - (i >> 1);
    y = * ( float * ) &i;
    y = y * (1.5 - (x * y * y));
    y = y * (1.5 - (x * y * y));
    return base * y;
}
#pragma GCC diagnostic pop

double calcSin(double x) {
    double sign=1;
    if (x<0){
        sign=-1.0;
        x=-x;
    }
    if (x>360) x -= int(x/360)*360;
    x*=PI/180.0;

    double result = 0;
    double term = x;

    for (int n_iterator = 1; result+term!=result; ++++n_iterator) {
        result+=term;
        n_iterator+=2;
        term*=-x*x/n_iterator/(n_iterator-1);
    }

    return sign*result;
}


