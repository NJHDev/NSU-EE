/*
#include <stdio.h>

struct point {                       // ����ü ���ǰ� �Լ� ���𺸴� �տ� �;� �Ѵ�.
    int x, y;
};
void print_point(struct point pt);   // �Լ� ����

void main()
{
    struct point arr[] = {          // point ����ü �迭
        {10, 20}, {35, 41}, {12, 63}, {72, 55}, {92, 86}, {4, 27}
    };
    int size = sizeof(arr) / sizeof(arr[0]);
    int i;

    for (i = 0; i < size; i++) {
        print_point(arr[i]);        // arr[i]�� �Լ��� �Ű����� pt�� �����ؼ� �����Ѵ�.
    }
    printf("\n");
}

void print_point(struct point pt)   // pt�� ���� ���� ȣ��� ���޵ȴ�.
{
    printf("(%d, %d) ", pt.x, pt.y);
}
*/