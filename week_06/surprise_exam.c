/*# Изненадващо контролно №1:

Условие: За произволно число n, където n <= 63, изведете всички прости числа в интервала [2,n].
Всяко просто число i, което намерите в хода на програмата запишете в променлива с размер 64 бита, която ще се казва bitSet, на съответния индекс.
На края извлечете всички прости числа, които сте намерили от съответната променлива и ги отпечатайте.

Дефиниция: Просто число е число, което се дели единствено на 1 и на себе си. Пример за просто число са 2,3 и 7.

Съвет: Спазвайте добрите практики за именуване на променливи. Използвайте snake_case или camelCase.

Решение:
*/
#include <stdio.h>

int main()
{
    unsigned n;
    long long bitSet = 0xFFFFFFFFFFFFFFC;
    
    printf("Enter a value for n\n");
    scanf("%u", &n);
    
    if (n > 63) {
        printf("Invalid input! End of program\n");
        return -1;
    }
    
    unsigned isComposite;
    for (int iter = 2; iter <= n; ++iter) {
        isComposite = 0;
        for (int delim = 2; delim < iter; ++delim) {
            if (iter % delim == 0) {
                isComposite = 1;
                break;
            }
        }
        
        if (isComposite)
        bitSet &= ~(1u << iter);
    }
    
    for (int iter = 0; iter <= n; ++iter) {
        if (bitSet >> iter & 1u)
        printf("%d ", iter);
    }
    
    return 0;
}
