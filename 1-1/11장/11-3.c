/*
#include <stdio.h>

void main()
{
    FILE* fout = NULL;      // ��¿� ���� ������
    FILE* fin = NULL;       // �Է¿� ���� ������

    fout = fopen("a.txt", "w");     // ��¿� �ؽ�Ʈ ������ ����.
    if (fout == NULL) {
        printf("���� ���� ����\n");
        return 1;
    }
    fclose(fout);                   // ��¿� ������ �ݴ´�.

    fin = fopen("a.txt", "r");      // �Է¿� �ؽ�Ʈ ������ ����.
    if (fin == NULL) {
        printf("���� ���� ����\n");
        return 1;
    }
    printf("���� ���� ����\n");
    fclose(fin);                    // �Է¿� ������ �ݴ´�.
}
*/