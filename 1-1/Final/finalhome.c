#include <stdio.h>

void main()
{
	int i, num;
	float kor_sum = 0, eng_sum = 0, math_sum = 0;
	int kor[100], eng[100], math[100];
	char name[100][100];

	printf("�л��� �Է�: ");
	scanf("%d", &num);
	printf("\n");

	for (i = 0; i < num; i++)
	{
		printf("%d�� �л� �̸� �Է�: ", i + 1);
		scanf("%s", name[i]);
		printf("%d�� �л� ����, ����, ���� ���� �Է�: ", i + 1);
		scanf("%d %d %d", &kor[i], &eng[i], &math[i]);
		kor_sum += kor[i];
		eng_sum += eng[i];
		math_sum += math[i];
	}

	printf("===========================================\n\n\n");

	for (i = 0; i < num; i++)
	{
		float sum = kor[i] + eng[i] + math[i];
		printf("%s / ����: %.f�� / ���: %.2f�� /", name[i], sum, sum / 3);
		if (sum / 3 >= 90) printf(" ���\n");
		else if (sum / 3 >= 70) printf(" ��ȣ\n");
		else printf(" ����\n");
	}

	printf("���� ���: %.2f�� / ���� ���: %.2f�� / ���� ���: %.2f��\n", kor_sum / num, eng_sum / num, math_sum / num);

}