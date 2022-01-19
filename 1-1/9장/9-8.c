/*
#include <stdio.h>
#include <string.h>

void main()
{
    char str_in[128];
    char str_out[128];
    int year, month, day;

    printf("날짜(yyyymmdd)? ");
    gets_s(str_in, sizeof(str_in)); // 한 줄의 문자열 입력

    // 문자열을 int형의 year, month, day로 변환한다.
    sscanf(str_in, "%4d%2d%2d", &year, &month, &day);

    // 출력할 문자열을 str_out에 생성한다.
    sprintf(str_out, "Due Date: %04d-%02d-%02d", year, month, day);
    puts(str_out);                  // 한줄의 문자열 출력
}
*/
