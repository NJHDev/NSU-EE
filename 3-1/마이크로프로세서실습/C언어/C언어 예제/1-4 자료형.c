/*
자료형(data type): 변수가 저장할 데이터가 정수인지 실수인지, 아니면 또 다른 어떤 데이터인지를 지정하는 것

정수형 : short, int, long, unsigned short, unsigned int, unsigned long
실수형 : float, double, long double
문자형 : char, unsigned char

여기서 signed char은 char, signed int는 int와 같다.
*/

#include <stdio.h>

void main(void)
{
    int x;	// 첫번째 정수를 저장하는 변수 
    int y;	// 두번째 정수를 저장하는 변수 
    int sum;    // 두 정수의 합을 저장하는 변수

    x = 10;  // 상수
    y = 20;    
    sum = x + y;

    printf("sum = %d", sum);

    /*
    float x;	// 첫번째 정수를 저장하는 변수 
    float y;	// 두번째 정수를 저장하는 변수 
    float sum;    // 두 정수의 합을 저장하는 변수

    x = 10.0;
    y = 20.0;    
    sum = x + y;

    printf("sum = %f", sum);
    //printf("sum = %3.1f", sum);
    */
}