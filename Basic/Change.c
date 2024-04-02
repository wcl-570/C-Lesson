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