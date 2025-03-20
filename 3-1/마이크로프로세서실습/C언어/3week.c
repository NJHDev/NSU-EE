/* 3-1 사칙연산자 계산
#include <stdio.h>

int main() {
    int input = 100, input2 = 5, sum = 0, sub = 0, multi = 0, divid = 0, mod = 0;

    sum = input + input2;
    sub = input - input2;
    multi = input * input2;
    divid = input / input2;
    mod = input % input2;

    printf("덧셈결과 = %d\n", sum);
    printf("뺄셈결과 = %d\n", sub);
    printf("곱셈결과 = %d\n", multi);
    printf("나눗셈결과 = %d\n", divid);
    printf("모듈로결과 = %d\n", mod);
    
    return 0;
    
}
*/
---------------------------------------------------
/* 3-2 형식지정자 계산
#include <stdio.h>

int main()
{
    int    x = 20;
    float  y = 10.5;
    char   z = 'A';
    char   str[] = "Hello";
    

    printf("정수 = %d \n", x);
    printf("실수 = %f \n", y);
    printf("문자 = %c \n", z);
    printf("문자열 = %s \n", str);

    return 0;
    
}
*/
---------------------------------------------------
/* 3-3 scanf
#include <stdio.h>

int main()
{
    int    number;
    float  height;

    scanf("%d", &number);    
    scanf("%f", &height);

    printf("숫자 = %d \n", number);
    printf("높이 = %f \n", height);

    return 0;
    
}
*/
---------------------------------------------------
/* 3-4 관계연산자
#include <stdio.h>

int main()
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

    return 0;
    
}
*/
---------------------------------------------------
/*관계연산자 if 사용
    #include <stdio.h>
    
    int main()
    {
        int x, y;
    
        printf("두개의 정수를 입력하시오: \n");
        scanf("%d%d", &x, &y);
        printf("=== 비교연산자 ===\n");
        
        printf("1. x > y\n");
            if (x > y)
            {
                 printf("x > y 비교결과 : 참\n");
            }
            else
            {
                printf("x > y 비교결과 : 거짓\n");
            }    

        printf("2. x < y\n");
            if (x < y)
            {
                 printf("x < y 비교결과 : 참\n");
            }
            else
            {
                printf("x < y 비교결과 : 거짓\n");
            }    

        printf("3. x >= y\n");
            if (x >= y)
            {
                 printf("x >= y 비교결과 : 참\n");
            }
            else
            {
                printf("x >= y 비교결과 : 거짓\n");
            }

        printf("4. x <= y\n");
            if (x <= y)
            {
                 printf("x <= y 비교결과 : 참\n");
            }
            else
            {
                printf("x <= y 비교결과 : 거짓\n");
            }

        printf("5. x == y\n");
            if (x == y)
            {
                 printf("x == y 비교결과 : 참\n");
            }
            else
            {
                printf("x == y 비교결과 : 거짓\n");
            }
        printf("5. x != y\n");
            if (x != y)
            {
                 printf("x != y 비교결과 : 참\n");
            }
            else
            {
                printf("x != y 비교결과 : 거짓\n");
            }
        
        return 0;
            
    }
*/
