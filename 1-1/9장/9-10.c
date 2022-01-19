/*
#include <stdio.h>
#include <string.h>             
#include <ctype.h>       

int count_space(const char* s)  // s는 입력 매개변수이므로 함수 안에서 변경되지 않는다.
{
    int count = 0;
    while (s[0] != '\0') {      // while (*s != '\0') 과 같은 의미
        if (isspace(s[0]))      // *s가 공백 문자인지 검사한다.
            count++;
        s++;                    // s는 다음 문자를 가리킨다.
    }
    return count;
}

void main()
{
    char str[64] = "this program\ttests const pointer to string.\n";

    puts(str);
    printf("공백 문자의 개수: %d\n", count_space(str));    // str은 변경되지 않는다.
}
*/