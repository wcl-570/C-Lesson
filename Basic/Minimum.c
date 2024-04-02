#include <stdio.h>
int main () {
    //對兩個變數求最小值
    //第一種
    /*
    int a, b, min;
    printf("Enter two intrgers: ");
    scanf("%d%d", &a, &b);
    if (a <= b) {
        min = a;
    }
    if (a > b) {
        min = b;
    }
    printf("The minimum is %d.\n", min);
    */
    //第二種
    /*
    int a, b, min;
    printf("Enter two intrgers: ");
    scanf("%d%d", &a, &b);
    min = a;
    if (a > b) {
        min = b;
    }
    printf("The minimum is %d.\n", min);
    */
    //對三個變數求最小值
    //第一種
    /*
    int a, b, c, min;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a <= b && a <= c) {
        min = a;
    }
    if (b < a && b <= c) {
        min = b;
    }
    if (c < a && c < b) {
        min = c;
    }
    printf("The minimum is %d.\n", min);
    */
    //第二種
    int a, b, c, min;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    min = a;
    if (b < a && b <= c) {
        min = b;
    }
    if (c < a && c < b) {
        min = c;
    }
    printf("The minimum is %d.\n", min);
    return 0;
}