/*
#include <stdio.h>
// 1. 처리 결과를 저장할 변수를 가리키는 포인터형으로 출력 매개변수를 선언한다.
void get_sum_product(int x, int y, int *psum, int *pproduct);   // x, y는 입력 매개변수   

void main()
{
    int sum, product;

    // 2. 처리 결과를 받아 올 변수의 주소를 전달한다
    get_sum_product(123, 456, &sum, &product);
    printf("sum = %d, product = %d\n", sum, product);
}

void get_sum_product(int x, int y, int *psum, int *pproduct)
{
    // 3. 포인터형의 매개변수가 가리키는 곳에 처리 결과를 저장한다.
    *psum = x + y;
    *pproduct = x * y;
}
*/