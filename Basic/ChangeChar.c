//大小寫轉換
#include <stdio.h>
int main(){
    char input, output;
    printf("請輸入一個字元:");
    scanf("%c", &input);
    output = input + 32;
    printf("%c\n", output);
    return 0;
}