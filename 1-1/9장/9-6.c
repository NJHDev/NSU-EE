/*
#include <stdio.h>
#include <string.h>

void main()
{
    char filename[] = "readme.txt";
    char *p = NULL;

    p = strchr(filename, '.');      // filename에서 '.' 문자를 찾아 그 주소를 받아온다.
    if (p != NULL)
        printf("file extension: %s\n", p + 1);  // p + 1은 '.' 다음 위치의 문자열 주소

    p = strstr(filename, ".txt");   // filename에서 ".txt" 문자열을 찾아 그 주소를 받아온다.
    if (p != NULL)
        printf("file type: TEXT file\n");
}
*/