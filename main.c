#include <stdio.h>
#include <omp.h>

int main(void){
    #pragma omp parallel num_threads(8)
    {
        printf("Kamil\n");
    }

    return 0;
}
