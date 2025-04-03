/*실습1*/
/*오버플로우 with for*/
#include <stdio.h>

int num = 0;
int cnt;

int main() {

    for(cnt = 0; cnt <= 260; cnt++){
        printf("num=%d\n",++num);
    }
    return 0;
}

#include <stdio.h>

unsigned num = 0;
int cnt;

int main() {

    for(cnt = 0; cnt <= 260; cnt++){
        printf("num=%d\n",++num);
    }
    return 0;
}

/*문제1*/
/*int형 오버플로우 알아보기*/
#include <stdio.h>

char signed_num = 0;
unsigned char unsigned_num = 0;
int cnt;

int main() {

    for(cnt = 0; cnt <= 260; cnt++){
        printf("signed_num=%d, unsigned_num=%d\n", signed_num++, unsigned_num++);
    }
    return 0;
}

/*문제2*/
/*변수 n의 값이 100보다 크거나 같으면 "large", 100보다 작으면 "small"을 출력하는 if-else문을 작성하라.*/
#include <stdio.h>

int main() {
    int n = 0;

    scanf("%d", &n);
    printf("변수 n의 값은? %d\n", n);
    
    if(n >= 100){
        printf("large");
    }
    else{
        printf("small");
    }
}

/*문제3*/
/*학점계산기*/
#include <stdio.h>

int main() {
    int score = 0;

    scanf("%d", &score);
    printf("점수는? %d\n", score);
    
    if(score >= 90){
        printf("A학점");
    }
        else if(score >= 80){
            printf("B학점");
        }
        else if(score >= 70){
            printf("C학점");
        }
        else if(score >= 60){
            printf("D학점");
        }
        else{
            printf("F학점");
        }
}
