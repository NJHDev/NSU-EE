#include <stdio.h>
#define SIZE 10                     // 배열의 크기

int is_equal_array(const int x[], const int y[], int sz) // 두 배열이 같은지 비교
{
    int i;
    for (i = 0; i < sz; i++)
        if (x[i] != y[i])
            return 0;   
    return 1;
}

void main()
{
    int arr1[SIZE] = { 60, 34, 55, 28, 12, 5, 63, 45, 91 };
    int arr2[SIZE];
    FILE* fp = NULL;

    fp = fopen("test.dat", "wb");               // 출력용 2진 파일을 연다.
    if (fp == NULL) {
        printf("출력용 파일 열기 실패\n");
        return 1;
    }
    fwrite(arr1, sizeof(arr1[0]), SIZE, fp);    // arr1을 파일로 저장한다.
    fclose(fp);
    fp = NULL;    // 파일 포인터도 더 이상 사용되지 않으면 널 포인터로 만든다.

    fp = fopen("test.dat", "rb");               // 입력용 2진 파일을 연다.
    if (fp == NULL) {                           // fp를 다시 사용할 수 있다.
        printf("입력용 파일 열기 실패\n");
        return 1;
    }
    fread(arr2, sizeof(arr2[0]), SIZE, fp);     // 파일에서 arr2로 읽어온다.
    fclose(fp);
    fp = NULL;

    if (is_equal_array(arr1, arr2, SIZE))       // arr1과 arr2가 같은지 비교한다.
        printf("2진 파일 입출력 성공\n");
    else
        printf("2진 파일 입출력 실패\n");
}