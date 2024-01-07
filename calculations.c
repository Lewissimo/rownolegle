#include <stdio.h>
#include <stdlib.h>
#include <time.h>

struct times_ {
    double time_omp_;
    cloct_t time_h;
};

struct approaches_{
    struct times_ sequentially,
    struct times_ domain,
    struct times_ functional
}

struct alg_{
    struct approaches crossing_out,
    struct approaches sito_eratostenesa
};

struct result_{
    int *primeNumbers;
    struct alg_ times;
}

struct times_ *execute_calculations(int first_num, int last_num) {
    if(first_num < 2){
        first_num = 2;
    }
    if(first_num > last_num){
        int x = first_num;
        first_num = last_num;
        last_num = x;
    }


    struct times_ *times_values = malloc(sizeof(struct times_));
    if (times_values == NULL) {
        return NULL;
    }



    return times_values;
}