/*
#include <stdio.h>

void main()
{
    FILE* fp = fopen("a.txt", "r"); // "a.txt"가 없으므로 파일 열기 실패
    if (fp == NULL) {   // 파일 열기가 실패했는지 반드시 확인해야 한다.
        printf("파일 열기 실패\n");
        return 1;       // 파일 열기 실패 시 더 이상 입출력을 수행하지 않도록 처리한다.
    }
    printf("파일 열기 성공\n");
    fclose(fp);         // 파일 열기가 성공인 경우에만 파일을 닫아야 한다.
}
*/