/*
#include <stdio.h>
#include <string.h>

struct content {
    char    title[40];
    int     price;
    double  rate;
};

void main()
{
    struct content arr[] = {                    // �ʱ�ȭ�� ����ü �迭
        {"Avengers", 11000, 8.8}, {"Aquaman", 5500, 7.1}, {"Shazam!", 7700, 7.4},
        {"X-Men", 3300, 8.0},     {"Us", 8800, 7.1},      {"Inception", 2200, 8.7}
    };
    int size = sizeof(arr) / sizeof(arr[0]);    // ����ü �迭�� ũ��
    int i;
    char title[40];                 // �˻��� ������ ������ ������ ����

    printf("����? ");
    gets_s(title, sizeof(title));   // ��ĭ�� ������ ���ڿ� �Է�

    for (i = 0; i < size; i++)                  // size�� ����ü �迭�� ũ��
        if (strcmp(arr[i].title, title) == 0)   // ������ ���� ���Ҹ� ã����
            break;                              // for�� Ż���Ѵ�.(i�� ã�� ������ �ε���)

    if (i == size)      // for���� ������ ���������� �˻��� ������ ���
        printf("�ش� �������� ã�� �� �����ϴ�.\n");
    else                // �˻��� ������ ���(i�� ã�� ������ �ε���)
        printf("%s: ����=%d, ����=%.1f\n", arr[i].title, arr[i].price, arr[i].rate);
}
*/