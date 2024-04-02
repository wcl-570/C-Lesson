#include <stdio.h>
int main () {
    //對兩個變數求最大值
    //第一種
    /*
    int a, b, max;
    printf("Enter first integer: ");
    scanf("%d", &a);
    printf("Enter second integer: ");
    scanf("%d", &b);
    if (a >= b){
        max = a;
    }
    if (a < b){
        max = b;
    }
    printf("The maximum is %d.\n", max); 
    */
    //第二種
    /*
    int a, b, max;
    printf("Enter first integer: ");
    scanf("%d", &a);
    printf("Enter second integer: ");
    scanf("%d", &b);
    max = a;
    if (max < b){
        max = b;
    }
    printf("The maximum is %d.\n", max);
    */
    //對三個變數求最大值
    //第一種
    /*
    int a, b, c, max;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a >= b && a >= c){
        max = a;
    }
    if (b > a && b >= c){
        max = b;
    }
    if (c > a && c > b){
        max = c;
    }
    printf("The maximum is %d. \n", max);
    */
    //第二種
    /*
    int a, b, c, max;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    max = a;
    if (b > max){
        max = b;
    }
    if (c > max){
        max = c;
    }
    printf("The maximum is %d.\n", max);
    */
    //對四個變數求最大值
    //第一種
    /*
    int a, b, c, d, max;
    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a >= b && a >= c && a >= d) {
        max = a;
    }
    if (b > a && b >= c && b >= d) {
        max = b;
    }
    if (c > a && c > b && c >= d) {
        max = c;
    }
    if (d > a && d > b && d > c) {
        max = d;
    }
    printf("The maximum is %d.\n", max);
    */
    //第二種
    /*
    int a, b, c, d, max;
    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    max = a;
    if (b > a && b >= c && b >= d) {
        max = b;
    }
    if (c > a && c > b && c >= d) {
        max = c;
    }
    if (d > a && d > b && d > c) {
        max = d;
    }
    printf("The maximum is %d.\n", max);
    */
    //第三種
    int a, b, c, d, max;
    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    if (d > max) {
        max = d;
    }
    printf("The maximum is $d.\n", max);
    return 0;
}