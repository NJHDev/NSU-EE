#include <stdio.h>
#include <string.h>

void main()
{
    const char* str_menu[] = {  // str_menu�� ���Ұ� 5���� ������ �迭
        "������", "���� �����", "���� ����", "���� ����", "�μ�"
    };
    int sz_menu = sizeof(str_menu) / sizeof(str_menu[0]);   // ������ �迭�� ũ��
    int menu;

    while (1) {
        int i;
        for (i = 0; i < sz_menu; i++)           // ������ �迭�� ũ�⸸ŭ �ݺ��Ѵ�.
            printf("%d.%s\n", i, str_menu[i]);  // str_menu[i]�� ����Ű�� ���ڿ� ���
        printf("�޴� ����? ");
        scanf("%d", &menu);
        if (menu == 0)          // menu�� �Է¹��� ���� ���� Ż�� ������ �˻��Ѵ�.
            break;
        else if (menu > 0 && menu < sz_menu)
            printf("%s �޴��� �����߽��ϴ�.\n\n", str_menu[menu]);
        else
            printf("�߸� �����߽��ϴ�.\n\n");
    }
}
