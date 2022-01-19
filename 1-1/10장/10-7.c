/*
#include <stdio.h>
#include <string.h>

struct content {
    char title[40];
    int price;
    double rate;
};

void main()
{
    struct content c1 = { "Avengers", 11000, 8.8 };
    struct content* p = &c1;    // content 구조체 변수를 가리키는 포인터 

    p->price *= 0.8;                // p가 가리키는 구조체의 price 변경 (20% 할인)
    p->rate = 8.9;                  // p가 가리키는 구조체의 rate 변경
    strcat(p->title, ": Endgame");  // p가 가리키는 구조체의 title에 문자열 연결

    printf("%s, %d, %.1f\n", p->title, p->price, p->rate);
}
*/