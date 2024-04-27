#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include<limits.h>

//指標
//兩個變數數值交換
void swap(int *, int *);

int main () {
    int a = 3, b = 5;
    swap(&a, &b);
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    return 0; 
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//兩個變數的排序
//試寫一函式sort，將輸入的兩個整數變數依值排序（大到小）
void swap(int *, int *);
void sort(int *, int *);

int main () {
    int a = 5, b = 3;
    sort(&a, &b);
    printf("a: %d\n", a);
    printf("b: %d\n", b);
    return 0; 
}

void sort(int *a,int *b) {
    if (*a > *b) {
        swap(a, b);//&*抵銷
    }
}

void swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

//兩個數的最大值
int max(int *, int *);

int main () {
    int a = 3, b = 5;
    printf("Max: %d\n", max(&a, &b));
    return 0;
}

int max(int *a, int *b) {
    if (*a > *b) {
        return *a;
    } else {
        return *b;
    }
}

//讓使用者輸入任意個整數後，將所有輸入的整數一起印出（輸入0結束）
int main () {
    int num[10];//儲存輸入的數字
    int length = 0;//目前已輸入的數字個數
    while (length < 10) {//最多輸入10個數字
        int input;
        scanf("%d", &input);//從鍵盤輸入數字
        if (input == 0) break;//輸入0結束
        num[length] = input;//將輸入數字加在最後面
        length++;//將輸入的數字個數加1
    }
    
    printf("Numbers: ");
    for (int i = 0; i < length; i++) {//數每個輸入的數字
        printf("%d ", num[i]);
    }
    printf("\n");
    return 0;
}