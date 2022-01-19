/*
#include <stdio.h>
#define ROW 3
#define COL 2

void main()
{
    int data[ROW][COL];
    int i, j, k;

    for (i = 0, k = 0; i < ROW; i++)
        for (j = 0; j < COL; j++)
            data[i][j] = ++k;

    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++)
            printf("%3d ", data[i][j]);
        printf("\n");
    }

    printf("sizeof(data)       = %d\n", sizeof(data));
    printf("sizeof(data[0])    = %d\n", sizeof(data[0]));
    printf("sizeof(data[0][0]) = %d\n", sizeof(data[0][0]));
}
*/