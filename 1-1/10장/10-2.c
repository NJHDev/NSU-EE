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
    struct content c1 = { "Avengers", 11000, 8.8 }; // ����ü ������ ���� �� �ʱ�ȭ
    struct content c2, c3;          // �ʱ�ȭ���� ���� ����ü ���� ����(�����Ⱚ)

    strcpy(c2.title, "Aquaman");    // ����ü ���� c2�� ����� �����Ѵ�.
    c2.price = 5500;
    c2.rate = 7.1;

    strcpy(c3.title, "Shazam!");    // ����ü ���� c3�� ����� �����Ѵ�.
    c3.price = 7700;
    c3.rate = 7.4;

    printf("c1 = %s, %d, %.1f\n", c1.title, c1.price, c1.rate); // c1�� ������� ����Ѵ�.
    printf("c2 = %s, %d, %.1f\n", c2.title, c2.price, c2.rate); // c2�� ������� ����Ѵ�.
    printf("c3 = %s, %d, %.1f\n", c3.title, c3.price, c3.rate); // c3�� ������� ����Ѵ�.
}
*/