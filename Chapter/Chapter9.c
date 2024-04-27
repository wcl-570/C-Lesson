#include <stdio.h>

//for述句
//印出1到10
int main () {
    for (int count = 1; count <= 10; count++) {
        printf("%d\n", count);
    }
    return 0;
}

//印出1到N
int main () {
    int N;
    printf("Enter a number: ");
    scanf("%d", &N);
    for (int num = 1; num <= N; num++) {
        printf("%d\n", num);
    }
    return 0;
}

//印出10到20
int main () {
    for (int count = 10; count <= 20; count++) {
        printf("%d\n", count);
    }
    return 0;
}

//印出M到N
int main () {
    int M, N;
    printf("Enter the number M: ");
    scanf("%d", &M);
    printf("Enter the number N: ");
    scanf("%d", &N);
    for (int count = M; count <= N; count++) {
        printf("%d\n", count);
    }
    return 0;
}

//印出10到1
//第一種
int main () {
    for (int count = 10; count <= 1; count--) {
        printf("%d\n", count);
    }
    return 0;
}
//第二種
int main () {
    for (int count = 10; count <= 1; count++) {
        int number = 11 - count;
        printf("%d\n", number);
    }
    return 0;
}

//印出1到10間的奇數
//第一種
int main () {
    for (int count = 1; count <= 10; count += 2) {
        printf("%d\n", count);
    }
}
//第二種
int main () {
    for (int count = 1; count <= 5; count ++) {
        int number = 2 * count - 1;
        printf("%d\n", number);
    }
}
//第三種
int main () {
    for (int count = 1; count <= 10; count ++) {
        if (count % 2 == 1) {//count除以2的餘數為1，即為奇數
            printf("%d\n", count);
        }
    }
}

//特定條件數列：印出1到10間不是三的倍數的偶數
//第一種
int main () {
    int count;
    for (count = 1; count <= 10; count++) {
        if (count % 2 == 0 && count % 3 != 0) {
            printf("%d\n", count);
        }
    }
    return 0;
}
//第二種
int main () {
    int count;
    for (count = 2; count <= 10; count += 2) {
        if (count % 3 != 0) {
            printf("%d\n", count);
        }
    }
    return 0;
}

//印出1加到100的整數和
int main () {
    int count;
    int total = 0;
    for (count = 1; count <= 100; count++) {
        total = total + count;    
    }
    printf("%d\n", total);
    return 0;
}

//求1加到N的整數和
//第一種
int main () {
    int i, N;
    int sum = 0;
    printf("Enter N: ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        sum = sum + i;
    }
    printf("%d\n", sum);
    return 0;
}
//第二種：公式
int main () {
    int N;
    printf("Enter N: ");
    scanf("%d", &N);
    int sum = (1 + N) * N / 2;
    printf("%d\n", sum);
    return 0;
}

//用文字畫橫線
int main () {
    int N, i;
    printf("Enter N: ");
    scanf("%d", &N);
    for (i = 1; i <= N; i++) {
        printf("*");
    }
    printf("\n");
    return 0;
}

//找出所有正因數
int main () {
    int N, num;
    printf("N: ");
    scanf("%d", &N);
    for (num = 1; num <= N; num++) {//列出可能的候選者
        if (N % num == 0) {//檢查合格條件
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}

//韓信點兵
//while述句
int main () {
    int num = 1;
    //不符合條件（num%3==2且num%5==3且num%7==2）時
    while (!(num % 3 == 2 && num % 5 == 3 && num % 7 == 2)) {
    //或是while (num % 3 != 2 || num % 5 != 3 || num % 7 != 2) {
        ++num;
    } 
    printf("%d\n", num);
    return 0;
}
//for述句
int main () {
    int num;
    for (num = 1; !(num % 3 == 2 && num % 5 == 3 && num % 7 == 2); ++num);
    printf("%d\n", num);
    return 0;
}
//有範圍的韓信點兵
//1到N
int main () {
    int max;
    printf("Max = ");
    scanf("%d", &max);
    
    int num;
    for (num = 1; num <= max; ++num) {
        if (num % 3 == 2 && num % 5 == 3 && num % 7 == 2) {
            printf("%d\n", num);
        }
    }
    printf("\n");
    return 0;
}
//上下限
//小到大
int main () {
    int max, min;
    printf("Min = ");
    scanf("%d", &min);
    printf("Max = ");
    scanf("%d", &max);
    
    int num;
    for (num = min; num <= max; ++num) {
        if (num % 3 == 2 && num % 5 == 3 && num % 7 == 2) {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}
//大到小
int main () {
    int max, min;
    printf("Min = ");
    scanf("%d", &min);
    printf("Max = ");
    scanf("%d", &max);
    int num;
    for (num = max; num >= min; --num) {
        if (num % 3 == 2 && num % 5 == 3 && num % 7 == 2) {
            printf("%d ", num);
        }
    }
    printf("\n");
    return 0;
}
//韓信點兵最大值
//while述句：效率較高
int main () {
    int max;
    printf("Max = ");
    scanf("%d", &max);
    
    int num = max;
    //小於23會不適用，所以要加上num>0
    while (num > 0 && !(num % 3 == 2 && num % 5 == 3 && num % 7 == 2)) {
        --num;
    }//while結束後，num可能是0或是符合條件的值
    if (num > 0) {
        printf("%d\n", num);
    }
    return 0;
}
//for述句：效率較低
//小到大
int main () {
    int max;
    printf("Max = ");
    scanf("%d", &max);

    int ans = 0;
    int num;
    for (num = 1; num <= max; ++num) {
        if (num % 3 == 2 && num % 5 == 3 && num % 7 == 2) {
            ans = num;//ans會存放最新找到的值
        }
    }//for迴圈結束後，ans可能是0或是符合條件的值
    if (ans != 0) {
        printf("%d\n", ans);
    }
    return 0;
}
//大到小
int main () {
    int max;
    printf("Max = ");
    scanf("%d", &max);

    int ans = 0;
    int num;
    for (num = max; num >= 1 && ans == 0; --num) {//ans==0表示還沒找到符合條件的值
        if (num % 3 == 2 && num % 5 == 3 && num % 7 == 2) {
            ans = num;
        }
    }
    if (ans != 0) {
        printf("%d\n", ans);
    }
    return 0;
}

//有次數的韓信點兵
//找出1到1000前三小的數字
int main () {
    int count = 0;
    int num;
    for (num = 1; num <= 1000 && count < 3; ++num) {
        if (num % 3 == 2 && num % 5 == 3 && num % 7 == 2) {
            ++count;
            if (count <= 3) {//只取前三個小的
                printf("%d ", num);
            }
        }
    }
    printf("\n");
    return 0;
}
//找出1到1000前三大的數字
int main () {
    int count = 0;
    int num;
    for (num = 1000; num >= 1 && count < 3; --num) {
        if (num % 3 == 2 && num % 5 == 3 && num % 7 == 2) {
            ++count;
            if (count <= 3) {
                printf("%d ", num);
            }
        }
    }
    printf("\n");
    return 0;
}
//找出1到1000第三小的數字
int main () {
    int count = 0;
    int num;
    for (num = 1; num <= 1000 && count < 3; ++num) {
        if (num % 3 == 2 && num % 5 == 3 && num % 7 == 2) {
            ++count;
            if (count == 3) {
                printf("%d ", num);
            }
        }
    }
    printf("\n");
    return 0;
}

//質數判斷
//第一種
int main () {
    int N;
    printf("Number = ");
    scanf("%d", &N);
    
    int numOfDivisors = 0;
    int num;
    for (num = 2; num < N; ++num) {
        if (N % num == 0) {
            ++numOfDivisors;//每次找到一個因數就加1
        }
    }

    if (numOfDivisors == 0) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
//第二種
int main () {
    int N;
    printf("Number = ");
    scanf("%d", &N);
    
    int isPrime = 1;
    int num;
    for (num = 2; num < N && isPrime; ++num) {
        if (N % num == 0) {
            isPrime = 0;//只要有一個因數就會變成0
        }
    }

    if (isPrime) {//也可以isPrime == 1
    //isPrime為1時，當作是布林值，代表是質數
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}
//第三種
int main () {
    int N;
    printf("Number = ");
    scanf("%d", &N);
    
    int num;
    for (num = 2; num < N && N % num != 0; ++num);//找到第一個因數就停止

    if (num == N) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
    return 0;
}

//九九乘法表
//第一種：九個for迴圈
int main () {
    int j;
    for (j =1; j <= 9; ++j) {
        printf("1 x %d = %d\n", j, 1 * j);
    }
    for (j =1; j <= 9; ++j) {
        printf("2 x %d = %d\n", j, 2 * j);
    }
    for (j =1; j <= 9; ++j) {
        printf("3 x %d = %d\n", j, 3 * j);
    }
    for (j =1; j <= 9; ++j) {
        printf("4 x %d = %d\n", j, 4 * j);
    }
    for (j =1; j <= 9; ++j) {
        printf("5 x %d = %d\n", j, 5 * j);
    }
    for (j =1; j <= 9; ++j) {
        printf("6 x %d = %d\n", j, 6 * j);
    }
    for (j =1; j <= 9; ++j) {
        printf("7 x %d = %d\n", j, 7 * j);
    }
    for (j =1; j <= 9; ++j) {
        printf("8 x %d = %d\n", j, 8 * j);
    }
    for (j =1; j <= 9; ++j) {
        printf("9 x %d = %d\n", j, 9 * j);
    }
    return 0;
}
//第二種：兩層for迴圈
int main () {
    int i, j;
    for (i = 1; i <= 9; ++i) {
        for (j = 1; j <= 9; ++j) {
            printf("%d x %d = %d\n", i, j, i * j);
        }
    }
    return 0;
}
//第三種：單層for迴圈
int main () {
    int c;
    for (c = 1; c < 81; ++c) {
        int i = c / 9 + 1;//c除以9的商
        int j = c % 9 + 1;//c除以9的餘數
        printf("%d x %d = %d\n", i, j, i * j);
    }
    return 0;
}

//用文字繪製長方形
int main () {
    int i, j;
    int n;
    printf("N = ");
    scanf("%d", &n);
    for (i = n; i <= n; ++i) {
        for (j = n; j <= n; ++j) {
            print("*");
        }
    }
    return 0;
}

//用文字繪製空心長方形
//第一種
int main () {
    int i, j;
    int n;
    printf("N = ");
    scanf("%d", &n);

    for (j = 1; j <= n; ++j) {
        printf("*");
    }
    printf("\n");
    
    //n-2是因為第一行和最後一行已經印過了
    for (i = 1; i <= n-2; ++i) {
        printf("*");//第一個星號
        for (j = 1; j <= n-2; ++j) {
            printf(" ");//中間空白
        }
        printf("*\n");//最後一個星號
    }

    for (j = 1; j <= n; ++j) {
        printf("*");
    }
    printf("\n");
    return 0;
}
//第二種
int main () {
    int i, j;
    int n;
    printf("N = ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            //第一行、最後一行、第一列、最後一列
            if (i == 1 || i == n || j == 1 || j == n) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

//用文字繪製三角形
int main () {
    int i, j;
    int n;
    printf("N = ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; ++i) {    
        for (j = 1; j <= i; ++j) {
            printf("*"); 
        }
        printf("\n");
    }    
    return 0;
}
//用文字繪製空心三角形
int main () {
    int n;
    printf("N = ");
    scanf("%d", &n);
    
    int i, j;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (j == 1 || i == n || i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

//基於座標法用文字繪製三角形
//座標法概念
int main () {
    int i, j;
    for (i = 1; i <= 5; ++i) {
        for (j = 1; j <= 5; ++j) {
            printf("(%d, %d)", i, j);
        }
        printf("\n");
    }
    return 0;
}
//實心三角形
//第一種：座標法
int main () {
    int n;
    printf("N = ");
    scanf("%d", &n);
    
    int i, j;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (i + j >=  n + 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
//第二種：填滿空格法
int main () {
    int n;
    printf("N = ");
    scanf("%d", &n);
    
    int i, j;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (i < j) {
                printf(" ");
            }
        }
        for (j = 1; j <= i; ++j) {
            printf("*"); 
        }
        printf("\n");
    }
    return 0;
}

//空心三角形
//第一種：座標法
int main () {
    int n;
    printf("N = ");
    scanf("%d", &n);
    
    int i, j;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (j == n || i == n || i + j == n + 1) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
//第二種：填滿空格法
int main () {
    int n;
    printf("N = ");
    scanf("%d", &n);
    
    int i, j;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (i < j) {
                printf(" ");
            }
        }
        for (j = 1; j <= n; ++j) {
            if (j == 1 || i == n || i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}
//另一種三角型
int main () {
    int n;
    printf("N = ");
    scanf("%d", &n);
    
    int i, j;
    for (i = 1; i <= n; ++i) {
        for (j = 1; j <= n; ++j) {
            if (i == 1 || j == n || i == j) {
                printf("*");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
    return 0;
}

//找簡易方程式整數解
//兩正整數相加為30，相乘為221，求此兩正整數
//第一種
int main () {
    int i, j;
    for (i = 1; i <= 15; ++i) {
        for (j = 15; j <= 30; ++j) {
            if (i + j == 30 && i * j == 221) {
                printf("%d, %d\n", i, j);
            }
        }
    }
    return 0;
}
//第二種
int main () {
    int i;
    for (i = 1; i <= 30; ++i) {
        if (i * (30 - i) == 221 && i <= (30 - i)) {
            printf("%d, %d\n", i, 30 - i);
        }
    }
    return 0;
}