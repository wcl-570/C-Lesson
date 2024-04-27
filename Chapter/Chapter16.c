#include <stdio.h>

//字串
//字元與字元陣列
void str_print(char str[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main () {
    char str[] = {
        'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd'
    };
    str_print(str, 11);
    return 0;
}
//字串與字元陣列
void str_print(char str[]) {
    int i;
    for (i = 0; str[i] != '\0'; i++) {
        printf("%c", str[i]);
    }
    printf("\n");
}

int main () {
    char str[] = {//也可以char str[] = "Hello";
        'H', 'e', 'l', 'l', 'o', '\0'//傳統方式
    };
    str_print(str);
    return 0;
}

//計算字串長度
int str_len(char str[]) {
    //回傳第一個'\0'的位置
    int i = 0;
    while (str[i] != '\0') {
        i++;
    }
    return i;
}

int main () {
    char str[] = "Hello world";
    //等於'H', 'e', 'l', 'l', 'o', ' ', 'w', 'o', 'r', 'l', 'd', '\0'
    printf("Length: %zu\n", sizeof(str));
    printf("Length: %d\n", str_len(str));
    return 0;
}

//從鍵盤輸入讀入一行字
//讓使用者輸入一行文字後，將輸入的文字重現印出
//第一種
int main () {
    char ch;
    scanf("%c", &ch);
    while (ch != '\n') {
        printf("%c", ch);
        scanf("%c", &ch);
    }
    return 0;
}
//第二種
void str_read(char[]);

int main () {
    char str[15];//限制長度
    str_read(str);
    printf("%s\n", str);
    return 0;
}

void str_read(char str[]) {
    int i = 0;
    while (1) {
        scanf("%c", &str[i]);
        if (str[i] == '\n')//遇到換行字元（Enter）就停止
            break;
        i++;    
    }
    str[i] = '\0';
}