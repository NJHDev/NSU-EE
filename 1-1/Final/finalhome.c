#include <stdio.h>

void main()
{
	int i, num;
	float kor_sum = 0, eng_sum = 0, math_sum = 0;
	int kor[100], eng[100], math[100];
	char name[100][100];

	printf("학생수 입력: ");
	scanf("%d", &num);
	printf("\n");

	for (i = 0; i < num; i++)
	{
		printf("%d번 학생 이름 입력: ", i + 1);
		scanf("%s", name[i]);
		printf("%d번 학생 국어, 영어, 수학 성적 입력: ", i + 1);
		scanf("%d %d %d", &kor[i], &eng[i], &math[i]);
		kor_sum += kor[i];
		eng_sum += eng[i];
		math_sum += math[i];
	}

	printf("===========================================\n\n\n");

	for (i = 0; i < num; i++)
	{
		float sum = kor[i] + eng[i] + math[i];
		printf("%s / 총점: %.f점 / 평균: %.2f점 /", name[i], sum, sum / 3);
		if (sum / 3 >= 90) printf(" 우수\n");
		else if (sum / 3 >= 70) printf(" 양호\n");
		else printf(" 부족\n");
	}

	printf("국어 평균: %.2f점 / 영어 평균: %.2f점 / 수학 평균: %.2f점\n", kor_sum / num, eng_sum / num, math_sum / num);

}