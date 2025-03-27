/*
연산   연산자   C 수식   수학에서의 기호
덧셈     +      x + y       x + y
뺄셈     -      x - y       x - y
곱셈     *      x * y        xy
나눗셈   /      x / y       x / y
나머지   %      x % y       x mod y  modulo 연산
*/

#include <stdio.h>

void main(void)
{
    int x;	// 첫번째 정수를 저장하는 변수 
    int y;	// 두번째 정수를 저장하는 변수 
    int sum;    // 두 정수의 합을 저장하는 변수

    x = 20;  // 상수
    y = 10;    
    
    sum = x + y;
    printf("두수의 합 = %d\n", sum);
    
    sum = x - y;
    printf("두수의 차 = %d\n", sum);
    
    sum = x * y;
    printf("두수의 곱 = %d\n", sum);
    
    sum = x / y;
    printf("두수의 몫 = %d\n", sum);
    
    sum = x % y;
    printf("나머지 = %d\n", sum);
}

