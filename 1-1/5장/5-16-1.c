#include <stdio.h>

void main()
{
    int i, sum = 0, sum1 = 0, sum2 = 0;

    for (i = 1; i <= 100; i++) 
	{
        printf("%3d ", i);
		sum = sum + i;
		if(i % 2 == 1)
			sum1 = sum1 + i;
		else
			sum2 = sum2 + i;
		if(i % 10 == 0)
			printf("\n");
    }
    printf("1���� 100������ �� = %d\n", sum);
	printf("1���� 100���� �� Ȧ������ �� = %d\n", sum1);
	printf("1���� 100���� �� ¦������ �� = %d\n", sum2);
}