#ifndef ALGORITHM_H
#define ALGORITHM_H
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>
#include <time.h>
#include <math.h>
#define TRUE 1
#define FALSE 0




struct resultData {
    int *primes;
    int amountOfPrimes;
    double ompTime;
    clock_t time_h;
};

struct transformDataFunctionResponse{
    int size;
    int *tab;
};

int *create_tab(int size);
struct transformDataFunctionResponse *transformBoolDataIntoResultTab(int *boolData, int size, int firstNum);

void displayTab(int *tab, int size);


struct resultData* divVersion(int firstNum, int lastNum);
struct resultData *divVersionParallel(int firstNum, int lastNum);
struct resultData *sitoSequentially(int firstNum, int lastNum);
#endif // ALGORITHM_H
