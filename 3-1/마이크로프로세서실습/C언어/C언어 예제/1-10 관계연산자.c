/*
 두개의 피연산자를 비교하는 연산자
 결과값은 참(1) 아니면 거짓(0)

 연산자 기호       의미                      사용예
    ==        x와 y가 같은가?               x == y
    !=        x와 y가 다른가?               x != y
    >         x가 y보다 큰가?               x > y
    <         x가 y보다 작은가?             x < y
    >=        x가 y보다 크거나 같은가?      x >= y
    <=        x가 y보다 작거나 같은가?      x <= y

*/

#include <stdio.h> 

void main(void) 
{ 
    int x, y;

    printf("두개의 정수를 입력하시오: \n");
    scanf("%d%d", &x, &y);
 
    printf("x == y의 결과값: %d\n", x == y);
    printf("x != y의 결과값: %d\n", x != y);
    printf("x > y의 결과값: %d\n", x > y);
    printf("x < y의 결과값: %d\n", x < y);
    printf("x >= y의 결과값: %d\n", x >= y);
    printf("x <= y의 결과값: %d\n", x <= y);
}
