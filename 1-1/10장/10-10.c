/*
#include <stdio.h>
#include <math.h>       // 제곱근을 구하는 sqrt 함수를 호출하려면 필요하다.

struct point {          // point 구조체가 line 구조체보다 앞에 정의되어야 한다.
    int x, y;
};
struct line {           // point 구조체를 이용해서 line 구조체을 정의한다.
    struct point start, end;    
};
void print_point(const struct point* ptr);
double get_length(const struct line* ptr);

void main()
{
    struct line ln1 = { 
        {10, 20}, {30, 40}      // start는 {10, 20}으로 end는 {30, 40}으로 초기화
    };   
    printf("직선 정보: ");
    print_point(&ln1.start);    // ln1.start를 point 구조체 변수로 사용할 수 있다.                    
    print_point(&ln1.end);      // ln1.end를 point 구조체 변수로 사용할 수 있다.  
    printf("\n길이: %f\n", get_length(&ln1));     // line 구조체의 주소를 전달한다.
}

void print_point(const struct point* ptr)
{
    printf("(%d, %d) ", ptr->x, ptr->y);
}

double get_length(const struct line* ptr)   // ptr은 입력 매개변수
{
    int dx = ptr->end.x - ptr->start.x;     // 여러 번 연속해서 멤버에 접근할 수 있다.
    int dy = ptr->end.y - ptr->start.y;
    return sqrt(dx * dx + dy * dy);     // sqrt는 제곱근을 구하는 표준 C 라이브러리 함수
}
*/