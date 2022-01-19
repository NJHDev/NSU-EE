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
    struct content arr[] = {        // 구조체 배열의 선언 및 초기화
        {"Avengers", 11000, 8.8},     // arr[0]의 초기값
        {"Aquaman", 5500, 7.1},       // arr[1]의 초기값
        {"Shazam!", 7700, 7.4}        // arr[2]의 초기값
    };
    int size = sizeof(arr) / sizeof(arr[0]);    // 배열의 크기
    int i;

    for (i = 0; i < size; i++)      // arr[i]는 content 구조체 변수이다.
        printf("arr[%d] = %s, %d, %.1f\n", i, arr[i].title, arr[i].price, arr[i].rate);
}
*/