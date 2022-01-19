/*
#include <stdio.h>

struct point {                       // 구조체 정의가 함수 선언보다 앞에 와야 한다.
    int x, y;
};
void print_point(struct point pt);   // 함수 선언

void main()
{
    struct point arr[] = {          // point 구조체 배열
        {10, 20}, {35, 41}, {12, 63}, {72, 55}, {92, 86}, {4, 27}
    };
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    for (i = 0; i < size; i++) {
        print_point(arr[i]);        // arr[i]를 함수의 매개변수 pt로 복사해서 전달한다.
    }
    printf("\n");
}

void print_point(struct point pt)   // pt는 값에 의한 호출로 전달된다.
{
    printf("(%d, %d) ", pt.x, pt.y);
}
*/