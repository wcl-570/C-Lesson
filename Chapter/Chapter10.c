#include <stdio.h>

//break和continue述句
//break述句
int main () {
    int num;
    for (num = 1; num <= 10; num++) {
      if (num == 5) {
        break;
      }
      printf("%d\n", num);//只會印出1,2,3,4
    }
  }

//韓信點兵：終止重複執行
int main () {
    int max;
    printf("Max = ");
    scanf("%d", &max);

    int num;
    for (num = max; num >= 1; --num) {//ans==0表示還沒找到符合條件的值
        if (num % 3 == 2 && num % 5 == 3 && num % 7 == 2) {
            break;//找到符合條件的值就終止迴圈
        }
    }
    printf("%d\n", num);
    return 0;
}

//continue述句
int main () {
    int num;
    for (num = 1; num <= 10; ++num) {
      if (num == 5) {
        continue;
      }
      printf("%d\n", num);//不會印出5
    }
}