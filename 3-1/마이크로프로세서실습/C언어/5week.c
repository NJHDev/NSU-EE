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

/*문제4*/
/*변수 fruit의 값이 각각 1, 2, 5일 때, 다음의 코드의 출력을 쓰시오. / if문으로 변환하시오.*/
/*Default Code*/
#include <stdio.h>

int main() {
    int fruit = 0;
    
    scanf("%d", &fruit);
    printf("과일 몇번? %d\n", fruit);
    
    switch(fruit) {
        case 1:
            printf("사과\n");
            break;
        case 2:
            printf("배\n");
            break;
        case 3:
            printf("바나나\n");
            break;
        default:
            printf("과일\n");
            break;
    }

    return 0;
}

/if문으로 변환*/
#include <stdio.h>

int main() {
    int fruit = 0;
    
    scanf("%d", &fruit);
    printf("과일 몇번? %d\n", fruit);
    
    if (fruit == 1) {
        printf("사과\n");
    } 
        else if (fruit == 2) {
            printf("배\n");
        }
        else if (fruit == 3) {
            printf("바나나\n");
        }
        else {
            printf("과일\n");
        }

    return 0;
}
