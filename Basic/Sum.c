//數字和
#include <stdio.h>
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