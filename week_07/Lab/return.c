#include <stdio.h>

int do_smth(int a, int b);
int do_smth_correct(int a, int b);
void void_return_example(int a);

int main(){

    int some_value;
    some_value = do_smth(1, 2); // !!this is undefined behaviour!!
    some_value = do_smth_correct(1,2);

    void_return_example(6);

    return 0; // Each function with a return type SHOULD return a value
}

void void_return_example(int a){
    if(a < 5) return;

    printf("number is >= 5\n");
}

int do_smth(int a, int b){

    /*
        This function is invalid
        Each branch of the function should return a value if the function has a return type
    */

    if(a > b) return 5; 
}

int do_smth_correct(int a, int b){

    /*
        This function is invalid
        Each branch of the function should return a value if the function has a return type
    */

    if(a > b)   return 5;  // the function stops execution here
    
    
    return 6; // default return value
}