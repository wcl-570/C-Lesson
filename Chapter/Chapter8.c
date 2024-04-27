#include <stdio.h>

//do-while述句
//猜數字
int main () {
    int num = 69;
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

//消費金額計算
int main () {
    int total = 0;
    int id;
    do {
        scanf("%d", &id);//至少要輸入一次
        switch (id) {
            case 1: total += 90; break;
            case 2: total += 75; break;
            case 3: total += 83; break;
            case 4: total += 89; break;
            case 5: total += 71; break;
        }
    } while (id != 0);
    printf("Total: %d\n", total);
    return 0;
}