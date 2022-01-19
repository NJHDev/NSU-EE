#include <stdio.h>
#define SIZE 10

void copy_array(const int *source, int *target, int size);
void print_array(const int *arr, int size); 

void main()
{
    int x[SIZE] = { 10, 20, 30, 40, 50 };
    int y[SIZE] = { 0 };

    printf("x = ");
    print_array(x, SIZE);   // �迭�� ���� �ּ� x�� arr�� �����Ѵ�.(������ ���� ȣ��)

    copy_array(x, y, SIZE);
    printf("y = ");
    print_array(y, SIZE);
}

// source�� size�� �Է� �Ű�����,  target�� ��� �Ű�����
void copy_array(const int *source, int *target, int size)
{
    int i;
    for (i = 0; i < size; i++)
        target[i] = source[i];  // source, target�� ���������� �迭ó�� ����Ѵ�.
}

void print_array(const int *arr, int size)  // arr�� �Է� �Ű�����
{
    int  i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);  // arr�� ���������� �迭ó�� ����Ѵ�.
    printf("\n");
}