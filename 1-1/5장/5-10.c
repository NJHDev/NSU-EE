/*
#include <stdio.h>

void main()
{
	double x, y ,result=0;
	char op, yesno='Y';

	while (yesno=='Y' || yesno == 'y')
	{
		printf("����? ");
		scanf("%lf %c %lf", &x, &op, &y);

		if(op=='+')
			result = x+y;
		else if(op=='-')
			result = x-y;
		else if(op=='*')
			result = x*y;
		else if(op=='/')
			result = x/y;
		else
		{
		printf("�߸��� �����Դϴ�.\n");
		return 1;
		}
		printf("%f %c %f = %f\n", x, op, y, result);

		printf("��� �Ͻðڽ��ϱ�(Y/N)? ");
		scanf(" %c", &yesno);
	}
}
*/