#include <stdio.h>

int main()
{
    unsigned int year;
    printf("Enter an year:\n");
    scanf("%u", &year);
    int result = (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    printf("1 means that %u is leap year and 0 means that it's not a leap year\n", year);
    printf("Result = %d", result);
    
    return 0;
}
