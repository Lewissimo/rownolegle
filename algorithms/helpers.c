 #include "algorithms.h"
 
 struct transformDataFunctionResponse *transformBoolDataIntoResultTab(int *boolData, int size, int firstNum){

    struct transformDataFunctionResponse *result = malloc(sizeof(struct transformDataFunctionResponse));
    result->tab = NULL;
    result->size = 0;
    for(int i = 0; size > i; i++){
        if(boolData[i] == TRUE) {
            result->size++;
            result->tab = realloc(result->tab, sizeof(int) * result->size);
            if(result->tab == NULL){
                printf("ALLOCATE TABLE ERROR");
                return NULL;
            }
            result->tab[result->size - 1] = i + firstNum;
        }
    }

    return result;

 }

 int *create_tab(int size){
    int *tab = malloc(size * sizeof(int));
    for(int i = 0; size > i; i++){
        tab[i] = TRUE;
    }

    return tab;
}