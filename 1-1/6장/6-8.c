#include <stdio.h>

void print_count(void);
void increment(void);
void decrement(void);

int count;

void main()
{
    int i;

    count = 0;
    print_count();

    for (i = 0; i < 5; i++)
        increment();
    print_count();

    for (i = 0; i < 5; i++)
        decrement();
    print_count();
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
