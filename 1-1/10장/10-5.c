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
    struct content arr[] = {        // ����ü �迭�� ���� �� �ʱ�ȭ
        {"Avengers", 11000, 8.8},     // arr[0]�� �ʱⰪ
        {"Aquaman", 5500, 7.1},       // arr[1]�� �ʱⰪ
        {"Shazam!", 7700, 7.4}        // arr[2]�� �ʱⰪ
    };
    int size = sizeof(arr) / sizeof(arr[0]);    // �迭�� ũ��
    int i;

    for (i = 0; i < size; i++)      // arr[i]�� content ����ü �����̴�.
        printf("arr[%d] = %s, %d, %.1f\n", i, arr[i].title, arr[i].price, arr[i].rate);
}
*/