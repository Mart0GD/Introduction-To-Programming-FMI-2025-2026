#include "stdio.h"

int mian(){

  unsigned int num, n;
  printf("Insert num, n: "); scanf("%u %u", &num, &n);

  printf("num << %u = %u", n, num << n);
  printf("num >> %u = %u", n, num >> n);
  return 0;
}