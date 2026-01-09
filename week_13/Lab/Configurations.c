#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

// (Комбинаторни Конфигурации)


typedef uint8_t _bool;
#define _true 1
#define _false 0

void swap(int* arr, unsigned int index1, unsigned int index2);

void k(int* set, unsigned int set_size, unsigned int output);
void print_combinations_without_repetition(int* set, int* combination, unsigned int set_size, unsigned int output, int current_index, int start);

void subsets(int* set, unsigned int n);
void print_subset(int* boolean, int* set, unsigned int set_size, int current_index);

void k_repetition(int* set, unsigned int set_size, unsigned int output);
void print_combinations_with_repetition(int* set, int* combination, unsigned int set_size, unsigned int output, int current_index, int start);

void k_order_of_n(int* set, unsigned int n);
void print_permutations(int* set, unsigned int set_size, unsigned int current_index);

void k_order_repetition_of_n(int* set, unsigned int n );
void print_permutations_with_repetition(int* set, int* combination, _bool* used, unsigned int set_size, unsigned int current_index);

void k_order(int* combination, unsigned int n, unsigned int output);
void print_variations_without_repetition(int* set, int* combination, _bool* in_use, unsigned int set_size, unsigned int output, unsigned int current_index);

void k_order_repetition(int* set, unsigned int n, unsigned int output);
void print_variations_with_repetition(int* set, int* combination, unsigned int set_size, unsigned int output, unsigned int current_index);

int main(){

    // !!WARNING!!
    // the implementations relly on the fact that a set has no duplicate values
    // if you insert two equal values they will be treated as different


    unsigned int n, m;
    printf("Insert set size: "); scanf("%u", &n);
    printf("Insert output subset size: "); scanf("%d", &m);

    int* set = (int*)malloc(sizeof(int) * n);
    if(!set) return -1;
    for(unsigned int i = 0; i < n; ++i) { printf("Insert number %d: ", i + 1); scanf("%d", &set[i]); }

    subsets(set, n);                        // subsets

    k(set, n, m);                           // combinations without repetition
    k_repetition(set, n, m);                // combinations with    repetition


    k_order_of_n(set, n);                   // permutations without repetition
    k_order_repetition_of_n(set, n);        // permutations with    repetition

    k_order_repetition(set, n, m);          // variations with      repetition
    k_order(set, n, m);                     // variations without   repetition


    free(set);
    set = NULL;
    return 0;
}


void subsets(int* set, unsigned int n){
    int* boolean = (int*)malloc(sizeof(int) * n);
    if(!boolean) return;

    print_subset(boolean, set, n, 0);
    
    free(boolean);
    boolean = NULL;
}

// combinations
void k(int* set, unsigned int set_size, unsigned int output){

    int* combination = (int*)malloc(sizeof(int) * output);
    if(!combination) return;

    print_combinations_without_repetition(set, combination, set_size, output, 0, 0);

    // free
    free(combination);
    combination = NULL;
}

// all combinations with repetition
void k_repetition(int* set, unsigned int set_size, unsigned int output){

    int* combination = (int*)malloc(sizeof(int) * output);
    if(!combination) return;

    print_combinations_with_repetition(set, combination, set_size, output, 0, 0);

    // free
    free(combination);
    combination = NULL;
}

// variations with repetition
void k_order_repetition(int* set, unsigned int n, unsigned int output){

    int* combination = (int*)malloc(sizeof(int) * output);
    if(!combination) return;

    print_variations_with_repetition(set, combination, n, output, 0);

    free(combination);
    combination = NULL;
}

// variations without repetition
void k_order(int* set, unsigned int n, unsigned int output){

    int* combination = (int*)malloc(sizeof(int) * output); 
    if(!combination) return;

    _bool* in_use = (_bool*)calloc(sizeof(_bool), n);
    if(!in_use){
        free(combination);
        combination = NULL;
        return;
    }

    print_variations_without_repetition(set, combination, in_use, n, output, 0);

    // free
    free(combination); free(in_use);
    combination = NULL; in_use = NULL;
}

// permutations without_repetition
void k_order_of_n(int* set, unsigned int n) { print_permutations(set, n, 0); }

// permutations with_repetition
void k_order_repetition_of_n(int* set, unsigned int n ){ 
    _bool* used = (_bool*)calloc(sizeof(_bool), n);
    if(!used) return;

    int* combination = (int*)malloc(sizeof(int) * n);
    if(!combination){
         free(used);
        used = NULL;
        return;
    }
    
    // a lot of memory wasted here. But still, I found an algorithm
    print_permutations_with_repetition(set, combination, used, n, 0);

    // free
    free(used); free(combination);
    used = NULL; combination = NULL;
}

void print_subset(int* boolean, int* set, unsigned int set_size, int current_index){
    if(current_index == set_size){
        printf("Subset: {");
        for (unsigned int i = 0; i < set_size; i++) {
            if (boolean[i]){
                printf(" %d", set[i]);
            }
        }
        puts(" }");
        return;
    }

    boolean[current_index] = 0;
    print_subset(boolean, set, set_size, current_index + 1);
    boolean[current_index] = 1;
    print_subset(boolean, set, set_size, current_index + 1);
}

void print_permutations(int* set, unsigned int set_size, unsigned int current_index){
    if(current_index >= set_size){
        printf("Permutation: {");
        for (unsigned int i = 0; i < set_size; i++) 
            printf(" %u", set[i]);
        puts(" }");
        return;
    }

    for (unsigned int i = current_index; i < set_size; ++i) {
        swap(set, current_index, i);
        print_permutations(set, set_size, current_index + 1);
        swap(set, current_index, i);
    }
}
void print_permutations_with_repetition(int* set, int* combination, _bool* used, unsigned int set_size, unsigned int current_index){
    if(current_index >= set_size){
        printf("Permutation with repetition: {");
        for (unsigned int i = 0; i < set_size; i++) 
            printf(" %u", combination[i]);
        puts(" }");
        return;
    }

    for (unsigned int i = 0; i < set_size; ++i) {
        if(used[i]) continue;

        _bool duplicate = _false;
        for (unsigned int j = 0; j < i; ++j){
            if(!used[j] && set[j] == set[i]) 
                duplicate = _true;
        }

        if(duplicate) continue;

        used[i] = _true;
        combination[current_index] = set[i]; 
        print_permutations_with_repetition(set, combination, used, set_size, current_index + 1);
        combination[current_index] = -1;
        used[i] = _false;
    }
}

void print_combinations_with_repetition(int* set, int* combination, unsigned int set_size, unsigned int output, int current_index, int start){
    if(current_index == output){
        printf("Combination with repetition: {");
        for(int i = 0; i < output; ++i)
            printf(" %d", combination[i]);
        puts(" }");
        return;
    }

    for (int i = start ; i < set_size; ++i)
    {
        combination[current_index] = set[i];
        print_combinations_with_repetition(set, combination, set_size, output, current_index + 1, i);
    }
}
void print_combinations_without_repetition(int* set, int* combination, unsigned int set_size, unsigned int output, int current_index, int start){
    if(current_index == output){
        printf("Combination without repetition: {");
        for(int i = 0; i < output; ++i)
            printf(" %d", combination[i]);
        puts(" }");
        return;
    }

    for (int i = start ; i < set_size; ++i)
    {
        combination[current_index] = set[i];
        print_combinations_without_repetition(set, combination, set_size, output, current_index + 1, i + 1);
    }
}

void print_variations_with_repetition(int* set, int* combination, unsigned int set_size, unsigned int output, unsigned int current_index){
    if(current_index == output){
        printf("Variations with repetition: {");
        for (int i = 0; i < output; i++)
            printf(" %d", combination[i]);
        puts(" }");
        return;
    }

    for (unsigned i = 0; i < set_size; ++i){
        combination[current_index] = set[i];
        print_variations_with_repetition(set, combination, set_size, output, current_index + 1);
    }
}
void print_variations_without_repetition(int* set, int* combination, _bool* in_use, unsigned int set_size, unsigned int output, unsigned int current_index){
    if(current_index == output){
        printf("Variations without repetition: {");
        for (int i = 0; i < output; i++)
            printf(" %d", combination[i]);
        puts(" }");
        return;
    }

    for (unsigned i = 0; i < set_size; ++i){
        if(!in_use[i]){
            in_use[i] = _true;
            combination[current_index] = set[i];
            print_variations_without_repetition(set, combination, in_use, set_size, output, current_index + 1);
            in_use[i] = _false;
        }
    }
}

void swap(int* arr, unsigned int index1, unsigned int index2){
    int temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
}