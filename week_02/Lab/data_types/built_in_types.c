// Introduction to built-in types in C

int main()
{
    // Primitive types in C, sizes depend on the architecture (usually 32 or 64 bits)
    // integer types
    short x = 5;                            // >= 2 bytes, usually 2 [-32,768 ; 32,767]
    int y = 10;                             // >= 2 bytes, usually 4 [-2,147,483,648 ; 2,147,483,647]     
    long z = 100000;                        // >= 4 bytes, 4 on LP64 8 on LLP64 [-2^63, 2^63]
    long long k = 100000000000;             // >= 8 bytes, usually 8 [-2^63, 2^63]

    // unsigned integer types
    unsigned short ux = 5;                  // >= 2 bytes, usually 2 [0 ; 65,535]
    unsigned int uy = 10;                   // >= 2 bytes, usually 4 [0 ; 4,294,967,295]
    unsigned long uz = 100000;              // >= 4 bytes, usually 8 [0 ; 2^64]
    unsigned long long uk = 100000000000;   // >= 8 bytes, usually 8 [0 ; 2^64]

    // floating point types
    float f = 5.5f;                         // usually 4 bytes, 6 decimal places
    double d = 10.99;                       // usually 8 bytes, 15 decimal places
    long double ld = -100.9999;             // usually 16 bytes, 18 decimal places

    // character type
    char c = 'A';                           // 1 byte, [-128 ; 127] 
    unsigned char uc = 'A';                 // 1 byte  [0 ; 255] 

    //no boolean type up until C99 and later
    int false = 0;                          // false
    int true  = 1;                          // everything apart 0 

    return 0;
}