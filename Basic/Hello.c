#include <stdio.h>

int main() {
    //換行'\n'
    printf("Hello\n");
    printf("World\n");
    //雙引號'\"'
    printf("Hello \"C\" World\n");
    //反斜線'\\'
    printf("Hello\\nWorld\n");
    //單引號'\''
    printf("Hello\'World\n");
    //跳位'\t'
    printf("Hello \tWorld\n");
    //練習，可讀性
    printf("H     H     A\n");
    printf("H     H    A A\n");
    printf("HHHHHHH   A   A\n");
    printf("H     H  AAAAAAA\n");
    printf("H     H  A     A\n");
    //單行寫法
    printf("H     H     A\nH     H    A A\nHHHHHHH   A   A\nH     H  AAAAAAA\nH     H  A     A\n");
    //也可以這樣
    printf("H     H     A\n"
           "H     H    A A\n"
           "HHHHHHH   A   A\n"
           "H     H  AAAAAAA\n"
           "H     H  A     A\n");
    return 0;//return 0 to indicate successful completion
}