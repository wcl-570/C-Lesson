#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>

//函式
//除以二的函式
double div2(double x) {
    return x/2;
} 

int main () {
    int N;
    scanf("%d", &N);
    printf("%f\n", div2(N));
    return 0;
}
//或者
double div2(double);

int main () {
    int N;
    scanf("%d", &N);
    printf("%f\n", div2(N));
    return 0;
}

double div2(double x) {
    return x/2;
}

//計算平方根
int main () {
    int N;
    printf("N = ");
    scanf("%d", &N);
    printf("%f\n", sqrt(N));
    return 0;
}

//對兩個變數求最大值
int max (int, int);

int main () {
    int a, b;
    printf("Enter a: ");
    scanf("%d", &a);
    printf("Enter b: ");
    scanf("%d", &b);
    printf("Max is %d\n", max(a, b));
    return 0;
}

int max(int x, int y) {//此函式的參數與主函式的無關
    if (x >= y) {
        return x;
    } else {
        return y;
    }
}

//對三個變數求最大值
int max1 (int, int, int);

int main () {
    int a, b, c;
    printf("Enter three intrgers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("The max is %d\n", max1(a, b, c));
    return 0;
}

int max1(int x, int y, int z) {
    int max = x;
    if (y > max) {
        return y;
    } else if (z > max) {
        return z;
    } else {
        return max;
    }
}

//利用max幫助判斷三個變數大小
int max (int, int);
int max1 (int, int, int);

int main () {
    int a, b, c;
    printf("Enter three intrgers: ");
    scanf("%d %d %d", &a, &b, &c);
    printf("The max is %d\n", max1(a, b, c));
    return 0;
}

int max1(int x, int y, int z) {
    return max(max(x, y), z);
}

int max(int x, int y) {
    if (x >= y) {
        return x;
    } else {
        return y;
    }
}

//用文字繪製三角形
void printf_stars(int);
void printf_triangle(int);

int main () {
    int n;
    printf("N = ");
    scanf("%d", &n);
    printf_triangle(n);
    return 0;
}

void printf_triangle(int n) {
    int i;
    for (i = 1; i <= n; ++i) {
        printf_stars(i);
        printf("\n");
    }
}

void printf_stars(int i) {//void作為回傳值，表示此函式不回傳任何值
    int j;
    for (j = 1; j <= i; ++j) {
        printf("*");
    }
    //當回傳值為void時，可以省略return;
}

//亂數生成：5個亂數
int main () {
    srand(time(0));//time(0)回傳目前時間，srand()用來設定亂數種子
    int i;
    for (i = 1; i <= 5; ++i) {
        printf("%d\n", rand());//每次呼叫rand()就會回傳一個隨機產生的亂數
    }
    return 0;
}

//擲骰子：模擬五次擲骰子
//第一種
int main () {
    srand(time(0));
    int i;
    for (i = 1; i <= 5; i++) {
        int dice;
        do {
            dice = rand();
        } while (dice < 1 || dice > 6);
        printf("%d\n", dice);
    }
    return 0;
}
//第二種
int main () {
    srand(time(0));
    int i;
    for (i = 1; i <= 5; i++) {
        //rand() % 6會產生0~5的亂數，+1後會產生1~6的亂數，對應骰子的點數
        int dice = rand() % 6 + 1;
        print("%d\n", dice);
    }
    return 0;
}

//猜數字
int main () {
    srand(time(0));
    int num = rand() % 100;
    int guess;

    do {
        printf("Enter your guess: ");
        scanf("%d", &guess);
        if (guess > num) {
            printf("Too large!\n");
        } else if (guess < num) {
            printf("Too small!\n");
        } else {
            printf("Correct!\n");
        }
    } while (guess != num);
    return 0;
}