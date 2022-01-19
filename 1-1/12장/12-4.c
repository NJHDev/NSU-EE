/*
#include <stdio.h>

void accumulator(char op, int rhs);

void main()
{
    while (1) {
        char op;
        int num;
        printf("연산자와 정수를 입력하세요(. 0 입력시 종료): ");
        scanf(" %c %d", &op, &num);
        if (op == '.' && num == 0)
            break;
        accumulator(op, num);
    }
}

void accumulator(char op, int rhs)
{
    static int result = 0;      // 프로그램 시작 시 한번만 생성되고 초기화된다.
    printf("%d ", result);      // 이전 연산의 결과값이 lhs로 사용된다.
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
}   // 함수가 리턴해도 result는 사라지지 않고 남아서 다음 번 함수 호출에 이용된다.
*/