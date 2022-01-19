/*
#include <stdio.h>
#include <string.h>

typedef struct tag_point { // tag_point는 태그명
    int x, y;
} point; // 구조체형 이름이 point가 된다.

//struct point {      
//    int x, y;
//};
//typedef struct point point_t;       // point 구조체에 대하여 typedef를 정의한다.
//typedef struct point {      // point 구조체를 정의하면서 함께 typedef를 정의한다.
//    int x, y;
//} POINT;
void print_point(const struct point* ptr);      // ptr은 입력 매개변수
void move_point(struct point* ptr, int offset); // ptr은 입출력 매개변수

void main()
{ 
    point_t pt1 = { 10, 20 };       // struct point 대신 point_t형을 사용할 수 있다.
    struct point* ptr = &pt1;       // struct point도 계속 사용할 수 있다.
    struct point arr[] = {
        {10, 20}, {35, 41}, {12, 63}, {72, 55}, {92, 86}, {4, 27}
    };
    int size = sizeof(arr) / sizeof(arr[0]);
    int i, offset;

    for (i = 0; i < size; i++) {
        print_point(&arr[i]);           // arr[i]의 주소를 매개변수 ptr로 전달한다.
    }                                   // 구조체를 복사하지 않고 전달하므로 효율적이다.
    printf("\n");

    printf("이동할 오프셋? ");
    scanf("%d", &offset);
    for (i = 0; i < size; i++) {
        move_point(&arr[i], offset);    // arr[i]를 offset만큼 이동한다.
        print_point(&arr[i]);           // 이동된 arr[i]를 출력한다.
    }
}

void print_point(const struct point* ptr)   // ptr은 입력 매개변수
{
    printf("(%d, %d) ", ptr->x, ptr->y);    // ptr이 포인터이므로 ->로 멤버에 접근한다.
}

void move_point(struct point* ptr, int offset)  // ptr은 입출력 매개변수
{
    ptr->x = ptr->x + offset;               // ptr이 가리키는 구조체의 x 멤버를 변경한다.
    ptr->y = ptr->y + offset;               // ptr이 가리키는 구조체의 y 멤버를 변경한다.
}
*/