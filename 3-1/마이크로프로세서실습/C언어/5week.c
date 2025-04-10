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
/*실습2 : 함수*/
    /*void&void*/
    #include <stdio.h>
    
    int in1 = 100; //입력1
    int in2 = 20; //입력2
    int sum = 0; //덧셈
    int sub = 0; //뺄셈
    int mult = 0; //곱셈
    int divd = 0; //나눗셈
    
    void sum_func(void);
    void sub_func(void);
    void mult_func(void);
    void divd_func(void);
    
    void main() {
        sum_func();
        sub_func();
        mult_func();
        divd_func();
    }
    
    void sum_func(void){
        sum = in1 + in2;
        printf("sum = %d\n",sum);
    }
    void sub_func(void){
        sub = in1 - in2;
        printf("sub = %d\n",sub);
    }
    void mult_func(void){
        mult = in1 * in2;
        printf("mult = %d\n",mult);
    }
    void divd_func(void){
        divd = in1 / in2;
        printf("divd = %d\n",divd);
    }

    /*void&인수,인자*/
    #include <stdio.h>
    
    int in1 = 100; //입력1
    int in2 = 20; //입력2
    int sum = 0; //덧셈
    int sub = 0; //뺄셈
    int mult = 0; //곱셈
    int divd = 0; //나눗셈
    
    void sum_func(int a, int b);
    void sub_func(int a, int b);
    void mult_func(int a, int b);
    void divd_func(int a, int b);
    
    void main() {
        sum_func(in1, in2);
        sub_func(in1, in2);
        mult_func(in1, in2);
        divd_func(in1, in2);
    }
    
    void sum_func(int a, int b){
        sum = a + b;
        printf("sum = %d\n",sum);
    }
    void sub_func(int a, int b){
        sub = a - b;
        printf("sub = %d\n",sub);
    }
    void mult_func(int a, int b){
        mult = a * b;
        printf("mult = %d\n",mult);
    }
    void divd_func(int a, int b){
        divd = a / b;
        printf("divd = %d\n",divd);
    }

    /*int&void*/
    #include <stdio.h>
    
    int in1 = 100; //입력1
    int in2 = 20; //입력2
    int sum = 0; //덧셈
    int sub = 0; //뺄셈
    int mult = 0; //곱셈
    int divd = 0; //나눗셈
    
    int sum_func(void);
    int sub_func(void);
    int mult_func(void);
    int divd_func(void);
    
    void main() {
        sum = sum_func();
        sub = sub_func();
        mult = mult_func();
        divd = divd_func();
    
        printf("sum = %d\n",sum);
        printf("sub = %d\n",sub);
        printf("mult = %d\n",mult);
        printf("divd = %d\n",divd);
    }
    
    int sum_func(void){
        int s;
        s = in1 + in2;
        return s;
    }
    int sub_func(void){
        int s;
        s = in1 - in2;
        return s;
    }
    int mult_func(void){
        int s;
        s = in1 * in2;
        return s;
    }
    int divd_func(void){
        int s;
        s = in1 / in2;
        return s;
    }

    /*int&인수, 인자*/
    #include <stdio.h>
    
    int in1 = 100; //입력1
    int in2 = 20; //입력2
    int sum = 0; //덧셈
    int sub = 0; //뺄셈
    int mult = 0; //곱셈
    int divd = 0; //나눗셈
    
    int sum_func(int a, int b);
    int sub_func(int a, int b);
    int mult_func(int a, int b);
    int divd_func(int a, int b);
    
    void main() {
        sum = sum_func(in1, in2);
        sub = sub_func(in1, in2);
        mult = mult_func(in1, in2);
        divd = divd_func(in1, in2);
    
        printf("sum = %d\n",sum);
        printf("sub = %d\n",sub);
        printf("mult = %d\n",mult);
        printf("divd = %d\n",divd);
    }
    
    int sum_func(int a, int b){
        return (a + b);
    }
    int sub_func(int a, int b){
        return (a - b);
    }
    int mult_func(int a, int b){
        return (a * b);
    }
    int divd_func(int a, int b){
        return (a / b);
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
    
    void main() {
        int n = 0;
    
        scanf("%d", &n);
        printf("변수 n의 값은? %d\n", n);
        
        if(n >= 100){
            printf("large\n");
        }
        else{
            printf("small\n");
        }
    }

/*문제3 - REPORT*/
/*학점계산기*/
    #include <stdio.h>
    
    void main() {
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
