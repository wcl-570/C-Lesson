# C語言
## 跳脫字元
- \n：換行
- \t：跳格
- \\：反斜線
- \'：單引號
- \"：雙引號
## 運算子
- &：取址運算子
## 撰寫程式考慮要點
- 正確性
- 維護性
- 可讀性
- 效率
  - 處理器的使用
  - 記憶體的使用
- 擴展性

# 第二章 資料型別（Data type）
- 資料處理的核心問題：
  - 記憶：資料如何儲存？
  - 計算：資料能做哪些運算？運算結果？
- 資料型別會決定這個資料要如何儲存與計算
## 資料儲存
- 電腦內部具有記憶儲存空間而該空間是以位元組（byte）為單位來組成
- 每個位元組（byte）有喔個位元構成（bit）
  - 一個位元一般由8個位元所構成（註：實際個數為「實作定義」）
  - 每個位元（bit）可以表示0或1兩種值
- 任何資料型別的資料都可以轉換成由一串0跟1所組成的序列來表示
## 常見資料型別（*表示大小為「實作定義」）
|資料型別|名稱|大小（位元組）|例子|
|:-:|:-:|:-:|:-:|
|短整數（short integer）|short int|2*|32|
|整數（integer）|int|4*|32|
|長整數（long integer）|long int|4*|32|
|字元（character）|char|1|'3'|
|單精度浮點數（single-precision floating point）|float|4*|3.2|
|倍精度浮點數（double-precision floating point）|double|8*|3.2|
|無|void|?||
## 使用sizeof看所佔記憶體空間大小
- 許多型別佔用的記憶體空間大小都是「實作定義」的，隨著使用的編譯器或者設定的不同而可能有異
  - 例如long int不一定是佔4個位元組，在某些64 bit的編譯器中，可能是8個位元組或其他大小
- 可以用sizeof運算子求出使用的編譯器上某個值或型別所佔用的記憶體大小（單位是位元組）
  ```c
  sizeof(long int);//sizeof會算出該值或型別佔用幾個位元組
  print("long int: %d\n", sizeof(long int));
  ```
## 定義變數
- 變數名稱在使用前，需要先宣告或定義
- 變數定義時需要指定名稱與型別：
  ```c
  //資料型別 變數名稱;
  int num;
  //也可以指定初始值，為初始化：
  int num = 0;
  ```
## 命名限制
- 名稱由英文大小寫字母、數字和底線構成，數字不能開頭，字母大小寫代表不同名稱
- 下列為保留字，不可作為命名得名稱：
  - auto, break, case, char, const, continue, default, do, double, else, enum, extern, float, for, goto, if, int, long, register, retrun, short, signrd, static, struct, switch, typedef, union, unsigned, void, volatile, while
## 不同資料型別間的差異
- 資料意涵不同：int and char
- 原理不同：int and float
- 值範圍不同：short int and long int
- 精確度不同：float and double
- 有無正負數的不同：int and unsigned int
## 2.1 整數型別
### 位元組可以儲存幾種可能？
- 一個位元組可以存256種不同的組合
  - 從0至255（無號數）
  - 從-128至127（有號數）
- 四個位元組可以存幾種可能？
  - 4個位元組＝32個位元
  - 32個位元可以存2x2x2x...x2（32個2連乘）＝4294967296種不同的組合＝4GB
  - 整數型別如果使用4個位元組來儲存，可表示4294967296種不同的整數
    - 從0到4294967295（無號整數：unsigned int）
    - 從-2147483648到2147483647（有號整數：signed int or int）
### 使用二進位表示法來表示整數（8個位元）
|值|二進位表示法|值|二進位表示法|值|二進位表示法|
|:-:|:-:|:-:|:-:|:-:|:-:|
|0|0000000|7|00000111|14|00001110|
|1|0000001|8|00001000|15|00001111|
|2|0000010|9|00001001|16|00010000|
|3|0000011|10|00001010|...|...|
|4|0000100|11|00001011|64|01000000|
|5|0000001|12|00001100|...|...|
|6|0000110|13|00001101|256|1111111|
### 整數的溢位（overflow）
- 大小為4個位元組的整數型別可以儲存將近十位數的整數
- 溢位表示數值運算的結果超過了原本型別可以型別可以表示的範圍
  - 可能造成未定義行為
### 大數問題
- 如果要處理的整數數值範圍比較大，可能要使用表示範圍比較大的整數型別
  - 佔用大小比較大的整數型別
  - 使用long int取代int
  - 還有long long int（C99後才有）
## 2.2 浮點數：可用來表示實數
- 實數表示法：約略值
- 一樣用4個位元組，整數二進位表示法範圍只能近10位數，而浮點數可以表示近40位數
- 想成是科學記號表示法
- 依然可能會溢位
### 有效數字
- 例如：圓周率取三位或四位或以上
- 位數越多，值越精確，需要記憶體也越多
## 2.3 將printf或scanf用在不同資料型別
### printf的使用：標準輸出的內建函式
```c
//使用時要給予想要輸出的字串
printf("Hello world!");
```
### printf的格式字串
- printf輸出的字串可以用類似跳脫字元的方法，放置一些「格式符」來輸出特定格式的資料
  ```c
  int sum = 10;
  printf("Sum is %d\n", sum);
  ```
- printf輸出整數時常見的格式符，以%作為跳脫記號，後面加上下表中的格式符代表要輸出的格式  
    |格式符|輸出格式|以輸出十進位的123為例|
    |:-:|:-:|:-:|
    |d或i|十進位有號整數|123|
    |u|十進位無號整數|123|
    |o|八進位無號整數|173|
    |x|十六進位無號整數（小寫）|7b|
    |X|十六進位無號整數（大寫）|7B|
- printf輸出不同格式的整數
  ```c
  int a = 123456789;
  unsigned int b = 3000000000;
  printf("%d\n", a);//123456789
  printf("%d\n", b);//-1294967296，溢位
  printf("%u\n", b);//3000000000
  printf("%u\n", a);//123456789，剛好一樣
  ```
- printf輸出浮點數時常見的格式符，以%作為跳脫記號，後面加上下表中的格式符代表要輸出的格式  
    |格式符|輸出格式|範例|
    |:-:|:-:|:-:|
    |f|十進位浮點數|123.45|
    |e|科學記號表示法（小寫）|1.234500e+02|
    |E|科學記號表示法（大寫）|1.234500E+02|
- printf輸出不同格式的浮點數
  ```c
  float a = 123.45;
  double b = 123.45;
  printf("%f\n", a);//123.449997
  printf("%f\n", b);//123.450000
  printf("%d\n", a);//2147483637
  printf("%d\n", b);//2147483637
  ```
### scanf的使用：標準輸入的內建函式
```c
//使用時要給予想要讀入的資料格式與變數位址
scanf("%d", &a);
```
### scanf的格式字串
- scanf輸出的字串可以用類似跳脫字元的方法，放置一些「格式符」來輸出特定格式的資料
  ```c  
  int sum = 10;
  printf("Sum is %d\n", sum);
  ```
- scanf讀取資料時常見的格式符，以%作為跳脫記號，後面加上下表中的格式符代表要輸出的格式  
    |格式符|輸出格式|範例|
    |:-:|:-:|:-:|
    |i|任何格式的整數|123|
    |d|十進位有號整數|123|
    |u|十進位無號整數|123|
    |f|十進位浮點數|123.45|
## 2.4 整數與浮點數型別間的轉換
### 算術運算的結果具有型別
- 做算術運算時，結果本身也必須被儲存，也會具有型別
  ```c
  int a = 3, b = 5;
  printf("Sum is %d.", a+b);
  ```
- 當兩個同樣整數或浮點數型別的值做運算時，結果也是同樣型別
### 字面常數
- 在程式碼中可以使用字面常數表示已知值的資料，字面常數一具有型別
  |常見字面常數|型別|
  |:-:|:-:|
  |123|int, long int|
  |123.45|double|
  |123.45f|float|
### 不一樣型別的值做算術運算的結果
- 當兩個不一樣整數或浮點數型別的值做算術運算時，如果可以算，會「隱性轉型」成範圍較大的型別並算出該型別的值
  - (int)+(float)->(float)+(float)->(float)
### 隱性轉型與顯性轉型
- 隱性轉型是當運算有需要時自動發生的
  ```c
  double average = (num1 + num2 + num3)/3.;
  ```
- 顯性轉型是當有需要時直接強加的
  ```c
  double average = (num1 + num2 + num3)/(double) 3;
  ```
## 2.5 字元型別簡介
### 儲存字元
- 將「字長什麼樣子」與「是哪個字」兩種資訊分開
  - 樣子
    - 字型
    - 需要輸出文字才需用到
  - 哪個字
    - 給每種字元獨一無二的編號
      - 編碼（encoding）
## 2.6 字元編碼簡介
### 字元有幾種可能？
- 英文鍵盤可以輸入的字元：
  - 英文字母（大小寫）：52
  - 數字（0-9）：10
  - 常用符號：20 ~ 30
  - 總共不到256種
- 只需一個位元組就可以表示
### C語言使用的字元編碼
- 實作定義
  - 一班常用是ASCII（American Standard Code for Information Interchange）
- 不管哪種編碼都必須包含大小寫英文字母、數字及常見符號
## 2.7 使用char字元型別
### 字元型別
- C主要有兩種字元型別
  - char
  - wchar_t
- 一般使用的是char，wchar_t則是使用在「寬字元」
  - char佔用的記憶體大小為1個位元組
  - 中文幾種可能？
    - 使用多個「char」或「wchar_t」表示
### char型別
- 特色
  - ASCII編碼
  - 一個位元組
  - 是一種「整數」型別
- 字面常數
  - 用一組單引號刮住：'A'、'a'、'1'、'\n'
- printf與scanf的格式符
  - 使用%c
- 範例：使用char型別
  ```c
  #include <stdio.h>
  int main(){
  char ch = 'A';
  printf("Character is %c\n", ch);
  return 0;
  }
  ```
## 2.8 如何對char型別做運算？
- 範例：使用char型別
  ```c
  #include <stdio.h>
  int main(){
  char ch = 'A' + 1;//B
  printf("Character is %c\n", ch);
  return 0;
  }
  ```
### char型別的算術運算
- char型別的變數可以做算術運算
  - 'A' + 1 得到 'B'
  - 'a' + 1 得到 'b'
  - 'A' - 1 得到 '@'
  - 'A' + '1' 得到 'r'
## 2.9 如何選擇資料型別？
|用途|選擇型別|注意事項|printf格式符|scanf格式符|
|:-:|:-:|:-:|:-:|:-:|
|整數|short int, int, long int|記憶體大小|%d, %i|%d, %i|
|浮點數|float, double|精確度|%f|%lf|
|字元|char|ASCII編碼|%c|%c|
# 第三章 運算與表示式
## 資料的儲存與處理
- 先前介紹了如何在電腦裡「儲存」（記憶）資料
- 現在要介紹如何在電腦裡「處理」（運算）資料
## 運算元、運算子與表示式
- 一次執行一個運算
- 運算子間有優先順序
## 3.1 整數與浮點數的算術運算
- 常見的算術運算
  |運算子|運算內容|整數|浮點數|範例|優先順序|
  |:-:|:-:|:-:|:-:|:-:|:-:|
  |+|加法|可|可|a + b|較低，由左至右|
  |-|減法|可|可|a - b|較低，由左至右|
  |*|乘法|可|可|a * b|較高，由左至右|
  |/|除法|可|可|a / b|較高，由左至右|
  |%|取餘數|可|不可|a % b|較高，由左至右|
## 3.2 賦值運算子「=」
- 將右方的值複製到左方的變數
  - 左方要放一個要改變變數
  - 左方變數值的改變是一種副作用
- 運算的結果是左方變數最後的型別跟值
  - 優先順序比大部分運算子低
  - 運算順序為由右至左
  ```c
  int a, c;
  double b, d;
  a = b = c = d = 3 + 7 / 2.;//a = 6, b = 6., c = 6, d = 6.5
  ```
## 3.3 如何表示是非對錯？
### 為何需要表示是非對錯？
- 流程控制
  - 有條件的執行程式碼
    - 條件成立時執行某段程式碼
    - 條件不成立時執行不要執行某段程式碼
  - 條件為何？
    - 如果「今天天氣很好」就「出去玩」
    - C語言中條件是用「表示式」來表示
    - 表示是算出來的值是「真」的時候表示條件成立，是「假」的時候表示條件不成立
### 如何表示是非對錯？
-  「是非」、「真假」、「對錯」都是二分型的資料
   - 共有兩種可能
   - 只需使用一個位元就可以表示
     - 1表示「真」（true）
     - 0表示「假」（false）
### 表示式的「真」與「假」
- 「非零」的值為「真」，「零」的值為「假」
  - 1為「真」
  - 0為「假」
  - -1為「真」
  - 2為「真」
  - 0.001為「真」
  - 'A'為「真」
  - '\0'為「假」
## 3.4 關係運算
- 等號與關係運算子
  |運算子|內容|範例|結果|
  |:-:|:-:|:-:|:-:|
  |>|大於|3 > 5|0|
  |<|小於|3 < 5|1|
  |==|等於|3 == 5|0|
  |!=|不等於|3 != 5|1|
  |>=|大於等於|3 >= 5|0|
  |<=|小於等於|3 <= 5|1|
- 3 > 2 > 1等同於1 > 1，但是1 > 1是錯的
## 3.5 邏輯運算
- 邏輯運算子
  |運算子|內容|範例|結果|優先級|
  |:-:|:-:|:-:|:-:|:-:|
  |&&|而且|3 > 2 && 2 > 1|1|「關係運算子」優先於「&&」|
  | \|\| |或|3 > 2 \|\| 2 > 1|1|「關係運算子」優先於「\|\|」|
  |!|非|!(3 > 2)|0|「!」優先於「關係運算子」|
  - ! (3 > 2) 相當於 3 <= 2
## 3.6 運算子的優先順序
|順序|運算子|算術類型|結合順序|運算元個數|
|:-:|:-:|:-:|:-:|:-:|
|1|!|邏輯運算|由右至左|一元運算子|
|2|* / %|算術運算|由左至右|二元運算子|
|3|+ -|算術運算|由左至右|二元運算子|
|4|> < <= >=|關係運算|由左至右|二元運算子|
|5|== !=|關係運算|由左至右|二元運算子|
|6|&&|邏輯運算|由左至右|二元運算子|
|7|\|\| |邏輯運算|由左至右|二元運算子|
|8|=|賦值運算|由右至左|二元運算子|
- 算術 > 關係 > 邏輯 > 賦值
- 「&&」優先於「\|\|」
- 大部分是由「左至右」，但是「一元運算子」是由右至左
# 第四章 程式流程控制
## 流程控制
- 無條件的執行一次（一般述句）
- 有條件的執行一次（if述句）
- 無條件的重複執行（無窮迴圈）
- 有條件的重複執行（while述句）
- 計次型的重複執行（for述句）
- 選擇性的執行（switch述句）
- 至少執行一次下有條件的重複執行（do-while述句）
- 使用頻率：if > while > for > switch > do-while
## 4.1  有條件的執行（if述句）
- if（表示式）{程式片段}
  - 如果「表示式」成立，就執行「程式片段」
## 4.2 猜數字
- 範例：
  ```c
  #include <stdio.h>
  int main(){
    int answer = 5;
    int guess;
    printf("Please enter your guess: ");
    scanf("%d", &guess);
    if(guess > answer){
        printf("Too large!\n");
    }
    if(guess < answer){
        printf("Too small!\n");
    }
    if(guess == answer){
        printf("Correct!\n");
    }
    return 0;
  }
  ```
## 4.3 滿額折扣
- 範例：
  ```c
  #include <stdio.h>
  int main () {
    //第一種
    int num, ans;
    printf("Enter number of customers: ");
    scanf("%d", &num);
    if (num >= 10){
        ans = num * 300 * 0.8;
    }
    if (num < 10){
        ans = num * 300;    
    }
    printf("The price is: %d\n", ans);
    //第二
    int num, total, original;
    printf("Enter number of customers: ");
    scanf("%d", &num);
    original = num * 300;
    if (original >= 3000){
        total = original * 0.8;
    }
    if (original < 3000){
        total = original;    
    }
    printf("The price is: %d\n", total);
    //第三種
    int num, total;
    printf("Enter number of customers: ");
    scanf("%d", &num);
    total = num * 300;
    if (total >= 3000){
        total = total * 0.8;
    }
    printf("The price is: %d\n", total);
    return 0;
  }
  ```
## 4.4 三角形判斷
- 範例：
  ```c
  #include <stdio.h>
  int main () {
    //正三角形判斷：三邊等長
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a == b)
        if (b == c) {//if (a == b && b == c)也可以
            printf("Regular triangle\n");
    }
    //等腰三角形判斷：有兩邊一樣長
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a == b || a == c || b == c) {
        printf("Isosceles triangle\n");
    }
    //直角三角形判斷：兩邊長的平方和等於第三邊的平方
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a * a + b * b == c * c ||
        a * a + c * c == b * b ||
        b * b + c * c == a * a) {
        printf("Rectangular triangle\n");
    }
    //三角形種類判斷
    int a, b, c;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a == b && b == c){
        printf("Regular triangle\n");
    }
    if (a == b || a == c || b == c) {
        printf("Isosceles triangle\n");
    }
    if (a * a + b * b == c * c ||
        a * a + c * c == b * b ||
        b * b + c * c == a * a) {
        printf("Rectangular triangle\n");
    }
    //由小到大
    int a, b, c;
    printf("Please enter the lengths(from small to large): ");
    scanf("%d%d%d", &a, &b, &c);
    if (a == c){
        printf("Regular triangle\n");
    }
    if (a == b || b == c) {
        printf("Isosceles triangle\n");
    }
    if (a * a + b * b == c * c) {
        printf("Rectangular triangle\n");
    }
    return 0;
  }
  ```
## 4.5 對變數求最大值
- 範例：
  ```c
  #include <stdio.h>
  int main () {
    //對兩個變數求最大值
    //第一種
    int a, b, max;
    printf("Enter first integer: ");
    scanf("%d", &a);
    printf("Enter second integer: ");
    scanf("%d", &b);
    if (a >= b){
        max = a;
    }
    if (a < b){
        max = b;
    }
    printf("The maximum is %d.\n", max); 
    //第二種
    int a, b, max;
    printf("Enter first integer: ");
    scanf("%d", &a);
    printf("Enter second integer: ");
    scanf("%d", &b);
    max = a;
    if (max < b){
        max = b;
    }
    printf("The maximum is %d.\n", max);
    //對三個變數求最大值
    //第一種
    int a, b, c, max;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a >= b && a >= c){
        max = a;
    }
    if (b > a && b >= c){
        max = b;
    }
    if (c > a && c > b){
        max = c;
    }
    printf("The maximum is %d. \n", max);
    //第二種
    int a, b, c, max;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    max = a;
    if (b > max){
        max = b;
    }
    if (c > max){
        max = c;
    }
    printf("The maximum is %d.\n", max);
    */
    //對四個變數求最大值
    //第一種
    int a, b, c, d, max;
    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    if (a >= b && a >= c && a >= d) {
        max = a;
    }
    if (b > a && b >= c && b >= d) {
        max = b;
    }
    if (c > a && c > b && c >= d) {
        max = c;
    }
    if (d > a && d > b && d > c) {
        max = d;
    }
    printf("The maximum is %d.\n", max);
    //第二種
    int a, b, c, d, max;
    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    max = a;
    if (b > a && b >= c && b >= d) {
        max = b;
    }
    if (c > a && c > b && c >= d) {
        max = c;
    }
    if (d > a && d > b && d > c) {
        max = d;
    }
    printf("The maximum is %d.\n", max);
    //第三種
    int a, b, c, d, max;
    printf("Enter four integers: ");
    scanf("%d%d%d%d", &a, &b, &c, &d);
    max = a;
    if (b > max) {
        max = b;
    }
    if (c > max) {
        max = c;
    }
    if (d > max) {
        max = d;
    }
    printf("The maximum is $d.\n", max);
    return 0;
  }
  ```
## 4.6 對變數求最小值
- 範例：
  ```c
  #include <stdio.h>
  int main () {
    //對兩個變數求最小值
    //第一種
    int a, b, min;
    printf("Enter two intrgers: ");
    scanf("%d%d", &a, &b);
    if (a <= b) {
        min = a;
    }
    if (a > b) {
        min = b;
    }
    printf("The minimum is %d.\n", min);
    //第二種
    int a, b, min;
    printf("Enter two intrgers: ");
    scanf("%d%d", &a, &b);
    min = a;
    if (a > b) {
        min = b;
    }
    printf("The minimum is %d.\n", min);
    //對三個變數求最小值
    //第一種
    int a, b, c, min;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a <= b && a <= c) {
        min = a;
    }
    if (b < a && b <= c) {
        min = b;
    }
    if (c < a && c < b) {
        min = c;
    }
    printf("The minimum is %d.\n", min);
    //第二種
    int a, b, c, min;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    min = a;
    if (b < a && b <= c) {
        min = b;
    }
    if (c < a && c < b) {
        min = c;
    }
    printf("The minimum is %d.\n", min);
    return 0;
  }
  ```
## 4.7 對三個變數求中位數
- 範例：
  ```c
  #include <stdio.h>
  int main () {
    //對三個變數求中位數
    //第ㄧ種
    int a, b, c, mid;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    if (b <= a && a <= c || c <= a && a <= b) {
        mid = a;
    }
    if (a <= b && b <= c || c <= b && b <= a) {
        mid = b;
    }
    if (a <= c && c <= b || b <= c && c <= a ) {
        mid = c;
    }
    printf("The middle is %d.\n", mid);
    //第二種
    int a, b, c, mid;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    mid = a;
    if (a <= b && b <= c || c <= b && b <= a) {
        mid = b;
    }
    if (a <= c && c <= b || b <= c && c <= a ) {
        mid = c;
    }
    printf("The middle is %d.\n", mid);
    return 0;
  }
  ```
- 中位數與最大最小值差異？
  - 求三個整數的中位數
  - 複雜度的概念
  - 為什麼最大最小值「好像」有比較簡單的解法？
    - 求三個整數的最大值「相當於」先求兩個整數的最大值後再與第三個整數比大
