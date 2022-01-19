/*
//계산기 Switch사용
#include <stdio.h>

void main()
{
	double x, y, result = 0;
	char op;

	printf("수식? ");
	scanf("%lf %c %lf", &x, &op, &y);

	switch(op)
	{
	case '+':
		result = x + y;
		break;
	case '-':
			result = x - y;
			break;
	case '*':
			result = x * y;
			break;
	case '/':
			result = x / y;
			break;
	default:
		printf("잘못된 수식입니다.\n");
		break;
	}
	printf("%f %c %f = %f\n", x, op, y, result);
}
*/