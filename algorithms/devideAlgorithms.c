#include "algorithms.h"





struct resultData *divVersion(int firstNum, int lastNum){
//Function security
    if(firstNum < 2) firstNum = 2;
    if(firstNum > lastNum){
        int tempVal = firstNum;
        firstNum = lastNum;
        lastNum = tempVal;
    }
    

//Preparing results data and variables
//Result structure
    struct resultData *result = malloc(sizeof(struct resultData));
    if(result == NULL){
        printf("ALLOCATE resultData ERROR");
        exit(1);
    }
    result->amountOfPrimes = 0;
    result->ompTime = 0;
    result->primes = NULL;
    result->time_h = 0;
    
//Helpers variables
    int size = lastNum - firstNum + 1;
    int *tab = create_tab(size);
    struct transformDataFunctionResponse *representativeData = NULL;

//Clock variables
    clock_t time_h_start, time_h_stop;
	double time_omp_start, time_omp_stop;


	time_omp_start = omp_get_wtime();
	time_h_start = clock();
//Algorithm
    for(int i = 0; size > i; i++){
        if((i + firstNum) % 2 == 0){
            tab[i] = FALSE;
        }
        for(int j = 3; j * j <= i + firstNum; j+= 2){
            if((i + firstNum) % j == 0){
                tab[i] = FALSE;
                break;
            }

        }
    }

    time_h_stop = clock();
    time_omp_stop = omp_get_wtime();
    result->ompTime = time_omp_stop - time_omp_start;
    result->time_h = time_h_stop - time_h_start;
//Filing returning tab
    representativeData = transformBoolDataIntoResultTab(tab, size, firstNum);
    if(representativeData == NULL){
        free(result);
        exit(1);
    }
    result->amountOfPrimes = representativeData->size;
    result->primes = representativeData->tab;
    free(tab);
    return result;

}

struct resultData *divVersionParallel(int firstNum, int lastNum){

//Function security
    if(firstNum < 2) firstNum = 2;
    if(firstNum > lastNum){
        int tempVal = firstNum;
        firstNum = lastNum;
        lastNum = tempVal;
    }
    

//Preparing results data and variables
//Result structure
    struct resultData *result = malloc(sizeof(struct resultData));
    if(result == NULL){
        printf("ALLOCATE resultData ERROR");
        exit(1);
    }
    result->amountOfPrimes = 0;
    result->ompTime = 0;
    result->primes = NULL;
    result->time_h = 0;
    
//Helpers variables
    int size = lastNum - firstNum + 1;
    int *tab = create_tab(size);
    struct transformDataFunctionResponse *representativeData = NULL;
//Clock variables
    clock_t time_h_start, time_h_stop;
	double time_omp_start, time_omp_stop;


	time_omp_start = omp_get_wtime();
	time_h_start = clock();
//Algorithm
#pragma omp parallel 
#pragma omp for schedule(static, 1) nowait
    for(int i = 0; size > i; i++){
        if((i + firstNum) % 2 == 0){
            tab[i] = FALSE;
        }
        for(int j = 3; j * j <= i + firstNum; j+= 2){
            if((i + firstNum) % j == 0){
                tab[i] = FALSE;
                break;
            }

        }
    }

    time_h_stop = clock();
    time_omp_stop = omp_get_wtime();
    result->ompTime = time_omp_stop - time_omp_start;
    result->time_h = time_h_stop - time_h_start;
//Filing returning tab
    
    representativeData = transformBoolDataIntoResultTab(tab, size, firstNum);
    if(representativeData == NULL){
        free(result);
        exit(1);
    }
    result->amountOfPrimes = representativeData->size;
    result->primes = representativeData->tab;

    free(tab);
    return result;



}