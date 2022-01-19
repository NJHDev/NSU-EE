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
    struct content c2 = c1;     // 같은 멤버끼리 1:1로 복사해서 초기화한다.
    struct content c3 = { 0 };  // 0으로 초기화

    c3 = c1;                    // 같은 멤버끼리 1:1로 복사해서 대입한다.

    printf("c1 = %s, %d, %.1f\n", c1.title, c1.price, c1.rate);
    printf("c2 = %s, %d, %.1f\n", c2.title, c2.price, c2.rate);
    printf("c3 = %s, %d, %.1f\n", c3.title, c3.price, c3.rate);
}
*/