// 구구단
#include <stdio.h>

void main(void)
{
    int i;
    int j;

    for(j=1; j<=9; j++) {   
      printf("## %d Dan\r", j);
      for(i=1; i<=9; i++) {
        printf("%d * %d = %d\r", j, i, j*i);
      }
      printf("\r");
   }
}