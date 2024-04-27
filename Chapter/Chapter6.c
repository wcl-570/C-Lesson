#include <stdio.h>

//switch述句
//簡易四則運算
int main () {
    int a, b;
    char op;
    float ans;
    scanf("%d%c%d", &a, &op, &b);
    switch (op) {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = (float) a / b;
        break;
    }
    printf("ANS: %f\n", ans);
    return 0;
}

//ID查詢
int main () {
    int id;
    printf("Enter ID number: ");
    scanf("%d", &id);
    switch (id) {
    case 2:
        printf("John\n");
        break;
    case 13:
        printf("Mary\n");
        break;
    case 16:
        printf("Amy\n");
        break;
    default:
        printf("Not found\n");
    }
    return 0;
}