/*
#include <stdio.h>

void accumulator(char op, int rhs);

void main()
{
    while (1) {
        char op;
        int num;
        printf("�����ڿ� ������ �Է��ϼ���(. 0 �Է½� ����): ");
        scanf(" %c %d", &op, &num);
        if (op == '.' && num == 0)
            break;
        accumulator(op, num);
    }
}

void accumulator(char op, int rhs)
{
    static int result = 0;      // ���α׷� ���� �� �ѹ��� �����ǰ� �ʱ�ȭ�ȴ�.
    printf("%d ", result);      // ���� ������ ������� lhs�� ���ȴ�.
    switch (op) {
    case '+':
        result += rhs;      break;
    case '-':
        result -= rhs;      break;
    case '*':
        result *= rhs;      break;
    case '/':
        result /= rhs;      break;
    default:
        return;
    }
    printf("%c %d = %d\n", op, rhs, result);
}   // �Լ��� �����ص� result�� ������� �ʰ� ���Ƽ� ���� �� �Լ� ȣ�⿡ �̿�ȴ�.
*/