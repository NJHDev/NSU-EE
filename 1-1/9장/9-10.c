/*
#include <stdio.h>
#include <string.h>             
#include <ctype.h>       

int count_space(const char* s)  // s�� �Է� �Ű������̹Ƿ� �Լ� �ȿ��� ������� �ʴ´�.
{
    int count = 0;
    while (s[0] != '\0') {      // while (*s != '\0') �� ���� �ǹ�
        if (isspace(s[0]))      // *s�� ���� �������� �˻��Ѵ�.
            count++;
        s++;                    // s�� ���� ���ڸ� ����Ų��.
    }
    return count;
}

void main()
{
    char str[64] = "this program\ttests const pointer to string.\n";

    puts(str);
    printf("���� ������ ����: %d\n", count_space(str));    // str�� ������� �ʴ´�.
}
*/