#include <stdio.h>
#define SIZE 10                     // �迭�� ũ��

int is_equal_array(const int x[], const int y[], int sz) // �� �迭�� ������ ��
{
    int i;
    for (i = 0; i < sz; i++)
        if (x[i] != y[i])
            return 0;   
    return 1;
}

void main()
{
    int arr1[SIZE] = { 60, 34, 55, 28, 12, 5, 63, 45, 91 };
    int arr2[SIZE];
    FILE* fp = NULL;

    fp = fopen("test.dat", "wb");               // ��¿� 2�� ������ ����.
    if (fp == NULL) {
        printf("��¿� ���� ���� ����\n");
        return 1;
    }
    fwrite(arr1, sizeof(arr1[0]), SIZE, fp);    // arr1�� ���Ϸ� �����Ѵ�.
    fclose(fp);
    fp = NULL;    // ���� �����͵� �� �̻� ������ ������ �� �����ͷ� �����.

    fp = fopen("test.dat", "rb");               // �Է¿� 2�� ������ ����.
    if (fp == NULL) {                           // fp�� �ٽ� ����� �� �ִ�.
        printf("�Է¿� ���� ���� ����\n");
        return 1;
    }
    fread(arr2, sizeof(arr2[0]), SIZE, fp);     // ���Ͽ��� arr2�� �о�´�.
    fclose(fp);
    fp = NULL;

    if (is_equal_array(arr1, arr2, SIZE))       // arr1�� arr2�� ������ ���Ѵ�.
        printf("2�� ���� ����� ����\n");
    else
        printf("2�� ���� ����� ����\n");
}