#include "algorithms.h"

int *preparePrimesTab(int lastNum, int *size){
    int lastNumSqrt = ceil(sqrt(lastNum));
    int count = 0;
    int isPrime;
    int *primes = (int *)malloc(sizeof(int));

     for (int i = 2; i <= lastNumSqrt; i++) {
        isPrime = TRUE;
        for (int j = 2; j * j <= i; j++) {
            if (i % j == 0) {
                isPrime = FALSE;
                break;
            }
        }

        if (isPrime) {
            primes = (int *)realloc(primes, (count + 1) * sizeof(int));
            primes[count++] = i;
        }
    }
    *size = count; 
    return primes;
}



struct resultData *sitoSequentially(int firstNum, int lastNum){

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

    //Clock variables
    clock_t time_h_start, time_h_stop;
	double time_omp_start, time_omp_stop;


    //Helpers variables
    int size = lastNum - firstNum + 1;
    int primesInputTabSize;
    int *tab = create_tab(size);
    struct transformDataFunctionResponse * representativeData = NULL;
    
    int lower_limit, upper_limit;
    
    time_omp_start = omp_get_wtime();
	time_h_start = clock();
    
    int *primesInputTab = preparePrimesTab(lastNum, &primesInputTabSize);
    //algorithm
    for(int i = 0; i < primesInputTabSize; i++){
        lower_limit = (2 > firstNum/primesInputTab[i]) ? 2: ceil(firstNum/primesInputTab[i]);
        upper_limit = floor(lastNum/primesInputTab[i]);
        for(int j = lower_limit; j <= upper_limit; j++){
            tab[j * primesInputTab[i] - firstNum] = FALSE;
        }
    }
    time_h_stop = clock();
    time_omp_stop = omp_get_wtime();
    result->ompTime = time_omp_stop - time_omp_start;
    result->time_h = time_h_stop - time_h_start;

    //Transform data into tab
    representativeData = transformBoolDataIntoResultTab(tab, size, firstNum);
    if(representativeData == NULL){
        free(result);
        exit(1);
    }
    result->amountOfPrimes = representativeData->size;
    result->primes = representativeData->tab;



    return result;
}


struct resultData *sitoDOM(int firstNum, int lastNum){

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

    //Clock variables
    clock_t time_h_start, time_h_stop;
	double time_omp_start, time_omp_stop;


    //Helpers variables
    int size = lastNum - firstNum + 1;
    int primesInputTabSize;
    int *tab = create_tab(size);
    struct transformDataFunctionResponse * representativeData = NULL;
    
    int lower_limit, upper_limit;
    
    time_omp_start = omp_get_wtime();
	time_h_start = clock();
    
    int *primesInputTab = preparePrimesTab(lastNum, &primesInputTabSize);






    //algorithm -----------------------------------------------------------------

    for(int i = 0; i < primesInputTabSize; i++){
        lower_limit = (2 > firstNum/primesInputTab[i]) ? 2: ceil(firstNum/primesInputTab[i]);
        upper_limit = floor(lastNum/primesInputTab[i]);
        for(int j = lower_limit; j <= upper_limit; j++){
            tab[j * primesInputTab[i] - firstNum] = FALSE;
        }
    }


    //------------------------------------------------------------------------
    time_h_stop = clock();
    time_omp_stop = omp_get_wtime();
    result->ompTime = time_omp_stop - time_omp_start;
    result->time_h = time_h_stop - time_h_start;







    //Transform data into tab
    representativeData = transformBoolDataIntoResultTab(tab, size, firstNum);
    if(representativeData == NULL){
        free(result);
        exit(1);
    }
    result->amountOfPrimes = representativeData->size;
    result->primes = representativeData->tab;



    return result;
}

