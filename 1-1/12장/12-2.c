/*
#include <stdio.h>
#define DEBUG_LEVEL 3               // ����� ������ ȣ��� �Լ��� ����ϵ��� ����

struct point
{
    int x, y;
};
void print_point(const struct point* ptr);

void main()
{
    struct point arr[3] = { {10, 20}, {30, 40}, {50, 60} };
    int i;
    for (i = 0; i < 3; i++)
        print_point(&arr[i]);
}

void print_point(const struct point* ptr)
{
#if DEBUG_LEVEL == 1                    // ȣ��� �Լ��� ���
    printf("print_point is called\n");      
#elif DEBUG_LEVEL == 2                  // ȣ��� �Լ���� ptr ���
    printf("print_point: ptr = %p\n", ptr);
#elif DEBUG_LEVEL == 3                  // ȣ��� �Լ���� ptr, ptr�� ��� ���
    printf("print_point: ptr = %p, ptr->x = %d, ptr->y = %d\n", ptr, ptr->x, ptr->y);
#endif
    printf("(%d, %d)\n", ptr->x, ptr->y);   // �̺κи� ���� �Լ� �ڵ��̴�.
}
*/