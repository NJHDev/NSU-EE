/*
#include <stdio.h>

enum direction { north, south, east, west };  // ����ü�� ���� ��� ����

void main()
{
    enum direction moves[] = {      // ����ü �迭 (�̵� ������ ������� ����)
        north, north, east, south, south, west,
    };
    int size = sizeof(moves) / sizeof(moves[0]);
    int i;
    printf("�̵� ����: ");
    for (i = 0; i < size; i++) {
        switch (moves[i]) {         // moves[i] ����ü ������ ���� ���� ó��
        case north:                 // ���� ����� case���� ����� �� �ִ�.
            printf("�� ");
            break;
        case south:
            printf("�� ");
            break;
        case east:
            printf("�� ");
            break;
        case west:
            printf("�� ");
            break;
        }
    }
    printf("\n");
}
*/