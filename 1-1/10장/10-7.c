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
    struct content* p = &c1;    // content ����ü ������ ����Ű�� ������ 

    p->price *= 0.8;                // p�� ����Ű�� ����ü�� price ���� (20% ����)
    p->rate = 8.9;                  // p�� ����Ű�� ����ü�� rate ����
    strcat(p->title, ": Endgame");  // p�� ����Ű�� ����ü�� title�� ���ڿ� ����

    printf("%s, %d, %.1f\n", p->title, p->price, p->rate);
}
*/