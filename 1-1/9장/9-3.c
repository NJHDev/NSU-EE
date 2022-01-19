/*
#include <stdio.h>
#include <string.h>             // 문자열 처리 함수 사용 시 포함

void main()
{
    char str1[10] = "";         // 널 문자열로 초기화한다.
    char str2[10] = "";         // 널 문자열로 초기화한다.
    char temp[10];
    
    printf("2개의 문자열? ");
    scanf("%s %s", str1, str2); // 빈칸으로 구분해서 문자열 입력
    printf("str1 = %s, str2 = %s\n", str1, str2);

    // 두 문자 배열을 swap한다.
    strcpy(temp, str1);         // str1을 temp로 복사한다.
    strcpy(str1, str2);         // str2을 str1로 복사한다.
    strcpy(str2, temp);         // temp을 str2로 복사한다.
    printf("str1 = %s, str2 = %s\n", str1, str2);
}
*/