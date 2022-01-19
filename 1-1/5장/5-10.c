/*
#include <stdio.h>

void main()
{
	double x, y ,result=0;
	char op, yesno='Y';

	while (yesno=='Y' || yesno == 'y')
	{
		printf("수식? ");
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
		printf("잘못된 수식입니다.\n");
		return 1;
		}
		printf("%f %c %f = %f\n", x, op, y, result);

		printf("계속 하시겠습니까(Y/N)? ");
		scanf(" %c", &yesno);
	}
}
*/