#include<stdio.h>
int main(){
    int num1, num2, num3;
    printf("Enter first integer: ");
    scanf("%d", &num1);
    printf("Enter second integer: ");
    scanf("%d", &num2);
    printf("Enter third integer: ");
    scanf("%d", &num3);
    double avg = (num1 + num2 + num3)/3.;
    printf("Average: %f\n", avg);
    return 0;
}