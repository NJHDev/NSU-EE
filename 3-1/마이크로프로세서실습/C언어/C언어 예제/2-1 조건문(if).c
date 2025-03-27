/*
 1. if 문
   if(조건식)
      문장;

 2. if ~ else 문
   if(조건식)
      문장 1;
   else
      문장 2;

 3. if ~ else if ~ else 문
   if(조건식)
      문장1;
   else if(조건식)
      문장 2;
   else
      문장 3;
 4. 중첩 if
   if(조건식)
      if(조건식)
          문장 1;
       else
          문장 2;
   else
      if(조건식)
          문장 3;
      else
          문장 4;
*/

#include <stdio.h> 

void main(void) 
{ 
    int number;

    printf("정수를 입력하시오:"); 
    scanf("%d", &number); 
    if( number < 0 ) 
        number = -number; 
         
    printf("절대값은 %d 입니다.\n", number);
}

/*
#include <stdio.h> 

void main(void) 
{ 
    int number; 
    printf("정수를 입력하시오:"); 
    scanf("%d", &number); 
    if( number % 2 == 0 ) 
        printf("입력된 정수는 짝수입니다.\n"); 
    else 
        printf("입력된 정수는 홀수입니다.\n");
}
*/

/*
// 학점 결정
#include <stdio.h> 

void main(void) 
{
    int score; 
         
    printf("성적을 입력하시오: "); 
    scanf("%d", &score); 
    if (score >= 90) 
        printf("합격: 학점A\n"); 
    else if (score >= 80) 
        printf("합격: 학점B\n"); 
    else if (score >= 70) 
        printf("합격: 학점C\n"); 
    else if (score >= 60) 
        printf("합격: 학점D\n"); 
    else 
        printf("불합격: 학점F\n");
}
*/

/*
// 최소값 찾기
#include <stdio.h>

void main(void)
{
    int n1, n2, n3, min;
	
    printf("정수 3개를 입력하시오:");
    scanf("%d %d %d", &n1, &n2, &n3);
	
    if( n1 < n2 )
	if( n1 < n3 )
		min = n1;
	else
		min = n3;
    else
	if( n2 < n3 )
		min = n2;
	else
		min = n3;
    printf("제일 작은 수는 %d입니다\n", min);
}
*/

/*
// 산술계산기
#include <stdio.h>

void main(void)
{
    char op;
    int x, y, result;
    printf("수식을 입력하시오\n");
    printf("(예: 2 + 5) ");
    printf(">>");
    scanf("%d %c %d", &x, &op, &y);
    if( op == '+' )
	result = x + y;
    else if( op == '-' )
	result = x - y;
    else if( op == '*' )
	result = x * y;
    else if( op == '/' )
	result = x / y;
    else if( op == '%' )
	result = x % y;
    else 
	printf("지원되지 않는 연산자입니다. ");
    printf("%d %c %d = %d ", x, op, y, result);
}
*/