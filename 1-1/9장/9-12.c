#include <stdio.h>
#include <string.h>

void main()
{
    const char* str_menu[] = {  // str_menu는 원소가 5개인 포인터 배열
        "끝내기", "새로 만들기", "파일 열기", "파일 저장", "인쇄"
    };
    int sz_menu = sizeof(str_menu) / sizeof(str_menu[0]);   // 포인터 배열의 크기
    int menu;

    while (1) {
        int i;
        for (i = 0; i < sz_menu; i++)           // 포인터 배열의 크기만큼 반복한다.
            printf("%d.%s\n", i, str_menu[i]);  // str_menu[i]가 가리키는 문자열 출력
        printf("메뉴 선택? ");
        scanf("%d", &menu);
        if (menu == 0)          // menu를 입력받은 다음 루프 탈출 조건을 검사한다.
            break;
        else if (menu > 0 && menu < sz_menu)
            printf("%s 메뉴를 선택했습니다.\n\n", str_menu[menu]);
        else
            printf("잘못 선택했습니다.\n\n");
    }
}
