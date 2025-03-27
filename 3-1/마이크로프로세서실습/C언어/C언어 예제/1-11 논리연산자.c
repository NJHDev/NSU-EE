/*
 여러 개의 조건을 조합하여 참과 거짓을 따지는 연산자
 결과값은 참(1) 아니면 거짓(0)

 연산자 기호   사용예         의미
    &&        x && y    AND 연산, x와 y가 모두 참이면 참, 그렇지 않으면 거짓
    ||        x || y    OR 연산, x나 y중에서 하나만 참이면 참, 모두 거짓이면 거짓
    !         !x        NOT 연산, x가 참이면 거짓, x가 거짓이면 참
*/

#include <stdio.h> 

void main(void) 
{ 
    int x, y;
 
    printf("두개의 정수를 입력하시오: \n");
    scanf("%d%d", &x, &y);
 
    printf("%d && %d의 결과값: %d\n", x, y, x && y);
    printf("%d || %d의 결과값: %d\n", x, y, x || y);
    printf("!%d의 결과값: %d\n", x, !x);
}
