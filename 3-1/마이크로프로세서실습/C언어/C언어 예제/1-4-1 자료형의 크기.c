/*
sizeof(): 변수의 크기를 알수 있는 함수

*/

#include <stdio.h>

void main(void)
{
       int x;

       printf("변수 x의    크기: %ld", sizeof(x));
       printf("char형의    크기: %ld", sizeof(char));
       printf("int형의     크기: %ld", sizeof(int));
       printf("short형의   크기: %ld", sizeof(short));
       printf("long형의    크기: %ld", sizeof(long));
       printf("float형의   크기: %ld", sizeof(float));
       printf("double형의  크기: %ld", sizeof(double));  
}
