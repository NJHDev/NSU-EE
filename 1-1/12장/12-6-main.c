// main.c
#include "12-6-point.h"      // point 구조체와 관련된 함수를 사용하려면 헤더 파일을 포함한다.

int  main(void)
{
    point_t pt1 = { 10, 20 };
    move_point(&pt1, 5);
    print_point(&pt1);
}
