/*
#include <stdio.h>
#include <string.h>

void main()
{
    char str_in[128];
    char str_out[128];
    int year, month, day;

    printf("��¥(yyyymmdd)? ");
    gets_s(str_in, sizeof(str_in)); // �� ���� ���ڿ� �Է�

    // ���ڿ��� int���� year, month, day�� ��ȯ�Ѵ�.
    sscanf(str_in, "%4d%2d%2d", &year, &month, &day);

    // ����� ���ڿ��� str_out�� �����Ѵ�.
    sprintf(str_out, "Due Date: %04d-%02d-%02d", year, month, day);
    puts(str_out);                  // ������ ���ڿ� ���
}
*/
