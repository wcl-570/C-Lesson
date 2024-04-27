#include <stdio.h>

//if-else述句
int main () {
    int grade;
    printf("Enter the grade: ");
    scanf("%d", &grade);
    if (grade >= 60) {
        printf("Pass!\n");
    } else { 
        printf("Fail!\n");
    }
    return 0;
}

//比大小
int main () {
    int a, b;
    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);
    if (a > b) {
        printf("a > b\n");
    } else if (a < b) {
        printf("b > a\n");
    } else {
        printf("a = b\n");
    }
    return 0;
}

//猜數字
int main () {
    int ans = 69;
    int guess;
    printf("Guess a number: ");
    scanf("%d", &guess);
    if (guess > ans) {
        printf("Too large!\n");
    } else if (guess < ans) {
        printf("Too small!\n");
    } else {
        printf("Correct!\n");
    }
    return 0;
}

//簡易四則運算
int main () {
    int a, b;
    char op;
    float ans;
    scanf("%d%c%d", &a, &op, &b);
    if (op == '+') {
        ans = a + b;
    } else if (op == '-') {
        ans = a - b;
    } else if (op == '*') {
        ans = a * b;
    } else {
        ans = (float) a / b;
    }
    printf("ANS: %f\n", ans);
    return 0;
}

//對多個變數求最大值
//兩個變數
int main () {
    int a, b, max;
    printf("Enter two integers: ");
    scanf("%d%d", &a, &b);
    if (a >= b) {
        max = a;
    } else {
        max = b;
    }
    printf("The maximumu is %d.\n", max);
    return 0;
}
//三個變數
int main () {
    int a, b, c, max;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }
    printf("The maximum is %d.\n", max);
    return 0;
}