/*
#include <stdio.h>
#define SIZE 5

void print_array(int arr[], int size)
{
    int  i;
    for (i = 0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void main()
{
    int data[SIZE] = { 52, 31, 28, 17, 46 };
    int i, j, temp;
    int index_min;

    for (i = 0; i < SIZE - 1; i++)
		{
        index_min = i;
        for (j = i + 1; j < SIZE; j++) 
			{

            if (data[index_min] > data[j])
                index_min = j;
			 }
        if (i != index_min) 
			{
            temp = data[i];
            data[i] = data[index_min];
            data[index_min] = temp;
			}

        printf("i = %d 일때 정렬 결과 : ", i);
        print_array(data, SIZE);
    }
}
*/