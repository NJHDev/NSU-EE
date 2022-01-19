#include <stdio.h>

void main()
{
	int age;
	float height, weight;

	printf("나이, 키, 몸무게를 입력하세요: ");
	scanf("%d %f %f", &age, &height, &weight);

	printf("나이  : %5d\n", age);
	printf("키    : %5.1f\n", height);
	printf("몸무게: %5.1f\n", weight);
}