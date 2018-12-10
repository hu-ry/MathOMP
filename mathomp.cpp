#include <stdbool.h>
#include <omp.h>
#include "mathomp.h"

bool isPrime(unsigned long long pn) {
    bool primIndicator = true;
    unsigned long long pnHalfed;
    if (pn > 2 && pn%2!=0 && pn%3!=0) {
        pnHalfed = pn / 2;
    }   else {
        return false;
    }
//checks if the number is high enough to make a difference in time for the calculation, because of the parallelization overhead.
    if(pnHalfed > 36500000) {

#pragma omp parallel shared(primIndicator)
        {
#pragma omp for schedule(dynamic, 5000)
            for (unsigned long long i_counter = 4; i_counter <= pnHalfed; i_counter++) {
                if (pn % i_counter == 0) {
                    primIndicator = false;
#pragma omp cancel for
                }
#pragma omp cancellation point for
            }
        }

    } else {

        for (unsigned long long i_counter = 4; i_counter < pnHalfed; i_counter++) {
            if (pn % i_counter == 0) {
                primIndicator = false;
                break;
            }
        }
    }
    if(primIndicator==true) {
        return true;
    } else {
        return false;
    }
}