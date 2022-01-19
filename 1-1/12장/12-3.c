/*
#include <stdio.h>

#define INT_COORD       // INT_COORD 매크로가 정의되면 정수 좌표를 사용한다는 뜻

#ifdef INT_COORD        // 정수 좌표를 사용한다는 의미의 INT_COORD가 정의된 경우
typedef int coord_t;
#else                   // 그러지 않은 경우(실수 좌표 사용)
typedef double coord_t;
#endif

typedef struct point {
    coord_t x, y;       // 좌표형으로 coord_t를 사용한다.
} point_t;

void print_point(const point_t* ptr)
{
#ifdef INT_COORD        // 좌표형에 따라 다르게 처리할 코드는 조건부 컴파일을 사용한다.
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