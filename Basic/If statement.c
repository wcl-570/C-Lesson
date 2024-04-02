#include <stdio.h>
  int main(){
    /*
    int a = 3;
    if(a > 4){
      printf("a is larger than 4.\n");//不會執行
    }
    int b = 5;
    if(b > 4){
      printf("b is larger than 4.\n");//會執行
    }
    int c;
    printf("c = ");
    scanf("%d", &c);
    if(c > 4){
        printf("c is larger than 4.\n");
    }
    */
    //大於、小於、等於
    int a = 5;//可以改變a的值
    if(a > 4){
        printf("a is larger than 4.\n");
    }
    if(a < 4){
        printf("a is smaller than 4.\n");
    }
    if(a == 4){//不能用「=」，要用「==」，因為「=」是指定值
        printf("a is equal to 4.\n");
    }
    return 0;
  }