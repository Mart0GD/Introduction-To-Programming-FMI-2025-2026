#include <stdio.h>
  
/*
*   Част от типовете в езика C: (зависи от системата 32bit/64bit)


*   ------------- 1 byte
*   signed char
*   unsigned char
*   -------------- 2 bytes
*   short/ short int / signed short / signed short int 
*   unsigned short / unsigned short int
*   -------------- 4 bytes
*   int / signed / signed int
*   unsigned / unsigned int
*   -------------- 4 bytes
*   long / long int / signed long / signed long int 
*   unsigned long / unsigned long int 
*   -------------- 8 bytes
*   long long / long long int / signed long long / signed long long int 
*   unsigned long long / unsigned long long int 
*   --------------
*   float --> 4 bytes
*   double --> 8 bytes
*   long double --> 16 bytes
*   --------------
*/

  int main() {

    /*
        така четем от конзолата 
        Disclaimer - ако използвате Visual studio, най-вероятно ще ви даде грешка за scanf и ще иска да използвате 
        scanf_s (това да не ви плаши, само малка особеност на Microsoft)
    */
    int a;
    scanf("%d", &a); // !!! не забравяйте знака & !!! 
}