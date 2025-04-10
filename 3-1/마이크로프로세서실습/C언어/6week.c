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

/*문제5*/
    #include <stdio.h>
    
    int main() {
      int i = 3;
    
      while (i) {
        printf("%d은 참입니다.\n", i);
        i--;
      }
    
      printf("%d은 거짓입니다.\n", i);
    
      return 0;
    }

/*문제6*/
/*1부터n까지의 합*/
    #include <stdio.h>
    
    int main() {
      int n = 0;
      int cnt;
      int sum = 0;
    
        printf("몇까지 더할까?\n");
        scanf("%d", &n);
    
      for (cnt = 1; cnt <= n; cnt++) {
        sum += cnt;
      }
    
      printf("%d까지의 합: %d\n", n, sum);
      return 0;
    }

    /*while로 변환*/
    #include <stdio.h>
    
    int main() {
      int n = 0;
      int cnt = 1;
      int sum = 0;
    
      printf("몇까지 더할까?\n");
      scanf("%d", &n);
    
      while (cnt <= n) {
        sum += cnt;
        cnt++;
      }
    
      printf("%d까지의 합: %d\n", n, sum);
      return 0;
    }

/*문제7*/
/*구구단 출력프로그램*/
    /*세로*/
    #include <stdio.h>
    
    int main() {
        int i;
        int j;
    
        for(j=1; j<=9; j++) {
          for(i = 1; i <= 9; i++) {
            printf("%d x %d = %d\n", j, i, j*i);
          }
          printf("\n");
       }
      
        return 0;
    }

    /*가로*/
    #include <stdio.h>
    
    int main() {
        int i;
        int j;
        
        for(i = 1; i <= 9; i++) {
            for(j = 1; j <= 9; j++) {
                printf("%d x %d = %d   ", j, i, j * i);
            }
            printf("\n");
        }
        
        return 0;
    }
