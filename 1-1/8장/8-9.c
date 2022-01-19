/*
#include <stdio.h>
void swap(int* px, int* py);    // 매개변수는 인자에 대한 포인터형으로 선언한다.

void main()
{
    int a = 1, b = 2;
    printf("a = %d, b = %d\n", a, b);

    swap(&a, &b);               // 인자로 전달하려는 변수의 주소를 전달한다.
    printf("a = %d, b = %d\n", a, b);
}

void swap(int* px, int* py)     // 참조에 의한 호출
{
    int temp = *px; // temp를 px가 가리키는 변수의 값으로 초기화한다.
    *px = *py;      // py가 가리키는 변수의 값을 px가 가리키는 변수에 대입한다.
    *py = temp;     // py가 가리키는 변수에 temp를 대입한다.
}
*/