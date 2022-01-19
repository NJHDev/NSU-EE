/*
#include <stdio.h>
#define ARR_SIZE 10

void main()
{
    int arr[ARR_SIZE] = {1, 1};
    int i;

    for (i = 2; i < ARR_SIZE; i++)
        arr[i] = arr[i - 2] + arr[i - 1];

    for (i = 0; i < ARR_SIZE; i++)
        printf("%d ", arr[i]);
    printf("\n");

    printf("arr[10] = %d\n", arr[10]);
    arr[10] = 100;
}
*/