/*
#include <stdio.h>
#define DEBUG_LEVEL 3               // 디버깅 정보로 호출된 함수명만 출력하도록 설정

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
#if DEBUG_LEVEL == 1                    // 호출된 함수명만 출력
    printf("print_point is called\n");      
#elif DEBUG_LEVEL == 2                  // 호출된 함수명과 ptr 출력
    printf("print_point: ptr = %p\n", ptr);
#elif DEBUG_LEVEL == 3                  // 호출된 함수명과 ptr, ptr의 멤버 출력
    printf("print_point: ptr = %p, ptr->x = %d, ptr->y = %d\n", ptr, ptr->x, ptr->y);
#endif
    printf("(%d, %d)\n", ptr->x, ptr->y);   // 이부분만 실제 함수 코드이다.
}
*/