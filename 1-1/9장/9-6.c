/*
#include <stdio.h>
#include <string.h>

void main()
{
    char filename[] = "readme.txt";
    char *p = NULL;

    p = strchr(filename, '.');      // filename���� '.' ���ڸ� ã�� �� �ּҸ� �޾ƿ´�.
    if (p != NULL)
        printf("file extension: %s\n", p + 1);  // p + 1�� '.' ���� ��ġ�� ���ڿ� �ּ�

    p = strstr(filename, ".txt");   // filename���� ".txt" ���ڿ��� ã�� �� �ּҸ� �޾ƿ´�.
    if (p != NULL)
        printf("file type: TEXT file\n");
}
*/