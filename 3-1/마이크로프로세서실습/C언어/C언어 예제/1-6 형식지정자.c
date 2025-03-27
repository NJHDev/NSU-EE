/*
형식 지정자: printf()에서 값을 출력하는 형식을 지정한다. 

형식지정자   의미               예                      실행결과
 %d        10진 정수로 출력  printf("%d \n", 10);         10
 %f        실수로 출력       printf("%f \n", 3.14);       3.14
 %c        문자로 출력       printf("%c \n", 'a');        a
 %s        문자열로 출력     printf("%s \n", "Hello");    Hello
*/

#include <stdio.h>

void main(void)
{
    int    x = 20;
    float  y = 10.5;
    char   z = 'A';
    char   str[] = "Hello";
    

    printf("정수 = %d \n", x);
    printf("실수 = %f \n", y);
    printf("문자 = %c \n", z);
    printf("문자열 = %s \n", str);
}

