#include <stdio.h>

typedef struct point {      // point 구조체를 정의하면서 함께 typedef를 정의한다.
    int x, y;
} point_t;
void print_point(const point_t* ptr);   // point_t를 매개변수의 데이터형으로 사용한다.

void main()
{
    point_t pt1 = { 10, 20 };           // struct point 대신 point_t형을 사용할 수 있다.
    print_point(&pt1);
}

void print_point(const point_t* ptr)
{
    printf("(%d, %d) ", ptr->x, ptr->y);
}