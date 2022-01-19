#include <stdio.h>
#define SIZE 10

void copy_array(const int *source, int *target, int size);
void print_array(const int *arr, int size); 

void main()
{
    int x[SIZE] = { 10, 20, 30, 40, 50 };
    int y[SIZE] = { 0 };

    printf("x = ");
    print_array(x, SIZE);   // 배열의 시작 주소 x를 arr로 전달한다.(참조에 의한 호출)

    copy_array(x, y, SIZE);
    printf("y = ");
    print_array(y, SIZE);
}

// source와 size는 입력 매개변수,  target은 출력 매개변수
void copy_array(const int *source, int *target, int size)
{
    int i;
    for (i = 0; i < size; i++)
        target[i] = source[i];  // source, target은 포인터지만 배열처럼 사용한다.
}

void print_array(const int *arr, int size)  // arr는 입력 매개변수
{
    int  i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);  // arr은 포인터지만 배열처럼 사용한다.
    printf("\n");
}