#include <stdio.h>
int main () {
    //正三角形判斷：三邊等長
    /*
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a == b)
        if (b == c) {//if (a == b && b == c)也可以
            printf("Regular triangle\n");
    }
    */
    //等腰三角形判斷：有兩邊一樣長
    /*
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a == b || a == c || b == c) {
        printf("Isosceles triangle\n");
    }
    */
    //直角三角形判斷：兩邊長的平方和等於第三邊的平方
    /*
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a * a + b * b == c * c ||
        a * a + c * c == b * b ||
        b * b + c * c == a * a) {
        printf("Rectangular triangle\n");
    }
    */
    //三角形種類判斷
    /*
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a == b && b == c){
        printf("Regular triangle\n");
    }
    if (a == b || a == c || b == c) {
        printf("Isosceles triangle\n");
    }
    if (a * a + b * b == c * c ||
        a * a + c * c == b * b ||
        b * b + c * c == a * a) {
        printf("Rectangular triangle\n");
    }
    */
    //由小到大
    int a, b, c;
    printf("Please enter the lengths(from small to large): ");
    scanf("%d%d%d", &a, &b, &c);
    if (a == c){
        printf("Regular triangle\n");
    }
    if (a == b || b == c) {
        printf("Isosceles triangle\n");
    }
    if (a * a + b * b == c * c) {
        printf("Rectangular triangle\n");
    }
    return 0;
}