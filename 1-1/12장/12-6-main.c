// main.c
#include "12-6-point.h"      // point ����ü�� ���õ� �Լ��� ����Ϸ��� ��� ������ �����Ѵ�.

int  main(void)
{
    point_t pt1 = { 10, 20 };
    move_point(&pt1, 5);
    print_point(&pt1);
}
