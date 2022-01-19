/*
#include <stdio.h>

struct point {
    int x, y;
};
void print_point(const struct point* ptr);      // ptr�� �Է� �Ű�����
void move_point(struct point* ptr, int offset); // ptr�� ����� �Ű�����

void main()
{
    struct point arr[] = {
        {10, 20}, {35, 41}, {12, 63}, {72, 55}, {92, 86}, {4, 27}
    };
    int size = sizeof(arr) / sizeof(arr[0]);
    int i, offset;

    for (i = 0; i < size; i++) {
        print_point(&arr[i]);           // arr[i]�� �ּҸ� �Ű����� ptr�� �����Ѵ�.
    }                                   // ����ü�� �������� �ʰ� �����ϹǷ� ȿ�����̴�.
    printf("\n");

    printf("�̵��� ������? ");
    scanf("%d", &offset);
    for (i = 0; i < size; i++) {
        move_point(&arr[i], offset);    // arr[i]�� offset��ŭ �̵��Ѵ�.
        print_point(&arr[i]);           // �̵��� arr[i]�� ����Ѵ�.
    }
}

void print_point(const struct point* ptr)       // ptr�� �Է� �Ű�����
{
    printf("(%d, %d) ", ptr->x, ptr->y);    // ptr�� �������̹Ƿ� ->�� ����� �����Ѵ�.
}

void move_point(struct point* ptr, int offset)  // ptr�� ����� �Ű�����
{
    ptr->x = ptr->x + offset;               // ptr�� ����Ű�� ����ü�� ����� �����Ѵ�.
    ptr->y = ptr->y + offset;               // ptr�� ����Ű�� ����ü�� ����� �����Ѵ�.
}
*/