#include <stdio.h>

typedef struct point {      // point ����ü�� �����ϸ鼭 �Բ� typedef�� �����Ѵ�.
    int x, y;
} point_t;
void print_point(const point_t* ptr);   // point_t�� �Ű������� ������������ ����Ѵ�.

void main()
{
    point_t pt1 = { 10, 20 };           // struct point ��� point_t���� ����� �� �ִ�.
    print_point(&pt1);
}

void print_point(const point_t* ptr)
{
    printf("(%d, %d) ", ptr->x, ptr->y);
}