/*
#include <stdio.h>

void test1(int x)   // 매개변수 x는 함수가 호출될 때 main의 x로 초기화된다.
{
    x = 20;         // 매개변수를 변경하는 것은 아무 의미가 없다.
}                   // 매개변수 x는 test1이 리턴할 때 소멸된다.

void test2(int *p)  // 매개변수 p는 main의 x를 가리킨다.
{
    *p = 20;        // p가 가리키는 변수(main의 x)에 20을 대입한다.
}

void main()
{
    int x = 10;
    test1(x);       // main의 x를 test1의 매개변수 x로 복사해서 전달한다.
    printf("test1 호출 후 x = %d\n", x);  // x의 값은 변경되지 않는다.

    test2(&x);      // x의 주소를 test2의 매개변수 p로 전달한다.
    printf("test2 호출 후 x = %d\n", x);  // x의 값이 변경된다.
}
*/