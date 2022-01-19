// point.c : point 구조체에 관련된 함수의 정의는 소스 파일에 넣어준다.
#include <stdio.h>      // 라이브러리를 사용하는 소스 파일마다 포함한다.
#include "12-6-point.h"      // 자기 자신의 헤더를 포함한다.

void print_point(const point_t* ptr)
{
    printf("(%d, %d)", ptr->x, ptr->y);
}

void move_point(point_t* ptr, int offset)
{
    ptr->x += offset;
    ptr->y += offset;
}