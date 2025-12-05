## Двумерни масиви
В рамките на миналите две упражнения се запознахме с масиви. Както казахме, те са начин да комплектоваме логически блок от еднотипни променливи в един обект.
Но ако искаме да моделираме по-сложни структури, например таблици от еднотипни променливи, матрици или просто искаме да представим по удобен начин множество 
от геометрични точки в двумерно евклидово пространство. На наша помощ се притичват именно многомерните масиви. В това упражнение ще се запознаем с двумерните масиви.

<img width="730" height="152" alt="image" src="https://github.com/user-attachments/assets/8e748b96-ac18-4cb1-8b9a-c9611d723a9c" />

## Синтаксис

**а) Декларация:**

<p>

```c
#include <stdio.h>
int main() {
  // <type> <name>[<rows_count>][<columns_count>];
  int matrix[2][3];

  return 0;
}
```
</p>

**б) Инициализация:**

<p>

```c
#include <stdio.h>
int main() {
  // <type> <name>[<rows_count>][<columns_count>] = {{el_00,..,el_0rows_cnt}, {el_10,..,el_1rows_cnt},..};
  int matrix[2][3] = {{1,2,5}, {5,6,3}};

  return 0;
}
```
</p>

## Записване на стойности и извеждане на стойности от двумерен масив

Всеки елемент в един двумерен масив се идентифицира с два индекса. Единият обозначава реда, в който се намира въпросен елемент, а вторият- колоната, в която се намира. Аналогично, точка в двумерна координатна система се определя еднозначно от позицията си по абсцисата Х и ординатата У. Едномерните масиви обхождахме с цикъл, тук ще приложим абсолютно същата логика. Ще ползваме един масив, чрез който ще обхождаме редовете и вложен такъв, чрез който ще обхождаме всички елементи в даден ред. На всеки ред ще има брой елементи, равен на броя на колоните.

**a) Писане в двумерен масив:**

<p>

```c
#include <stdio.h>
int main() {
  const unsigned rows = 3;
  const unsigned columns = 4;
  float points_2d[rows][columns];

  for (unsigned i = 0; i < rows; ++i) {
    for (unsigned j = 0; j < columns; ++j) {
      scanf("%f", &2d_points[i][j]);
    }
  }

  return 0;
}
```
</p>

**б) Четене на от двумерен масив:**

<p>

```c
#include <stdio.h>
int main() {
  const unsigned rows = 2;
  const unsigned columns = 3;
  unsigned matrix[rows][columns] = {{1,2,3,}, {4,5,6}};

  for (unsigned i = 0; i < rows; ++i) {
    for (unsigned j = 0; j < columns; ++j) {
      printf("%u ", matrix[i][j]);
    }
    printf("\n"); // print the next row on a new line
  }

  return 0;
}
```
</p>

**в) Допълнение:**

Досега обхождахме нашия двумерен масив по редове. Съвсем спокойно можем да го обходим по колони, външният и вложеният масив.

<p>

```c
#include <stdio.h>
int main() {
  const unsigned rows = 2;
  const unsigned columns = 3;
  unsigned matrix[rows][columns] = {{1,2,3,}, {4,5,6}};

  for (unsigned j = 0; j < columns; ++j) {
    for (unsigned i = 0; i < rows; ++i) {
      printf("%u ", matrix[i][j]);
    }
    printf("\n"); // print the next column on a new line
  }

  return 0;
}
```
</p>

## Как подаваме двумерен масив като аргумент на функция

<p>

```c
#include <stdio.h>

// using VLA (variable length arrays)
void printMatrix(unsigned rows, unsigned columns, int matrix[rows][columns]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j){
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int matrix[2][3] = {{1,2,3}, {4,5,6}}; // int matrix[2][3] decays to a pointer to an array of 3 integers
                                            // int matrix[2][3] <=> int (*)[3]
    printMatrix(2, 3, matrix);
    

    return 0;
}

```
</p>

int (*)[3] e указател към масив от 3 променливи от тип int.
