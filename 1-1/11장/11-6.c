/*
#include <stdio.h>
#include <string.h>

void main()
{
    char in_fname[128] = "";        // 입력 파일명
    char out_fname[128] = "";       // 출력 파일명
    FILE *fin = NULL;               // 입력 스트림에 대한 파일 포인터
    FILE *fout = NULL;              // 출력 스트림에 대한 파일 포인터
    char str[BUFSIZ];

    printf("파일 이름? ");
    gets_s(in_fname, sizeof(in_fname));
    fin = fopen(in_fname, "r");     // 입력 스트림을 연다.
    if (fin == NULL) {
        printf("%s 파일 열기 실패\n", in_fname);
        return 1;
    }
    strcpy(out_fname, in_fname);
    strcat(out_fname, ".bak");      // 출력 파일명은 입력파일명.bak
    fout = fopen(out_fname, "w");   // 출력 스트림을 연다.
    if (fout == NULL) {
        printf("%s 파일 열기 실패\n", out_fname);
        fclose(fin);    // 출력 스트림을 열 수 없으면 입력 스트림을 닫고 종료한다.
        return 1;
    }
    while (fgets(str, sizeof(str), fin) != NULL)
        fputs(str, fout);
    fclose(fin);                    // 입력 스트림을 닫는다.
    fclose(fout);                   // 출력 스트림을 닫는다.

    printf("파일 백업 성공: %s로 백업했습니다.\n", out_fname);
}
*/