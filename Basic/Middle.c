#include <stdio.h>
int main () {
    //對三個變數求中位數
    //第ㄧ種
    /*
    int a, b, c, mid;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    if (b <= a && a <= c || c <= a && a <= b) {
        mid = a;
    }
    if (a <= b && b <= c || c <= b && b <= a) {
        mid = b;
    }
    if (a <= c && c <= b || b <= c && c <= a ) {
        mid = c;
    }
    printf("The middle is %d.\n", mid);
    */
    //第二種
    int a, b, c, mid;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    mid = a;
    if (a <= b && b <= c || c <= b && b <= a) {
        mid = b;
    }
    if (a <= c && c <= b || b <= c && c <= a ) {
        mid = c;
    }
    printf("The middle is %d.\n", mid);
    return 0;
}