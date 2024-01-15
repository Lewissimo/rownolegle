#include <stdio.h>
#include <omp.h>
#include "algorithms/algorithms.h"
int main(void){
    
    struct resultData *result = sitoSequentially(23, 225);

    displayTab(result->primes, result->amountOfPrimes);
    // sitoSequentially(2, 25);
    return 0;
}
