/*
#include <stdio.h>

void print_array(int arr[], int size)
{
    int  i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main()
{
    int data[] = { 12, 34, 51, 22, 91, 12, 15 };
    int size, i;
    int key;

    size = sizeof(data) / sizeof(data[0]);
    printf("data = ");
    print_array(data, size);

    printf("찾을 값(키)? ");
    scanf("%d", &key);
    for (i = 0; i < size; i++) {
        if (data[i] == key)
            printf("찾은 원소의 인덱스: %d\n", i);
    }
}
*/