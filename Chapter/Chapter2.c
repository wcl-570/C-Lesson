#include <stdio.h>

//大小寫轉換
int main(){
    char input, output;
    printf("請輸入一個字元:");
    scanf("%c", &input);
    output = input + 32;
    printf("%c\n", output);
    return 0;
}

//平均值
int main(){
    int num1, num2, num3;
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);
    printf("Enter third integer: ");
    scanf("%d", &num3);
    double avg = (num1 + num2 + num3)/3.;
    printf("Average: %f\n", avg);
    return 0;
}