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
    struct content c2 = c1;     // ���� ������� 1:1�� �����ؼ� �ʱ�ȭ�Ѵ�.
    struct content c3 = { 0 };  // 0���� �ʱ�ȭ

    c3 = c1;                    // ���� ������� 1:1�� �����ؼ� �����Ѵ�.

    printf("c1 = %s, %d, %.1f\n", c1.title, c1.price, c1.rate);
    printf("c2 = %s, %d, %.1f\n", c2.title, c2.price, c2.rate);
    printf("c3 = %s, %d, %.1f\n", c3.title, c3.price, c3.rate);
}
*/