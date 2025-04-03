/*문제6*/
/*1부터n까지의 합*/
    #include <stdio.h>
    
    int main() {
        int n = 0;
        int cnt;
        int sum = 0;
    
        scanf("%d", &n);
        printf("몇까지 더할까? %d\n", n);
        
        for(cnt = 1; cnt <= n; cnt++){
            sum = sum + cnt;
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
