/*
#include <stdio.h>

void main()
{
    int year, month, day;

    while (1) {
        printf("날짜? ");
        if (scanf("%4d%2d%2d", &year, &month, &day) == 3 )  // 입력 성공 시 루프 탈출
            break;
        printf("yyyymmdd 형식으로 입력하세요.\n");   // 입력 실패에 대한 에러 메시지 출력
        while (getchar() != '\n') {}                 // 입력 버퍼를 비운다.
    }
    printf("입력된 날짜: %4d-%02d-%02d\n", year, month, day);    // 2019-05-20 형식으로 출력
}
*/