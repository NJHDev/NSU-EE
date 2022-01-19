/*
#include <stdio.h>
#include <string.h>

struct content {
    char title[40];
    int price;
    double rate;
};

void main()
{
    struct content c1 = { "Avengers", 11000, 8.8 }; // 구조체 변수의 선언 및 초기화
    struct content c2, c3;          // 초기화되지 않은 구조체 변수 선언(쓰레기값)

    strcpy(c2.title, "Aquaman");    // 구조체 변수 c2의 멤버를 변경한다.
    c2.price = 5500;
    c2.rate = 7.1;

    strcpy(c3.title, "Shazam!");    // 구조체 변수 c3의 멤버를 변경한다.
    c3.price = 7700;
    c3.rate = 7.4;

    printf("c1 = %s, %d, %.1f\n", c1.title, c1.price, c1.rate); // c1의 멤버들을 출력한다.
    printf("c2 = %s, %d, %.1f\n", c2.title, c2.price, c2.rate); // c2의 멤버들을 출력한다.
    printf("c3 = %s, %d, %.1f\n", c3.title, c3.price, c3.rate); // c3의 멤버들을 출력한다.
}
*/