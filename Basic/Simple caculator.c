//滿額折扣
#include <stdio.h>
int main () {
    //第一種
    /*
    int num, ans;
    printf("Enter number of customers: ");
    scanf("%d", &num);
    if (num >= 10){
        ans = num * 300 * 0.8;
    }
    if (num < 10){
        ans = num * 300;    
    }
    printf("The price is: %d\n", ans);
    return 0;
    */
    //第二種
    /*
    int num, total, original;
    printf("Enter number of customers: ");
    scanf("%d", &num);
    original = num * 300;
    if (original >= 3000){
        total = original * 0.8;
    }
    if (original < 3000){
        total = original;    
    }
    printf("The price is: %d\n", total);
    return 0;
    */
    //第三種
    int num, total;
    printf("Enter number of customers: ");
    scanf("%d", &num);
    total = num * 300;
    if (total >= 3000){
        total = total * 0.8;
    }
    printf("The price is: %d\n", total);
    return 0;
}