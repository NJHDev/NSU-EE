/*
 복합대입 연산자      의미
  x += y            x = x + y 
  x -= y            x = x - y
  x *= y            x = x * y
  x /= y            x = x / y
  x %= y            x = x % y
  x &= y            x = x & y
  x |= y            x = x | y
  x ^= y            x = x ^ y
  x >>= y           x = x >> y
  x <<= y           x = x << y  
*/
#include <stdio.h> 

void main(void) 
{ 
    int x = 10;
    int y = 10;
    int z = 33;

    x += 1;       // x = x + 1;
    y *= 2;       // y = y * 2;
    z %= x + y;   // z = z % (x + y );  // 주의

    printf("x = %d    y = %d    z = %d \n", x, y, z);

    printf("수식 x++ 의 값: %d \n", x++); 
    printf("현재 x의 값: %d \n", x); 
    printf("수식 ++x 의 값: %d \n", ++x); 
    printf("현재 x의 값: %d \n", x); 

    printf("수식 x-- 의 값: %d \n", x--); 
    printf("현재 x의 값: %d \n", x); 
    printf("수식 --x 의 값: %d \n", --x); 
    printf("현재 x의 값: %d \n", x);
}
