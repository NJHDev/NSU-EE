#include <stdio.h>

void main()
{
	int kor, eng, math;
	float sum, avr;
	

	printf("���� ������? ");
	scanf("%d", &kor);

	printf("���� ������? ");
	scanf("%d", &eng);

	printf("���� ������? ");
	scanf("%d", &math);

	printf("====================\n");

	sum=kor+eng+math;
	avr=sum/3;

	printf("���� : %.f\n", sum);
	printf("��� : %.2f\n", avr);

	if(avr>=70)
		printf("��� : PASS\n");
	else
		printf("��� : FAIL\n");
}
