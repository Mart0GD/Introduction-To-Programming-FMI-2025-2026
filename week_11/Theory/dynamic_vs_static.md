# Dynamic vs static масиви

## Пример: Разлика между двумерен масив на стека и двумерен масив в динамичната памет
<p>

```c
#include <stdlib.h>
#define ROWS 3
#define COLS 2

int main() {
  int stackMatrix[ROWS][COLS] = {{1,2},
                           {3,4},
                           {5,6}};
  
  int** dynamicMatrix = malloc(ROWS * sizeof(int*));
  if (dynamicMatrix == NULL)
      return -1;
  for (int i = 0; i < ROWS; ++i) {
      dynamicMatrix[i] = malloc(COLS * sizeof(int));
      if (dynamicMatrix[i] == NULL) {
          // Free previously allocated rows
          for (int j = 0; j < i; ++j) {
              free(dynamicMatrix[j]);
          }
          free(dynamicMatrix);
          return -1;
      }
  }

  for (int i = 0; i < ROWS; ++i) {
      free(dynamicMatrix[i]);
  }
  free(dynamicMatrix);
  
  return 0;
}
```
</p>

<img width="498" height="510" alt="image" src="https://github.com/user-attachments/assets/470cbb37-fb6b-4200-b169-17cabf5f62be" />

Това, което трябва да отбележим и е хубаво да разбираме отсега е, че статично заделената матрица е линейна в паметта, т.е. това са 6 променливи от тип ***int** намиращи се в съседни клетки в паметта.
По горепоказаната картина можем да забележим, че това не е вярно за динамично заделената матрица.

<img width="1856" height="922" alt="image" src="https://github.com/user-attachments/assets/2f881b9a-7263-41df-90f2-ea59a5b985ea" />

