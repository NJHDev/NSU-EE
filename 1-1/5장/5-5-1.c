/*
//���� Switch���
#include <stdio.h>

void main()
{
	double x, y, result = 0;
	char op;

	printf("����? ");
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
		printf("�߸��� �����Դϴ�.\n");
		break;
	}
	printf("%f %c %f = %f\n", x, op, y, result);
}
*/