#include <stdio.h>

//while述句
//猜數字
//第一種
int main () {
    int num = 69;
    int guess;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    while (guess != num) {
        if (guess > num) {
            printf("Too large!\n");
        } else {
            printf("Too small!\n");
        }
        printf("Enter your guess: ");
        scanf("%d", &guess);
    }       
    printf("Correct!\n");
    return 0;
}
//第二種
int main () {
    int num = 69;
    int guess;
    int count = 0;
    while (count == 0 || guess != num) {//count == 0是為了猜第一次數字
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count = count + 1;
        if (guess > num) {
            printf("Too large!\n");
        } else {
            printf("Too small!\n");
        }
    }
    printf("Correct!\n");
    return 0;
}

//計算出猜了幾次
int main () {
    int num = 69;
    int guess;
    int count = 0;
    printf("Enter your guess: ");
    scanf("%d", &guess);
    count = count + 1;
    while (guess != num) {
        if (guess > num) {
            printf("Too large!\n");
        } else {
            printf("Too small!\n");
        }
        printf("Enter your guess: ");
        scanf("%d", &guess);
        count = count + 1;
    }       
    printf("Correct! (%d)\n", count);
    return 0;
}

//求不定個數正整數的總和
int main () {
    int num;
    int sum = 0;
    printf("Enter the numbers:(0: quit) ");
    scanf("%d", &num);
    while (num != 0) {
        sum = sum + num;
        scanf("%d", &num);
    }
    printf("The sum is %d\n", sum);
    return 0;
}

//求不定個數正整數平均的練習
int main () {
    int num;
    int sum = 0;
    float average;
    int count = 0;
    printf("Enter the numbers:(0: quit) ");
    scanf("%d", &num); 
    count = count + 1;
    while (num != 0) {
        sum = sum + num;
        count = count + 1;
        scanf("%d", &num);
    }
    if (num == 0) {
        printf("The average is N/A\n");
        return 0;
    }
    average = (float)sum / count;
    printf("The average is %f\n", average);
    return 0;
}

//印出1到10
int main () {
    int num = 0;
    while (num < 10) {
        num = num + 1;
        printf("%d\n", num);
    }
    return 0;
}

//印出1到N
int main () {
    int N;
    int num = 0;
    printf("Enter number: ");
    scanf("%d", &N);
    while (num < N) {
        num = num + 1;
        printf("%d\n", num);
    }
    return 0;
}

//印出10到20
int main () {
    int num = 10;
    while (num <= 20) {
        printf("%d\n", num);
        num = num + 1;
    }
    return 0;
}

//印出M到N
int main () {
    int M, N;
    printf("Enter number M: ");
    scanf("%d", &M);
    printf("Enter number N: ");
    scanf("%d", &N);
    while (M <= N) {
        printf("%d\n", M);
        M = M + 1;
    }
    return 0;
}