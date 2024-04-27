#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//陣列
//骰子點數出現統計：模擬擲六千次骰子，分別顯示點數1到6出現的次數
//一般做法
int main () {
    srand(time(0));
    int count1 = 0;
    int count2 = 0;
    int count3 = 0;
    int count4 = 0;
    int count5 = 0;
    int count6 = 0;
    int i;
    for (i = 1; i <= 6000; ++i) {
        int dice = rand() % 6 + 1;
        switch (dice) {
            case 1: count1++; break;
            case 2: count2++; break;
            case 3: count3++; break;
            case 4: count4++; break;
            case 5: count5++; break;
            case 6: count6++; break;
        }    
    }
    printf("1: %d\n", count1);
    printf("2: %d\n", count2);
    printf("3: %d\n", count3);
    printf("4: %d\n", count4);
    printf("5: %d\n", count5);
    printf("6: %d\n", count6);
    return 0;
}
//陣列做法
int main () {
    srand(time(0));
    int counter[6] = {0};
    int i;
    for (i = 1; i <= 6000; ++i) {
        int dice = rand() % 6 + 1;
        switch (dice) {
            case 1: counter[0]++; break;
            case 2: counter[1]++; break;
            case 3: counter[2]++; break;
            case 4: counter[3]++; break;
            case 5: counter[4]++; break;
            case 6: counter[5]++; break;
        }
    }
    printf("1: %d\n", counter[0]);
    printf("2: %d\n", counter[1]);
    printf("3: %d\n", counter[2]);
    printf("4: %d\n", counter[3]);
    printf("5: %d\n", counter[4]);
    printf("6: %d\n", counter[5]);
    return 0;
}

//循序存取陣列元素
int main () {
    srand(time(0));
    int counter[6] = {0};
    int i, j;
    for (i = 1; i <= 6000; ++i) {
        int dice = rand() % 6 + 1;
        for (j = 1; j <= 6; ++j) {//j是骰子點數
            if (dice == j) {//如果骰子點數等於j
                counter[j-1]++;//元素j-1的值加1
            }
        }
    }
    for (j = 1; j <= 6; ++j) {
        printf("%d: %d\n", j, counter[j-1]);//counter[j-1]是第j點出現的次數
    }
    return 0;
}

//隨機存取陣列元素
int main () {
    srand(time(0));
    int counter[6] = {0};
    int i, j;
    for (i = 1; i <= 6000; ++i) {
        int dice = rand() % 6 + 1;
            counter[dice-1]++;//dice-1對應到元素，假設dice是1，則counter[0]加1
        }
    for (j = 1; j <= 6; ++j) {
        printf("%d: %d\n", j, counter[j-1]);
    }
    return 0;
}

//消費金額計算
int main () {
    int prices[5] = {90, 75, 83, 89, 71};
    int total = 0;
    int id, i;
    do {
        scanf("%d", &id);
        total += prices[id-1];//id-1對應到價格，假設id是1，則prices[0]是90
    } while (id != 0);
    printf("Total: %d\n", total);
    return 0;
}
//考慮到輸入0的問題
int main () {
    int prices[5] = {90, 75, 83, 89, 71};
    int total = 0;
    int id, i;
    while (1) {
        scanf("%d", &id);
        if (id == 0) {//如果輸入0，則跳出迴圈
            break;
        }
        total += prices[id-1];
    }
    printf("Total: %d\n", total);
    return 0;
}

//兩顆骰子點數和出現次數統計
//擲100000次，每次擲兩顆骰子，統計點數和出現的次數
int main () {
    srand(time(0));
    int counter[12] = {0};
    int i, j;
    for (i = 1; i <= 100000; ++i) {
        int dice = rand() % 12 + 2;
            counter[dice-1]++;
        }
    for (j = 2; j <= 12; ++j) {
        printf("%d: %d\n", j, counter[j-1]);
    }
    return 0;
}

//查詢數字
//輸入5個整數後，可以依照輸入的順序號碼查詢所輸入的整數（查詢順序號碼為0則結束）
int main () {
    int i, num[5];
    for (i = 1; i <= 5; i++) {//i:輸入順序編號
        printf("%d: ", i);
        scanf("%d", &num[i-1]);
    }
    
    while (1) {
        printf("Q: ");
        scanf("%d", &i);
        if (i == 0) {
            break;
        }
        printf("%d\n", num[i-1]);
    }
    return 0;
}

//查詢範圍內數字
//輸入10個整數，輸入要查詢的上下界後，顯示包含在上下限內的整數
//輸入0 0則結束
int main () {
    int i, num[10];
    
    for (i = 1; i <= 10; i++) {
        scanf("%d", &num[i-1]);//代表第幾個數字
    }
    
    while (1) {
        int l, r;
        printf("L R: ");
        scanf("%d%d", &l, &r);
        if (l == 0 && r == 0) {
            break;
        }
        printf("Ans: ");
        for (i = 0; i < 10; i++) {
            if (num[i] >= l && num[i] <= r) {
                printf("%d ", num[i]);//代表第幾號元素
            }
        }
        printf("\n");
    }
    return 0;
}

//查詢上限內最大數字
//輸入10個整數，輸入要查詢的數字後，顯示輸入的整數中最接近的一個
//輸入0則結束
int main () {
    int i, num[10], q;
    
    for (i = 1; i <= 10; i++) {
        scanf("%d", &num[i-1]);
    }
    
    while (1) {
        int max_i = -1;
        printf("Q: ");
        scanf("%d", &q);
        if (q == 0) {
            break;
        }
        for (i = 0; i < 10; i ++) {
            //max_i == -1代表是第一個就要換掉
            //num[i] > num[max_i]非第一個但是比原本最大還大
            if (num[i] <= q && (max_i == -1 || num[i] > num[max_i])) {
                max_i = i;
            }
        }
        if (max_i != -1) {
            printf("%d\n", num[max_i]);
        }
    }
    return 0;
}

//查詢最接近數字
//輸入10個整數，輸入要查詢的數字後，顯示輸入的整數中最接近的一個
//有兩個以上結果，則顯示最小的那個
//輸入0則結束
int main () {
    int i, num[10], q;
    
    for (i = 1; i <= 10; i++) {
        scanf("%d", &num[i-1]);
    }
    
    while (1)
    {
        printf("Q: ");
        scanf("%d", &q);
        int nearest_n = num[0], nearest_d = abs(q-num[0]);
        if (q == 0) {
            break;
        }
        for (i = 1; i < 10; i++) {
            int d = abs(q-num[i]);
            //d < nearest_d代表新的比原本最近的還近
            //d == nearest_d && num[i] < nearest_n代表新的一樣近但是比原本的數字小
            if (d < nearest_d || (d == nearest_d && num[i] < nearest_n)) {
                nearest_d = d;
                nearest_n = num[i];
            }
        }
        printf("%d\n", nearest_n);
    }
    return 0;
}

//畫數字統計長條圖
//輸入10個1~100的整數，畫出以10分為區間的長條圖
int main () {
    int i, j, n, b[10] = {0};
    
    for (i = 1; i <= 10; i++) {
        scanf("%d", &n);
        b[(n-1)/10]++;//n-1除以10代表第幾個計數器（b[0]~b[9]）
    }
    for (i = 1; i <= 10; i++) {
        printf("%3d: ", i*10);//%3d代表顯示3個字元
        //j <= b[i-1]：假設b[0] = 3，j <= 3，代表顯示3個*
        for (j= 1; j <= b[i-1]; j++) {
            printf("*");
        }
        printf("\n");
    }
    return 0;
}

//求小範圍內的眾數
//輸入10個0~9的整數，輸出眾數
//當有一樣多的眾數時，輸出最大的
int main () {
    int i, n, a[10] = {0};
    for (i = 0; i <= 9; i++) {
        scanf("%d", &n);//n代表投票箱編號
        a[n]++;//a[n]++代表加一票
    }

    int ans = 0;//ans代表出現次數最多的數字
    for (n = 0; n <= 9; n++) {
        //如果目前的數字n出現次數大於或等於目前已知的最大次數（a[ans]），則更新ans為n
        if (a[n] >= a[ans]) {
            ans = n;
        }
    }
    printf("Ans: %d\n", ans);
    return 0;
}

//數字統計
//輸入10個整數，輸出最大與平均值
int max10(int a[10]);
float avg10(int a[10]);

int main () {
    int i, a[10] = {0};
    for (i = 0; i <= 9; i++) {
        scanf("%d", &a[i]);
    }
    printf("Max: %d\n", max10(a));
    printf("Avg: %f\n", avg10(a));
    return 0;
}

int max10(int a[10]) {
    int max = a[0];
    for (int i = 0; i <= 9; i++) {
        if (a[i] > max) {
            max = a[i];
        }
    }
    return max;
}

float avg10(int a[10]) {
    float sum;
    for (int i = 0; i <= 9; i++) {
        sum = sum + a[i];
    } 
    return sum / 10;
}

//陣列排序
//將陣列的元素依照一定的規則改變前後順序
//泡沫排序法：小到大
int main () {
    int i, a[4] = {0};
    for (i = 0; i <= 4; i++) {
        scanf("%d", &a[i]);
    }
    
    for (int j = 1; j <= 4; j++) {
        for (int i = 0; i <= 4; i++) {//可以寫成i <= 4-j
        if (a[i] < a[i-1]) {//如果左邊比右邊大就交換
            int x = a[i];
            a[i] = a[i-1];
            a[i-1] = x;   
            }   
        }
    }
    
    for (int i = 0; i <= 4; i++) {
        printf("%d ", a[i]);
    }
    return 0;
}

//用二維陣列表示九宮格
//第一種
int main () {
    int v[3][3] = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };

    int i, j;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//第二種
int main () {
    int v[3][3], i, j, k = 1;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            v[i][j] = k;//k是計數器，從1開始
            k++;
        }
    }
    
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    return 0;
}

//用一維陣列表示九宮格
int main () {
    int v[9], i, k = 1;
    for (i = 0; i < 9; i++) {
            v[i] = k;
            k++;
        }
    
    for (i = 0; i < 9; i++) {
            printf("%d ", v[i]);
            if (i % 3 ==2) {
                printf("\n");
            }
        }
    return 0;
}

//隨機生成九宮格
//二維陣列
int main () {
    srand(time(0));
    int v[3][3] = {(1, 2, 3), (4, 5, 6), (7, 8, 9)};
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            //i=0, j=0的時候隨機找一格交換
            //i=0, j=1的時候從剩下的8格隨機找一格交換
            int r = rand() % (9-k) + k;//剩下還有幾格的索引號
            int m = r / 3;//反推出是第幾列
            int n = r % 3;//反推出是第幾行
            int t = v[i][j];
            v[i][j] = v[m][n];
            v[m][n] = t;
            k++;
        }
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf("%d ", v[i][j]);
        }
        printf("\n");
    }
    return 0;
}
//一維陣列
int main () {
    srand(time(0));
    int v[9] = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    int i;
    for (i = 0; i < 9; i++) {
        //i=0的時候隨機找一格交換
        //i=1的時候從剩下的8格隨機找一格交換
        int m = rand() % (9-i) + i;//剩下還有幾格的索引號
        int t = v[i];
        v[i] = v[m];
        v[m] = t;
    }
    for (i = 0; i < 9; i++) {
        printf("%d ", v[i]);
        if (i % 3 == 2) {
            printf("\n");
        }
    }
    return 0;
}