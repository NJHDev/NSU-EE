#include <stdio.h>

void main()
{
	int kor, eng, math;
	float sum, avr;
	

	printf("국어 점수는? ");
	scanf("%d", &kor);

	printf("영어 점수는? ");
	scanf("%d", &eng);

	printf("수학 점수는? ");
	scanf("%d", &math);

	printf("====================\n");

	sum=kor+eng+math;
	avr=sum/3;

	printf("총점 : %.f\n", sum);
	printf("평균 : %.2f\n", avr);

	if(avr>=70)
		printf("결과 : PASS\n");
	else
		printf("결과 : FAIL\n");
}
