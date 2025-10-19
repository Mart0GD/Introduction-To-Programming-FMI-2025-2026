#include <stdio.h>

int main()
{   
    const float PI = 3.14f;
    const float denumerator = 180.f;
    float degrees;
    printf("Enter an angle in degrees: ");
    scanf("%f ", &degrees);
    
    float radians = PI / denumerator * degrees;
    printf("%f degrees = %f in radians", degrees, radians); 
    
    return 0;
}
