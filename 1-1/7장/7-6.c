/*
#include <stdio.h>
#define ARR_SIZE 5

void main()
{
    int x[ARR_SIZE] = { 10, 20, 30, 40, 50 };
    int y[ARR_SIZE] = { 10, 20, 30, 40, 50 };
    int i;
    int is_equal;

    if (x == y) 
        printf("두 배열의 주소가 같습니다.\n");
    else
        printf("두 배열의 주소가 다릅니다.\n");

    is_equal = 1;
    for (i = 0; i < ARR_SIZE; i++) {
        if (x[i] != y[i]) 
		{
            is_equal = 0;
            break;
        }
    }
    if (is_equal == 1)
        printf("두 배열의 내용이 같습니다.\n");
    else
        printf("두 배열의 내용이 다릅니다.\n");
}
*/