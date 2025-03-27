/*
변수란 프로그램이 사용하는 데이터를 일시적으로 저장할 목적으로 사용하는 메모리 공간

int x;	    // 첫번째 정수를 저장하는 변수 
int y;	    // 두번째 정수를 저장하는 변수 
int sum;    // 두 정수의 합을 저장하는 변수
자료형 변수이름; 
*/

#include <stdio.h>

void main(void)
{
    int x;	// 첫번째 정수를 저장하는 변수 
    int y;	// 두번째 정수를 저장하는 변수 
    int sum;    // 두 정수의 합을 저장하는 변수

    x = 10;
    y = 20;    
    sum = x + y;

    printf("sum = %d", sum);
}