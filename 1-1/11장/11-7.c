/*
#include <stdio.h>
#include <string.h>

void print_array(const int arr[], int size, FILE* stream)
{
    int  i;
    for (i = 0; i < size; i++)
        fprintf(stream, "%2d ", arr[i]);    // 파일 포인터를 이용해서 출력한다.
    fprintf(stream, "\n");
}

void main()
{
    int arr[] = { 60, 34, 55, 28, 12, 5, 63, 45, 91 };
    int size = sizeof(arr) / sizeof(arr[0]);
    char filename[128] = "";
    FILE *fp = NULL;

    printf("파일 이름? ");
    gets_s(filename, sizeof(filename));
    fp = fopen(filename, "w");
    if (fp == NULL)
        fp = stdout;            // 파일 열기 실패면 표준 출력에 출력한다.
    print_array(arr, size, fp);
    fclose(fp);
}
*/