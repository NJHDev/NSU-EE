/*
#include <stdio.h>
#include <string.h>

void main()
{
    char in_fname[128] = "";        // �Է� ���ϸ�
    char out_fname[128] = "";       // ��� ���ϸ�
    FILE *fin = NULL;               // �Է� ��Ʈ���� ���� ���� ������
    FILE *fout = NULL;              // ��� ��Ʈ���� ���� ���� ������
    char str[BUFSIZ];

    printf("���� �̸�? ");
    gets_s(in_fname, sizeof(in_fname));
    fin = fopen(in_fname, "r");     // �Է� ��Ʈ���� ����.
    if (fin == NULL) {
        printf("%s ���� ���� ����\n", in_fname);
        return 1;
    }
    strcpy(out_fname, in_fname);
    strcat(out_fname, ".bak");      // ��� ���ϸ��� �Է����ϸ�.bak
    fout = fopen(out_fname, "w");   // ��� ��Ʈ���� ����.
    if (fout == NULL) {
        printf("%s ���� ���� ����\n", out_fname);
        fclose(fin);    // ��� ��Ʈ���� �� �� ������ �Է� ��Ʈ���� �ݰ� �����Ѵ�.
        return 1;
    }
    while (fgets(str, sizeof(str), fin) != NULL)
        fputs(str, fout);
    fclose(fin);                    // �Է� ��Ʈ���� �ݴ´�.
    fclose(fout);                   // ��� ��Ʈ���� �ݴ´�.

    printf("���� ��� ����: %s�� ����߽��ϴ�.\n", out_fname);
}
*/