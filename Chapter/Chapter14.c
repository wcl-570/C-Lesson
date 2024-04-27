#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//亂數的產生
//產生不重複亂數
//隨機產生一組由10個1到10之間的數字所組成的序列，序列裡不能有重複的數字
int main () {
    srand(time(0));
    int i, j, v[10]; //int used

    for (i = 1; i <= 10; i++) {
        do {
            v[i-1] = rand() % 10 + 1;
            //used = 0;//used=0代表v[i-1]還沒出現過
            //從1檢查到i，代表檢查到前一個即可確認v[i-1]是否已經出現過
            for (j = 1; j < i; j++) {
                if (v[i-1] == v[j-1]) {//如果v[i-1]已經出現過
                    //used = 1;//v[i-1]出現過則將used設為1
                    break;//結束for迴圈
                }
            }//此時假設j=i，代表v[i-1]還沒出現過；假設j<i，代表v[i-1]已經出現過
        } while (j != i);//}while(used == 1)//如果v[i-1]已經出現過
        printf("%d ", v[i-1]);
    }
    printf("\n");
    return 0;
}
//用建表法產生不重複亂數
int main () {
    srand(time(0));
    int i, n, counter[10] = {0}; //counter統計1~10出現的次數

    for (i = 1; i <= 10; i++) {
        do {
            n = rand() % 10 + 1;
        } while (counter[n-1] != 0);//counter[n-1]不等於0代表已經出現過
        printf("%d ", n);
        counter[n-1]++;
    }
    printf("\n");
    return 0;
}
//用交換法產生不重複亂數
int main () {
    srand(time(0));
    int i, a[10];
    for (i = 1; i <= 10; i++) {
        a[i-1] = i;
    }
    for (i = 1; i <= 10; i++) {
        int j = rand() % (11-i) + i;//(11-i)代表每交換一次範圍就少一個數字
        //將第i個與第j個交換
        int t = a[i-1];
        a[i-1] = a[j-1];
        a[j-1] = t;
        printf("%d ", a[i-1]);
    }
    printf("\n");
    return 0;
}

//實作亂數生成：線性同餘法（Linear Congruential Generator）
//Xn+1=(Xn*1104515245+12345)%4294967296
int main () {
    //設定為無號整數，溢位後等於除以UINT_MAX+1的餘數
    unsigned int next = 1;

    for (int i = 1; i <= 5; i++) {
        next = next * 1103515245 + 12345;
        int rand = (unsigned int)(next / 65536) % 32768;//只取高位部分讓他更亂
        printf("%u\n", rand);
    }
    return 0;
}

//自定義亂數函式
int rand(void) {
    //使用靜態區域變數
    static unsigned int next = 1;
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}
int main () {
    for (int i = 1; i <= 5; i++) {
        printf("%u\n", rand());
    }
    return 0;
}
//使用全域變數
unsigned int next = 1;
int rand(void) {
    next = next * 1103515245 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}
void srand(unsigned int seed) {
    next = seed;
}
int main () {
    srand(time(0));
    for (int i = 1; i <= 5; i++) {
        printf("%u\n", rand());
    }
    return 0;
}
//使用特定命名方式
unsigned int _next = 1;
int _rand(void) {
    _next = _next * 1103515245 + 12345;
    return (unsigned int)(_next / 65536) % 32768;
}
void _srand(unsigned int seed) {
    _next = seed;
}
int main () {
    _srand(time(0));
    for (int i = 1; i <= 5; i++) {
        printf("%u\n", _rand());
    }
    return 0;
}
//使用靜態的全域變數：該名稱只有在該檔案中可以用
static unsigned int _next = 1;
int _rand(void) {
    _next = _next * 1103515245 + 12345;
    return (unsigned int)(_next / 65536) % 32768;
}
void _srand(unsigned int seed) {
    _next = seed;
}
int main () {
    _srand(time(0));
    for (int i = 1; i <= 5; i++) {
        printf("%u\n", _rand());
    }
    return 0;
}