#include <stdio.h>

int main()
{
    const float COEFF = 1.9558f;
    float bgn, euro;
    
    printf("Enter amount of bgn:\n");
    scanf("%f", &bgn);
    euro = bgn / COEFF;

    printf("%.4f bgn = %.4f euro", bgn, euro);
    
    return 0;
}
