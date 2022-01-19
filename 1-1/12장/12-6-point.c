// point.c : point ����ü�� ���õ� �Լ��� ���Ǵ� �ҽ� ���Ͽ� �־��ش�.
#include <stdio.h>      // ���̺귯���� ����ϴ� �ҽ� ���ϸ��� �����Ѵ�.
#include "12-6-point.h"      // �ڱ� �ڽ��� ����� �����Ѵ�.

void print_point(const point_t* ptr)
{
    printf("(%d, %d)", ptr->x, ptr->y);
}

void move_point(point_t* ptr, int offset)
{
    ptr->x += offset;
    ptr->y += offset;
}