/*
#include <stdio.h>

#define INT_COORD       // INT_COORD ��ũ�ΰ� ���ǵǸ� ���� ��ǥ�� ����Ѵٴ� ��

#ifdef INT_COORD        // ���� ��ǥ�� ����Ѵٴ� �ǹ��� INT_COORD�� ���ǵ� ���
typedef int coord_t;
#else                   // �׷��� ���� ���(�Ǽ� ��ǥ ���)
typedef double coord_t;
#endif

typedef struct point {
    coord_t x, y;       // ��ǥ������ coord_t�� ����Ѵ�.
} point_t;

void print_point(const point_t* ptr)
{
#ifdef INT_COORD        // ��ǥ���� ���� �ٸ��� ó���� �ڵ�� ���Ǻ� �������� ����Ѵ�.
    const char* format = "(%d, %d)";
#else
    const char* format = "(%.2f, %.2f)";
#endif
    printf(format, ptr->x, ptr->y);
}

void main()
{
    point_t pt1 = { (coord_t)12.34, (coord_t)56.78 };
    print_point(&pt1);
}
*/