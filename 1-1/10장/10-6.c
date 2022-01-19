/*
#include <stdio.h>
#include <string.h>

struct content {
    char    title[40];
    int     price;
    double  rate;
};

void main()
{
    struct content arr[] = {                    // 초기화된 구조체 배열
        {"Avengers", 11000, 8.8}, {"Aquaman", 5500, 7.1}, {"Shazam!", 7700, 7.4},
        {"X-Men", 3300, 8.0},     {"Us", 8800, 7.1},      {"Inception", 2200, 8.7}
    };
    int size = sizeof(arr) / sizeof(arr[0]);    // 구조체 배열의 크기
    int i;
    char title[40];                 // 검색할 콘텐츠 제목을 저장할 변수

    printf("제목? ");
    gets_s(title, sizeof(title));   // 빈칸을 포함한 문자열 입력

    for (i = 0; i < size; i++)                  // size는 구조체 배열의 크기
        if (strcmp(arr[i].title, title) == 0)   // 제목이 같은 원소를 찾으면
            break;                              // for를 탈출한다.(i는 찾은 원소의 인덱스)

    if (i == size)      // for문을 끝까지 수행했지만 검색이 실패한 경우
        printf("해당 콘텐츠를 찾을 수 없습니다.\n");
    else                // 검색이 성공한 경우(i는 찾은 원소의 인덱스)
        printf("%s: 가격=%d, 평점=%.1f\n", arr[i].title, arr[i].price, arr[i].rate);
}
*/