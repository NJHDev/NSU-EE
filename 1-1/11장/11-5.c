/*
// fgetc_test.c : 소스 파일 이름
#include <stdio.h>

void main()
{
    FILE *fp = NULL;
    int ch;

    fp = fopen("fgetc_test.c", "r");    // 프로젝트 디렉터리의 소스 파일을 연다.
    if (fp == NULL) {
        printf("파일 열기 실패\n");
        return 1;
    }
    while ((ch = fgetc(fp)) != EOF)     // 파일에서 문자 하나를 읽는다
        fputc(ch, stdout);              // 표준 출력 스트림으로 문자 하나를 출력한다.
    fclose(fp);
}
*/