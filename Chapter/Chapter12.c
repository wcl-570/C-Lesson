#include <stdio.h>

//函式遞迴
//數數字：印出1到3
void countTo3(int);

int main () {
    countTo3(1);
    return 0;
}

void countTo3(int i) {
    if (i <= 3) {
        printf("%d\n", i);
        countTo3(i + 1);
    }
}
//印出3到1
//第一種
void countTo1(int);

int main () {
    countTo1(3);
    return 0;
}

void countTo1(int i) {
    if (i >= 1) {
        printf("%d\n", i);
        countTo1(i - 1);
    }
}
//第二種
void countTo1(int);

int main () {
    countTo1(1);//呼叫countTo1函式
    return 0;
}

void countTo1(int i) {
    if (i <= 3) {
        countTo1(i + 1);//開始遞迴
        printf("%d\n", i);
    }
}

//連續整數和：印出1到N的和
//第一種：for迴圈
int sum(int);

int main () {
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);
    printf("%d\n", sum(N));
    return 0;
}

int sum(int N) {
    int sum = 0;
    int i;
    for (i = 1; i <= N; i++) {
        sum = sum + i;    
    }
    return sum;
}
//第二種：遞迴
//n = 1, sum(1) = 1; n > 1, sum(n) = sum(n-1) + n
int sum(int);

int main () {
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);
    printf("%d\n", sum(N));
    return 0;
}

int sum(int N) {
    if (N == 1) {
        return 1;
    }
    return sum(N - 1) + N;
}

//費波那契數列：f(1) = 1, f(2) = 1, f(n) = f(n-1) + f(n-2)
//上樓梯方法數
int s(int);

int main () {
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);
    printf("%d\n", s(N));
    return 0;
}

int s(int N) {
    if (N <= 2) {
        return N;
    }
    return s(N - 1) + s(N - 2);
}