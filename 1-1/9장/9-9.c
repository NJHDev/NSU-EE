/*
#include <stdio.h>
#include <string.h>
#include <ctype.h>                  // 문자 처리 라이브러리 사용 시 필요

void main()
{
    char str[64] = "this is test string for char pointer.";
    char* p = str;                  // p는 str 배열을 가리킨다.

    while (1) {
        if (islower(p[0]))          // p[0]이 소문자인지 검사한다.
            p[0] = toupper(p[0]);   // p가 가리키는 str[0]을 대문자로 변경한다.
        p = strchr(p, ' ');         // str중 ' ' 문자를 찾아 그 주소를 p에 저장한다.
        if (p == NULL)
            break;
        p++;                        // p가 ' ' 문자 다음 문자를 가리키게 한다.
    }
    puts(str);
}
*/