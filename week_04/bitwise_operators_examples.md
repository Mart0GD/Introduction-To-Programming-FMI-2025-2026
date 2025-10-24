# Побитови операции. Примери за употреба
## Bit-shifts (<<, >>)

```c
#include <stdio.h>

int main()
{
    unsigned short x = 1; // 0000000000000001
    
    // Example of bit-shifts and going over the powers of 2 and 
    for (int i = 0; i <=8; ++i)
    {
        printf("2^%d = %hu\n", i, x);
        x <<= 1;
    }

    return 0;
}
```
### Output:

1. 2^0 = 1
2. 2^1 = 2
3. 2^2 = 4
4. 2^3 = 8
5. 2^4 = 16
6. 2^5 = 32
7. 2^6 = 64
8. 2^7 = 128
9. 2^8 = 256



## Bitwise mask
Побитовите маски се използват за извличане, задаване (вдигане) и нулиране (смъкване) на конкретни битове в число.

```c
#include <stdio.h>

int main()
{
    unsigned short x = 0; // 0000000000000000
    printf("Original value of x = %u\n", x);
    
    unsigned short bitSet = 1; // 0000000000000001
    
    unsigned short bitUnset = 0; // 0000000000000000

    // Повдигане нa bit
    x |= bitSet; // 1 | 0 = 1
    printf("Value after bit-set of x = %u\n", x);
    
    // Смъкване на bit
    x &= bitUnset; // 1 & 0 = 0
    printf("Value after bit-unset of x = %u\n", x);

    // Извличане на bit
    unsigned short bitToggle = 1; // 0000000000000001
    bitToggle <<= 3; // 0000000000001000

    //  Искаме да проверим дали bit на index 3 e вдигнат
    x = 26; // 0000000000011010
    short isRaised = (bitToggle & x) != 0;
    printf("The bit at index 3 is: %hu\n", isRaised);
    return 0;
}
```
