/*
#include <stdio.h>

void draw_line(char, int);
double get_area(double radius);

void main()
{
    int r;

    draw_line('-', 40);
    for (r = 5; r <= 20; r+=5) 
        printf("r=%d, 원의 면적: %.2f\n", r, get_area(r));
    draw_line('-', 40);
}

double get_area(double radius)
{
    const double pi = 3.14;
    return pi * radius * radius;
}

void draw_line(char ch, int len)
{
    int i;
    for (i = 0; i < len; i++)
        printf("%c", ch);
    printf("\n");
}
*/