/*
#include <stdio.h>

enum direction { north, south, east, west };  // 열거체와 열거 상수 정의

void main()
{
    enum direction moves[] = {      // 열거체 배열 (이동 방향을 순서대로 저장)
        north, north, east, south, south, west,
    };
    int size = sizeof(moves) / sizeof(moves[0]);
    int i;
    printf("이동 순서: ");
    for (i = 0; i < size; i++) {
        switch (moves[i]) {         // moves[i] 열거체 변수의 값에 따라 처리
        case north:                 // 열거 상수는 case문에 사용할 수 있다.
            printf("북 ");
            break;
        case south:
            printf("남 ");
            break;
        case east:
            printf("동 ");
            break;
        case west:
            printf("서 ");
            break;
        }
    }
    printf("\n");
}
*/