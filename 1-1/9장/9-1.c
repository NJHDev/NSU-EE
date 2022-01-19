/*
#include <stdio.h>

void main()
{
    char str1[10] = "abc";              // 문자 배열은 문자열 리터럴로 초기화한다.
    char str2[10] = "very long string"; //문자 배열보다 긴 문자열로 초기화하는 경우
    char str3[] = "abc";                // 크기가 4인 배열로 할당된다.
    char str4[10] = "";                 // 배열 전체를 널 문자로 초기화한다.
    int i;

    str1[0] = 'A';                      // 인덱스를 이용해서 한 문자씩 변경할 수 있다.
    printf("str1 = ");
    for (i = 0; str1[i] != '\0'; i++)   // 널 문자를 만날 때까지 
        printf("%c", str1[i]);          // str1[i]를 한 문자씩 출력한다.
    printf("\n");

    printf("str2 = %s\n", str2);    // 문자열의 끝에 널 문자가 없으므로 쓰레기값 출력
    printf(str3);           // printf 함수의 첫 번째 인자로 문자 배열을 전달할 수 있다.
    printf("\nstr4 = %s\n", str4);  // str4는 널 문자열이므로 아무것도 출력되지 않는다.

    //str1 = "XYZ";         // 배열 이름은 배열의 시작 주소이므로 변경할 수 없다.
    strcpy(str1, "XYZ");    // 문자열을 변경하려면 문자열 처리 함수를 이용한다.
}
*/