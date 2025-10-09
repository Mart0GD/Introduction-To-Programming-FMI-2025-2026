# Именуване на променливи в С

## Именуване в стандарт C17
По стандарт идентификаторите в С винаги започват със символ от латинската азбука a-z(A-Z) или _(underscore) и могат да бъдат последвани от цифра. Lower-case и Upper-case символите биват третирани като различни символи, тъй като С e case-sensitive програмен език. Не можем да ползваме "резервираните" символи за операции.

---

Пример:

int main()

  {

      int var1; ✅
  
      int _var2; ✅
    
      int myVar3; ✅
  
      long double big_var; ✅
  
      float CapitalVar; ✅
  
      return 0;
  
  }

---

Контрапримери:

---

int main()

  {

      int skuskaha_me-Brat; ❌ // wrong use of '-'
  
      int 2var; ❌ // starting with a digit  
  
      return 0;
  
  }

---

## snake_case vs camelCase

---

#### snake_case:

int main()

  {

      float side_a;
      
      float side_b;
      
      float side_c;

      scanf("%f", &side_a);

      scanf("%f", &side_b);

      scanf("%f", &side_c);

      float perimeter = side_a + side_b + side_c;
      
      return 0;
  
  }

---

---

#### camelCase:

int main()
{

    float sideA;
   
    float sideB;
    
    float sideC;

    scanf("%f", &sideA);
    
    scanf("%f", &sideB);
    
    scanf("%f", &sideC);

    float perimeter = sideA + sideB + sideC;

    return 0;

}

---

## Връзки за ресурси
https://www.iso-9899.info/wiki/The_Standard
