#include <stdio.h>

//printf()的使用
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
    return 0;//return 0表示程式執行成功
}

//數字和
//寫法一
int main() {
    int integer1, integer2, integer3, sum;
    printf("Enter first integer:\n");
    scanf("%d", &integer1);
    printf("Enter second integer:\n");
    scanf("%d", &integer2);
    printf("Enter third integer:\n");
    scanf("%d", &integer3);
    sum = integer1 + integer2 + integer3;
    printf("Sum is %d\n", sum);
    return 0;
}
//寫法二
int main() {
    int integer, sum;
    printf("Enter first integer:\n");
    scanf("%d", &integer);
    sum = integer;
    printf("Enter second integer:\n");
    scanf("%d", &integer);
    sum = sum + integer;
    printf("Enter third integer:\n");
    scanf("%d", &integer);
    sum = sum + integer;
    printf("Sum is %d\n", sum);
    return 0;
}

//數值交換
#include <stdio.h>
//寫法一
int main() {
    int integer1, integer2;
    printf("Enter first integer:\n");
    scanf("%d", &integer1);
    printf("Enter second integer:\n");
    scanf("%d", &integer2);

    //change number
    int temp = integer1;
    integer1 = integer2;
    integer2 = temp;

    printf("integer1: %d\n", integer1);
    printf("integer2: %d\n", integer2);
    return 0;
}
//寫法二
int main() {
    int integer1, integer2;
    printf("Enter first integer:\n");
    scanf("%d", &integer1);//3
    printf("Enter second integer:\n");
    scanf("%d", &integer2);//5

    //change number
    integer1 = integer1 + integer2;//3+5=8
    integer2 = integer1 - integer2;//8-5=3
    integer1 = integer1 - integer2;//8-3=5

    printf("integer1: %d\n", integer1);
    printf("integer2: %d\n", integer2);
    return 0;
}
//寫法三
int main() {
    int integer1, integer2;
    printf("Enter first integer:\n");
    scanf("%d", &integer1);//3
    printf("Enter second integer:\n");
    scanf("%d", &integer2);//5

    //change number
    integer1 = integer1 ^ integer2;//3^5=6
    integer2 = integer1 ^ integer2;//6^5=3
    integer1 = integer1 ^ integer2;//6^3=5

    printf("integer1: %d\n", integer1);
    printf("integer2: %d\n", integer2);
    return 0;
}