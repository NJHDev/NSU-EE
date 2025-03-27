/*
  for (초기식; 조건식; 증감식)
  {
     for (초기식; 조건식; 증감식) 
     {
        문장; 
     }
  }
*/

#include <stdio.h>
int main(void)
{
	int x, y;

	for(y = 1; y <= 5; y++)			 	
	{
		for(x = 0; x < y; x++)
			printf("*");
		printf("");			// 내부 반복문이 종료될 때마다 실행
	}
	return 0;
}




 

