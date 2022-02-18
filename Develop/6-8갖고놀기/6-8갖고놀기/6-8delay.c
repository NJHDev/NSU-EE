#include <stdio.h>
#include <stdlib.h>

void print_count(void);
void increment(void);
void decrement(void);

int count;

void main()
{
    int i;

	while(1)
   {
		count = 0;
		print_count();

		for (i = 0; i < 5; i++)
			increment();
		print_count();

		for (i = 0; i < 5; i++)
			decrement();
		print_count();
		_sleep(1000);
		printf("------------------\n");
   }
}

void print_count(void)
{
    printf("count = %d\n", count);
}
void increment(void)
{
    count++;
}

void decrement(void)
{
    count--;
}