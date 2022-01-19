// point.h : 매크로, 구조체, typedef의 정의는 헤더 파일에 넣어준다.
#pragma once
typedef struct point {      // 함수 선언보다 앞에 point 구조체가 정의되어야 한다.
    int x, y;
} point_t;

void print_point(const point_t* ptr);       // point 구조체에 관련된 함수의 선언
void move_point(point_t* ptr, int offset);