#include <stdio.h>

void main()
{
	int age;
	float height, weight;

	printf("����, Ű, �����Ը� �Է��ϼ���: ");
	scanf("%d %f %f", &age, &height, &weight);

	printf("����  : %5d\n", age);
	printf("Ű    : %5.1f\n", height);
	printf("������: %5.1f\n", weight);
}