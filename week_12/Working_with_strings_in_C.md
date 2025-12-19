# Работа със string в С
## Инициализация
Следните два начина са еквивалентни.

**а)**
<p>
  
```c
int main() {
  char str1[] = "Shrek";
  return 0;
}
```
</p>

**б)**
<p>
  
```c
int main() {
  char str1[] = {'S', 'h', 'r', 'e', 'k', '\0'};
  return 0;
}
```
</p>

## Заделяне на string в динамичната памет
<p>
  
```c
#include <stdio.h>
#include <stdlib.h>

int main() {
  
  char *str = calloc(8, sizeof(char));
  if (NULL == str) {
    printf("Unable to allocate memory. End of program\n");
    return -1;
  }

  free(str);
  return 0;
}
```
</p>

<img width="1195" height="658" alt="image" src="https://github.com/user-attachments/assets/d5f05f79-be11-4af6-9052-d23c61c7b7a3" />

## Фунцкии за работа със string
При работа със **string-ове** често ще ни се налага да използваме някакви операции. И когато често ни се налага да пишем един и същи код правим **функции**.
Истината е, че такива функции вече съществуват и са имплементирани в <string.h>, но в рамките на този курс **НЕ Е ПОЗВОЛЕНО ДА ГИ ИЗПОЛЗВАМЕ НАГОТОВО**. Това
е така с цел да упражним уменията ни да боравим с динамична памет, както и за да разберем как работят те "под капака". Затова сега ще покажем няколко такива основни
функции за работа със **string**.

## strlen()
**strlen()** е функция, връщаща ни дължината на текста, който масив от тип **char** съдържа.

**Примерна имплементация**
<p>
  
```c
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

size_t strlen(const char* str) {
  if (NULL == str)
    return -1;

  size_t count = 0;
  while ('\0' != str[count]) {
    ++count;
  }
  
  return count;
}
```
</p>

## strcpy()
**strcpy(char\* dest, const char\* src)** е фунция, копираща съдържанието на един **string** в друг.
Ако **dest** не е достатъчно дълъг масив имаме **undefined behaviour**. Ако **src** не е **null-terminated** отново имаме **undefined behaviour**.
**strcpy()** не се интересува от тези подробности и нейната работа е просто да копира от едно място на друго при подадени валидни аргументи. **strcpy**
копира И **терминиращата нула**. Функцията връща указател към **dest**.

**Примерна имплементация**
<p>
  
```c
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char *strcpy(char *dest, const char *src) {
    size_t i = 0;

    while ('\0' != src[i]) {
        dest[i] = src[i];
        i++;
    }

    dest[i] = '\0';
    return dest;
}
```
</p>


## strcat()
**strcat(char\* dest, const char\* src)** e функция, която слепва съдържанието на копие на **src** към края на **dest**. Операцията записва първият символ на **src** върху терминиращата
нула на **dest** и след слепването поставя нова такава. **dest** трябва да сочи към достатъчно голям блок памет, така, че съдържанието на двата string-a да може да бъде съхранено. **strcat()**
връща указател към **dest**

**Примерна имплементация**
<p>
  
```c
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

char* strcat(char *dest, const char *src) {
    int indexDest = 0;
    
    // iterate until '\0' is found
    while ('\0' != dest[indexDest]) {
        ++indexDest;
    }
    
    int indexSrc = 0; // new index to iterate over src
    while ('\0' != src[indexSrc]) {
        dest[indexDest++] = src[indexSrc++];
    }
    
    // don't forget to null-terminate 'dest'
    dest[indexDest] = '\0';
    
    return dest;    
}
```
</p>

<img width="1529" height="920" alt="image" src="https://github.com/user-attachments/assets/1fa4fc5f-7b33-4b13-bf18-fc36c436c0c3" />


## strcmp()
**strcmp(const char \*str1, const char \*str2)** е функция, сравняваща два string-a лексикографски. Ако **str1** e по-малък, то **strcmp** връща отрицателно число, ако **str2** е по-малък, върнатото
число е положително, а ако двата string-a са равни, то резултатът е 0. Лексикографското сравнение работи по следния начин: обхождаме двата стринга едновременно, като на всяка итерация на цикъла, сравняваме str1[index] c str2[index]. Припомняме, че променливите **char** са числа, които се интерпретират посредством **ASCII** таблица като символи и ние ще ги сравняваме именно като числа.
* Ако str1[index] < str2[index], то връщаме str1[index] - str2[index]. Щом върнатото число е отрицателно, това значи, че str1 < str2.
* Aко str1[index] > str2[index], то връщаме str1[index] - str2[index]. Щом върнатото число е положително, това значи, че str1 > str2.
* Ако str1[index] == str2[index], но някой от двата string-a е по-дълъг, то по-голям е този, който е по-дълъг.
* Ако str1[index] == str2[index] и двата string-а са с равна дължина, то връщаме 0.

**Примерна имплементация**
<p>
  
```c
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int strcmp(const char *str1, const char *str2) {
    int index = 0;
    int delta = 0;
    while(str1[index] != '\0' && str2[index] != '\0') {
        delta = str1[index] - str2[index];
        
        if (delta < 0)
            return delta;
        if (delta > 0)
            return delta;
        
        ++index;
    }
    
    if ('\0' == str1[index])
        return -str2[index];
    
    return str1[index];
}
```
</p>

<img width="1532" height="890" alt="image" src="https://github.com/user-attachments/assets/8c9b2fe0-17d7-41af-9ac0-c022dd5c0e42" />

