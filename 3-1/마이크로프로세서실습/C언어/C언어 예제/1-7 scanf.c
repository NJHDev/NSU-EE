/*
scanf(): 키보드로부터 입력을 하기 위한 라이브러리 함수

*/

#include <stdio.h>

void main(void)
{
    int    number;
    float  height;

    scanf("%d", &number);    
    scanf("%f", &height);

    printf("숫자 = %d \n", number);
    printf("높이 = %f \n", height);
}

