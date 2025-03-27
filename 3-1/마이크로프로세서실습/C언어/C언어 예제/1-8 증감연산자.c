/*
 증감 연산자
  ++x  : x값을 먼저 증가한 후에 다른 연산에 사용
  x++  : x값을 먼저 사용한 후에 증가
  --x  : x값을 먼저 감소한 후에 다른 연산에 사용
  x--  : x값을 먼저 사용한 후에 감소
*/

#include <stdio.h>

void main(void)
{
	int x=10, y=10;

	printf("x=%d\n", x);
	printf("++x의 값=%d\n", ++x);

	printf("x=%d\n\n", x);

	printf("y=%d\n", y);
	printf("y++의 값=%d\n", y++);
	printf("y=%d\n", y);  
}