/*
#include <stdio.h>
#include <string.h>             // 문자열 처리 함수 사용 시 필요하다.

void main()
{
    char str[10] = "hello";     // 크기가 10인 문자 배열 선언
    int len = 0;
                                                               
    printf("str의 길이: %d\n", strlen(str));       // 널 문자를 제외한 문자열의 길이
    printf("\"good bye\"의 길이: %d\n", strlen("good bye"));   // 문자열 리터럴의 길이

    printf("str = %s\n", str);
    len = strlen(str);
    if (len > 0)                // 널 문자열이 아니면
        str[len - 1] = '\0';    // 마지막 한 글자를 삭제한다.
    printf("str = %s\n", str);
}
*/