/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>                  // ���� ó�� ���̺귯�� ��� �� �ʿ�

void main()
{
    char str[64] = "this is test string for char pointer.";
    char* p = str;                  // p�� str �迭�� ����Ų��.

    while (1) {
        if (islower(p[0]))          // p[0]�� �ҹ������� �˻��Ѵ�.
            p[0] = toupper(p[0]);   // p�� ����Ű�� str[0]�� �빮�ڷ� �����Ѵ�.
        p = strchr(p, ' ');         // str�� ' ' ���ڸ� ã�� �� �ּҸ� p�� �����Ѵ�.
        if (p == NULL)
            break;
        p++;                        // p�� ' ' ���� ���� ���ڸ� ����Ű�� �Ѵ�.
    }
    puts(str);
}
*/