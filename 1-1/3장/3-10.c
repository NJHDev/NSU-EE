#include <stdio.h>

void main()
{
	int amount = 0, price = 0;
	const double vat_rate = 0.1;
	int total_price = 0;

	printf("amount? ");
	scanf("%d", &amount);
	printf("price? ");
	scanf("%d", &price);
	total_price = amount * price * (1 + vat_rate);
	printf("total price = %d\n", total_price);
}