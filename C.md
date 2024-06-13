# 第一章 C語言
## 直譯器
- 直譯器（interpreter）
  - 可以將程式碼一行一行的讀取並執行，佔用的記憶體較少，然而執行速度較慢
  - 例如：BASIC
- 編譯器（compiler）
  - 可以將程式碼一次編譯成機器碼，執行速度較快，但是佔用的記憶體較多
  - 例如：C
## 撰寫程式考慮要點
- 正確性
- 維護性
- 可讀性
- 效率
  - 處理器的使用
  - 記憶體的使用
- 擴展性
# 第二章 資料型態（Data type）
- 資料處理的核心問題：
  - 記憶：資料如何儲存？
  - 計算：資料能做哪些運算？運算結果？
- 資料型態會決定這個資料要如何儲存與計算
## 資料儲存
- 電腦內部具有記憶儲存空間而該空間是以位元組（byte）為單位來組成
- 每個位元組（byte）有喔個位元構成（bit）
  - 一個位元一般由8個位元所構成（註：實際個數為「實作定義」）
  - 每個位元（bit）可以表示0或1兩種值
- 任何資料型態的資料都可以轉換成由一串0跟1所組成的序列來表示
## 常見資料型態（*表示大小為「實作定義」）
|資料型態|名稱|大小（位元組）|例子|
|:-:|:-:|:-:|:-:|
|短整數（short integer）|short int|2*|32|
|整數（integer）|int|4*|32|
|長整數（long integer）|long int|4*|32|
|字元（character）|char|1|'3'|
|單精度浮點數（single-precision floating point）|float|4*|3.2|
|倍精度浮點數（double-precision floating point）|double|8*|3.2|
|無|void|?||
## 使用sizeof看所佔記憶體空間大小
- 許多型態佔用的記憶體空間大小都是「實作定義」的，隨著使用的編譯器或者設定的不同而可能有異
  - 例如long int不一定是佔4個位元組，在某些64 bit的編譯器中，可能是8個位元組或其他大小
- 可以用sizeof運算子求出使用的編譯器上某個值或型態所佔用的記憶體大小（單位是位元組）
  ```c
  sizeof(long int);//sizeof會算出該值或型態佔用幾個位元組
  print("long int: %d\n", sizeof(long int));
  ```
## 定義變數
- 變數名稱在使用前，需要先宣告或定義
- 變數定義時需要指定名稱與型態：
  ```c
  //資料型態 變數名稱;
  int num;
  //也可以指定初始值，為初始化：
  int num = 0;
  ```
## 命名限制
- 名稱由英文大小寫字母、數字和底線構成，數字不能開頭，字母大小寫代表不同名稱
- 下列為保留字，不可作為命名得名稱：
  - auto, break, case, char, const, continue, default, do, double, else, enum, extern, float, for, goto, if, int, long, register, retrun, short, signrd, static, struct, switch, typedef, union, unsigned, void, volatile, while
## 不同資料型態間的差異
- 資料意涵不同：int and char
- 原理不同：int and float
- 值範圍不同：short int and long int
- 精確度不同：float and double
- 有無正負數的不同：int and unsigned int
## 2.1 整數型態
### 位元組可以儲存幾種可能？
- 一個位元組可以存256種不同的組合
  - 從0至255（無號數）
  - 從-128至127（有號數）
- 四個位元組可以存幾種可能？
  - 4個位元組＝32個位元
  - 32個位元可以存2x2x2x...x2（32個2連乘）＝4294967296種不同的組合＝4GB
  - 整數型態如果使用4個位元組來儲存，可表示4294967296種不同的整數
    - 從0到4294967295（無號整數：unsigned int）
    - 從-2147483648到2147483647（有號整數：signed int or int）
### 使用二進位表示法來表示整數（8個位元）
|值|二進位表示法|值|二進位表示法|值|二進位表示法|
|:-:|:-:|:-:|:-:|:-:|:-:|
|0|0000000|7|00000111|14|00001110|
|1|0000001|8|00001000|15|00001111|
|2|0000010|9|00001001|13|00010000|
|3|0000011|10|00001010|...|...|
|4|0000100|11|00001011|64|01000000|
|5|0000001|12|00001100|...|...|
|6|0000110|13|00001101|256|1111111|
### 整數的溢位（overflow）
- 大小為4個位元組的整數型態可以儲存將近十位數的整數
- 溢位表示數值運算的結果超過了原本型態可以型態可以表示的範圍
  - 可能造成未定義行為
### 大數問題
- 如果要處理的整數數值範圍比較大，可能要使用表示範圍比較大的整數型態
  - 佔用大小比較大的整數型態
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
## 2.3 將printf或scanf用在不同資料型態
### 2.3.1 printf的使用：標準輸出的內建函式
```c
//使用時要給予想要輸出的字串
printf("Hello world!");
```
### 2.3.2 printf的格式字串
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
    |o|八進位無號整數|143|
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
### 2.3.3 scanf的使用：標準輸入的內建函式
```c
//使用時要給予想要讀入的資料格式與變數位址
scanf("%d", &a);
```
### 2.3.4 scanf的格式字串
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
- 讀取字元常見錯誤
  ```c
  int main () {
    int num;
    char ch;

    printf("Enter a number: ");
    scanf("%d", &num);
    printf("Enter a character: ");
    scanf("%c", &ch);//需要在%c前加上一個空白字元，因為scanf會讀取上一個輸入的換行字元
    scanf(" %c", &ch);//正確的寫法
    printf("num = %d, ASCII of ch = %d\n", num, ch);

    return 0;
  }
  ```
### 2.3.5 清除緩衝區的資料
- 利用fflush(stdin);可以清除緩衝區的資料
  ```c
  int main () {
    int num;
    char ch;

    printf("Enter a number: ");
    scanf("%d", &num);
    fflush(stdin);//清除緩衝區的資料
    printf("Enter a character: ");
    scanf("%c", &ch);
    printf("num = %d, ASCII of ch = %d\n", num, ch);

    return 0;
  }
  ```
## 2.4 整數與浮點數型態間的轉換
### 算術運算的結果具有型態
- 做算術運算時，結果本身也必須被儲存，也會具有型態
  ```c
  int a = 3, b = 5;
  printf("Sum is %d.", a+b);
  ```
- 當兩個同樣整數或浮點數型態的值做運算時，結果也是同樣型態
### 字面常數
- 在程式碼中可以使用字面常數表示已知值的資料，字面常數一具有型態
  |常見字面常數|型態|
  |:-:|:-:|
  |123|int, long int|
  |123.45|double|
  |123.45f|float|
### 不一樣型態的值做算術運算的結果
- 當兩個不一樣整數或浮點數型態的值做算術運算時，如果可以算，會「隱性轉型」成範圍較大的型態並算出該型態的值
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
## 2.5 字元型態簡介
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
## 2.7 使用char字元型態
### 字元型態
- C主要有兩種字元型態
  - char
  - wchar_t
- 一般使用的是char，wchar_t則是使用在「寬字元」
  - char佔用的記憶體大小為1個位元組
  - 中文幾種可能？
    - 使用多個「char」或「wchar_t」表示
### char型態
- 特色
  - ASCII編碼
  - 一個位元組
  - 是一種「整數」型態
- 字面常數
  - 用一組單引號刮住：'A'、'a'、'1'、'\n'
- printf與scanf的格式符
  - 使用%c
- 範例：使用char型態
  ```c
  #include <stdio.h>
  int main() {
    char ch = 'A';
    printf("Character is %c\n", ch);
    return 0;
  }
  ```
## 2.8 如何對char型態做運算？
- 範例：使用char型態
  ```c
  #include <stdio.h>
  int main() {
    char ch = 'A' + 1;//B
    printf("Character is %c\n", ch);
    return 0;
  }
  ```
### char型態的算術運算
- char型態的變數可以做算術運算
  - 'A' + 1 得到 'B'
  - 'a' + 1 得到 'b'
  - 'A' - 1 得到 '@'
  - 'A' + '1' 得到 'r'
## 2.9 如何選擇資料型態？
|用途|選擇型態|注意事項|printf格式符|scanf格式符|
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
- 運算的結果是左方變數最後的型態跟值
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
## 3.7 複合賦值運算子
|運算子|意義|範例|相等於|
|:-:|:-:|:-:|:-:|
|+=|加等於|a += 2|a = a + 2|
|-=|減等於|a -= 2|a = a - 2|
|*=|乘等於|a *= 2|a = a * 2|
|/=|除等於|a /= 2|a = a / 2|
|%=|取餘等於|a %= 2|a = a % 2|
## 3.8 遞增遞減運復職
|運算子|意義|範例|對a相等於|運算結果|
|:-:|:-:|:-:|:-:|:-:|
|++|遞增|a++|a = a + 1|a原本的值|
|++|遞增|++a|a = a + 1|a加1後的值|
|--|遞減|a--|a = a - 1|a原本的值|
|--|遞減|--a|a = a - 1|a減1後的值|
- 範例：
  ```c
  int a = 0;
  int b;
  b = ++a;//a = 1, b = 1
  b = a++;//a = 2, b = 1
  a = a++;//未定義行為
  ```
# 第四章 有條件的執行（if述句）
## 程式流程控制
- 無條件的執行一次（一般述句）
- 有條件的執行一次（if述句）
- 無條件的重複執行（無窮迴圈）
- 有條件的重複執行（while述句）
- 計次型的重複執行（for述句）
- 選擇性的執行（switch述句）
- 至少執行一次下有條件的重複執行（do-while述句）
- 使用頻率：if > while > for > switch > do-while
## 4.1  有條件的執行（if述句）
- if (表示式) {程式片段}
  - 如果「表示式」成立，就執行「程式片段」
## 4.2 猜數字
- 範例：
  ```c
  int main() {
    int answer = 5;
    int guess;
    printf("Please enter your guess: ");
    scanf("%d", &guess);
    if(guess > answer) {
      printf("Too large!\n");
    }
    if(guess < answer) {
      printf("Too small!\n");
    }
    if(guess == answer) {
      printf("Correct!\n");
    }
    return 0;
  }
  ```
## 4.3 滿額折扣
- 範例：
  ```c
  int main() {
    //第一種
    int num, ans;
    printf("Enter number of customers: ");
    scanf("%d", &num);
    if (num >= 10) {
      ans = num * 300 * 0.8;
    }
    if (num < 10) {
      ans = num * 300;    
    }
    printf("The price is: %d\n", ans);
    //第二種
    int num, total, original;
    printf("Enter number of customers: ");
    scanf("%d", &num);
    original = num * 300;
    if (original >= 3000) {
      total = original * 0.8;
    }
    if (original < 3000) {
      total = original;    
    }
    printf("The price is: %d\n", total);
    //第三種
    int num, total;
    printf("Enter number of customers: ");
    scanf("%d", &num);
    total = num * 300;
    if (total >= 3000) {
      total = total * 0.8;
    }
    printf("The price is: %d\n", total);
    return 0;
  }
  ```
## 4.4 三角形判斷
- 範例：
  ```c
  int main() {
    //正三角形判斷：三邊等長
    int side1, side2, side3;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &side1, &side2, &side3);
    if (side1 == side2)
      if (side2 == side3) {//if (side1 == side2 && side2 == side3)也可以
        printf("Regular triangle\n");
    }
    //等腰三角形判斷：有兩邊一樣長
    int side1, side2, side3;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &side1, &side2, &side3);
    if (side1 == side2 || side1 == side3 || side2 == side3) {
      printf("Isosceles triangle\n");
    }
    //直角三角形判斷：兩邊長的平方和等於第三邊的平方
    int side1, side2, side3;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &side1, &side2, &side3);
    if (side1 * side1 + side2 * side2 == side3 * side3 ||
        side1 * side1 + side3 * side3 == side2 * side2 ||
        side2 * side2 + side3 * side3 == side1 * side1) {
      printf("Rectangular triangle\n");
    }
    //三角形種類判斷
    int side1, side2, side3;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &side1, &side2, &side3);
    if (side1 == side2 && side2 == side3){
      printf("Regular triangle\n");
    }
    if (side1 == side2 || side1 == side3 || side2 == side3) {
      printf("Isosceles triangle\n");
    }
    if (side1 * side1 + side2 * side2 == side3 * side3 ||
        side1 * side1 + side3 * side3 == side2 * side2 ||
        side2 * side2 + side3 * side3 == side1 * side1) {
      printf("Rectangular triangle\n");
    }
    //由小到大
    int side1, side2, side3;
    printf("Please enter the lengths(from small to large): ");
    scanf("%d%d%d", &side1, &side2, &side3);
    if (side1 == side3) {
      printf("Regular triangle\n");
    }
    if (side1 == side2 || side2 == side3) {
      printf("Isosceles triangle\n");
    }
    if (side1 * side1 + side2 * side2 == side3 * side3) {
      printf("Rectangular triangle\n");
    }
    return 0;
  }
  ```
## 4.5 對變數求最大值
- 範例：
  ```c
  int main() {
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
## 4.8 對多個變數排序
- 排序
  - 將資料依照某種順序排列
    - 由大到小
    - 由小到大
  - 處理後產生具有某種順序的資料序列
    - 找最大值
    - 找最小值
    - 找中位數
    - 找第K大的值
- 對兩個變數依照大小排序
  - 範例：
    ```c
    int main () {
    //對兩個變數依照大小排序：使用數值交換的做法
    //由小到大
    int a, b, temp;
    scanf("%d%d", &a, &b);
    printf("Before: %d %d\n", a, b);
    if (a > b) {
      temp = a;
      a = b;
      b = temp;
    }
    printf("After: %d %d\n", a, b);
    return 0;
    }
    ```
- 三個變數的數值交換（ABC->CAB）
  - 利用賦值順序的調整來達成
  - 使用兩次兩個變數的數值交換
  - 範例：
    ```c
    #include <stdio.h>
    int main () {
    //對兩個變數依照大小排序：使用數值交換的做法
    //由小到大
    int a, b, temp;
    scanf("%d%d", &a, &b);
    printf("Before: %d %d\n", a, b);
    if (a > b) {
        temp = a;
        a = b;
        b = temp;
    }
    printf("After: %d %d\n", a, b);
    //對三個變數依照大小排序：賦值順序調整
    int a = 2, b = 4, c = 6, t;
    printf("Before: %d %d %d\n", a, b, c);
    t = a;
    a = b;
    b = c;
    c = t;
    printf("After: %d %d %d\n", a, b, c);
    //使用兩次兩個變數的數值交換
    int a = 2, b = 4, c = 6, t;
    printf("Before: %d %d %d\n", a, b, c);
    //將a和c交換
    t = a;
    a = c;
    c = t;
    //將b和c交換
    t = b;
    b = c;
    c = t;
    printf("After: %d %d %d\n", a, b, c);
    return 0;
    }
    ```
## 4.9 對三個變數依照大小排序
- 由小到大排序
- 變數間可能的大小順序關係：變成a, b, c
  - a <= b <= c：不用任何處理
  - a <= c < b：c與b做數值交換(a, c, b)->(a, b, c)
  - b < a <= c：b與a做數值交換(b, a, c)->(a, b, c)
  - b <= c < a：b, c, a做數值交換(b, c, a)->(a, b, c)
  - c < a <= b：c, a, b做數值交換(c, a, b)->(a, b, c)
  - c < b < a：c與a做數值交換(c, b, a)->(a, b, c)
  - 範例：
    ```c
    int main () {
      //對三個變數按照大小排序（a, b, c）
      int a, b, c, t;
      scanf("%d%d%d", &a, &b, &c);
      printf("Before: %d %d %d \n", a, b, c);
      if (a < c && c < b) {
        //c與b做數值交換：(a, c, b)->(a, b, c)
        t = b; b = c; c = t;
      }
      if (b < a && a < c) {
        //b與a做數值交換：(b, a, c)->(a, b, c)
        t = a; a = b; b = t;
      }
      if (b < c && c < a) {
        //b, c, a做數值交換：(b, c, a)->(a, b, c)
        t = a; a = b; b = c; c = t;
      }
      if (c < a && a < b) {
        //c, a, b做數值交換：(c, a, b)->(a, b, c)
        t = a; a = c; c = b; b = t;
      }
      if (c < b && b < a) {
        //c與a做數值交換：(c, b, a)->(a, b, c)
        t = a; a = c; c = t;
      }
      printf("After: %d %d %d\n", a, b, c);
      return 0;
    }
    ```
## 4.10 用兩個變數的數值交換對三個變數排序
- 由小到大排序
- 變數間可能的大小順序關係：變成a, b, c
  - a <= b <= c：不用任何處理
  - a <= c < b：c與b做數值交換(a, c, b)->(a, b, c)
  - b < a <= c：b與a做數值交換(b, a, c)->(a, b, c)
  - b <= c < a：b與a做數值交換，c與b做數值交換(b, c, a)->(a, b, c)
  - c < a <= b：c與a做數值交換，c與b做數值交換(c, a, b)->(a, b, c)
  - c < b < a：c與a做數值交換(c, b, a)->(a, b, c)
  - 範例：
    ```c
    //用兩個變數的數值交換對三個變數做排序（a, b, c）
    int main () {  
      int a, b, c, t;
      scanf("%d%d%d", &a, &b,&c);
      printf("Before: %d %d %d\n", a, b, c);
      if (b < a && a <= c || b <= c && c < a) {
        //b與a做數值交換：(b, a, c)->(a, b, c) 
        t = b, b = a, a = t;
      }
      if (c < a && a <=b || c < b && b <= a) {
        //c與a做數值交換：(c, b, a)->(a, b, c)
        t = c, c = a, a = t;
      }
      if (a <= c && c < b || b <= c && c < a || c < a && a <=b) {
        //b與c做數值交換：(a, c, b)->(a, b, c)
        t = c; c = b; b = t;
      }
      printf("After: %d %d %d\n", a, b, c);
      return 0;
    }
    ```
- 簡化後變數間可能的大小順序關係：
  - a <= b <= c：不用任何處理
  - a <= c < b：c與b做數值交換(a, c, b)->(a, b, c)
  - b < a <= c：b與a做數值交換(b, a, c)->(a, b, c)
  - b <= c < a：b與a做數值交換，c與b做數值交換(b, c, a)->(a, b, c)
  - c < a <= b：c與a做數值交換，c與b做數值交換(c, a, b)->(a, b, c)
  - c < b < a：b與a做數值交換變成c < a < b，成為上一列的情況
  - 範例：
    ```c
    //簡化上述程式碼
    int main () {
      int a, b, c, t;
      scanf("%d%d%d", &a, &b, &c);
      printf("Before: %d %d %d\n", a, b, c);
      if (b < a) {
        t = b; b = a; a = t;
      }
      if (c < a) {
        t = c; c = a; a = t;
      }
      if (c < b) {
        t = c; c = b; b = t;
      }
      printf("After: %d %d %d\n", a, b, c);
      return 0;
    }
    ```
- 一次只解決一小部分的問題，慢慢累積後就可以解決全部的問題
  - 將a, b, c中最小的數值換到變數a
    - 將a, b中最小的數值換到變數a
    - 將a, c中最小的數值換到變數a
    - 將b, c中最小的數值換到變數b
  - 範例：
    ```c
    //將a, b, c中最小的數值換到變數a
    int main () {
      int a, b, c, t;
      scanf("%d%d%d", &a, &b, &c);
      printf("Before: %d %d %d\n", a, b, c);
      if (b < a) {
        t = b; b = a; a = t;
      }
      if (c < a) {
        t = c; c = a; a = t;
      }
      if (c < b) {
        t = c; c = b; b = t;
      }
      printf("After: %d %d %d\n", a, b, c);
      return 0;
    }
    ```
  - 將a, b, c中最大的數值換到變數c
    - 將a, c中最大的數值換到變數c
    - 將b, c中最大的數值換到變數c
    - 將a, b中最大的數值換到變數b
  - 範例：
    ```c
    //將a, b, c中最大的數值換到變數c
    int main () {
      int a, b, c, t;
      scanf("%d%d%d", &a, &b, &c);
      printf("Before: %d %d %d\n", a, b, c);
      if (c < a) {
        t = c; c = a; a = t;
      }
      if (c < b) {
        t = c; c = b; b = t;
      }
      if (b < a) {
        t = b; b = a; a = t;
      }
      printf("After: %d %d %d\n", a, b, c);
      return 0;
    }
    ```
## 4.11 用排序簡化三角形判斷
- 範例：
  ```c
  int main () {
    //用排序簡化三角形判斷條件
    //當if的大括號內只有一行敘述時，可以省略大括號
    int side1, side2, side3, t;
    printf("Please enter the lengths: ");
    scanf("%d%d%d", &side1, &side2, &side3);
    //在這裡將side1, side2, side3由小到大排
    if (side1 > side2) { 
      t = side1; 
      side1 = side2; 
      side2 = t; 
    }
    if (side1 > side3) { 
      t = side1; 
      side1 = side3; 
      side3 = t; 
    }
    if (side2 > side3) { 
      t = side2; 
      side2 = side3; 
      side3 = t; 
    }
    if (side1 == side3)
      printf("Regular triangle\n");
    if (side1 == side2 || side2 == side3)
      printf("Isosceles triangle\n");
    if (side1 * side1 + side2 * side2 == side3 * side3)
      printf("Rectangular triangle\n");
    return 0;
  }
  ```
# 第五章 二選一的交叉路口（if-else述句）
## 5.1  if-else述句
- if (表示式) {程式片段1} else {程式片段2}
  - 如果「表示式」成立，就執行「程式片段1」
  - 如果「表示式」不成立，就執行「程式片段2」
  - 範例：
    ```c
    int main () {
    int grade;
    printf("Enter the grade: ");
    scanf("%d", &grade);
    if (grade >= 60) {
      printf("Pass!\n");
    } else { 
      printf("Fail!\n");
    }
    return 0;
    }
    ```
## 5.2 兩個變數比大小
- 範例：
  ```c
  int main () {
    int a, b;
    printf("Enter a and b: ");
    scanf("%d%d", &a, &b);
    if (a > b) {
      printf("a > b\n");
    } else if (a < b) {
      printf("b > a\n");
    } else {
      printf("a = b\n");
    }
    return 0;
  }
  ```
## 5.3 猜數字
- 範例：
  ```c
  int main () {
    int answer = 69;
    int guess;
    printf("Please enter your guess: ");
    scanf("%d", &guess);
    if (guess > answer) {
      printf("Too large!\n");
    } else if (guess < answer) {
      printf("Too small!\n");
    } else {
      printf("Correct!\n");
    }
    return 0;
  }
  ```
## 5.4 簡易四則運算
- 範例：
  ```c
  //簡易四則運算
  int main () {
    int a, b;
    char op;
    float ans;
    scanf("%d%c%d", &a, &op, &b);
    if (op == '+') {
        ans = a + b;
    } else if (op == '-') {
        ans = a - b;
    } else if (op == '*') {
        ans = a * b;
    } else {
        ans = (float) a / b;
    }
    printf("ANS: %f\n", ans);
    return 0;
  }
  ```
## 5.5 對多個變數求最大值
- 範例：
  ```c
  //對兩個變數求最大值
  int main () {
    int a, b, max;
    printf("Enter two integers: ");
    scanf("%d%d", &a, &b);
    if (a >= b) {
        max = a;
    } else {
        max = b;
    }
    printf("The maximumu is %d.\n", max);
    return 0;
  }
  //對三個變數求最大值
  int main () {
    int a, b, c, max;
    printf("Enter three integers: ");
    scanf("%d%d%d", &a, &b, &c);
    if (a >= b && a >= c) {
        max = a;
    } else if (b >= a && b >= c) {
        max = b;
    } else {
        max = c;
    }
    printf("The maximum is %d.\n", max);
    return 0;
  }
  ```
# 第六章 多選一的路口（switch述句）
## 6.1 switch述句
```c
switch (整數值) {  
  case 整數常數值://可以指定多個不同的case
    程式片段;  
    break;//執行到break為止  
  default://可以設定default，在所有case都不符合時執行
    程式片段;
}
```
- 範例：
  ```c
  //簡易四則運算
  int main () {
    int a, b;
    char op;
    float ans;
    scanf("%d%c%d", &a, &op, &b);
    switch (op) {
    case '+':
        ans = a + b;
        break;
    case '-':
        ans = a - b;
        break;
    case '*':
        ans = a * b;
        break;
    case '/':
        ans = (float) a / b;
        break;
    }
    printf("ANS: %f\n", ans);
    return 0;
  }
  ```
## 6.2 ID查詢
- 範例（給定表格）：
  |ID|Name|
  |:-:|:-:|
  |2|John|
  |13|Mary|
  |13|Amy|
  ```c
  int main () {
    int id;
    printf("Enter the ID: ");
    scanf("%d", &id);
    switch (id) {
    case 2:
        printf("John\n");
        break;
    case 13:
        printf("Mary\n");
        break;
    case 13:
        printf("Amy\n");
        break;
    default:
        printf("Not found\n");
    }
    return 0;
  }
  ```
# 第七章 有條件的重複執行（while述句）
## 7.1 while述句
- while (表示式) {程式片段}
  - 當「表示式」成立時，就執行「程式片段」
- 範例：
  ```c
  int main () {
    int count = 10;
    while (count < 3) {
      printf("%d\n", count);//不會執行
    }
    return 0;
  }
  int main () {
    int count = 0;
    while (count < 3) {
      printf("%d\n", count);//一直輸出0，無窮迴圈
    }
    return 0;
  }
  int main () {
    int count = 0;
    while (count < 3) {
      printf("%d\n", count);
      count = count + 1;
    }//輸出0, 1, 2
    return 0;
  }
  ```
## 7.2 猜數字
- 範例：
  ```c
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
    while (count == 0 || guess != num) {
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
  ```
## 7.3 計算猜了幾次數字
- 範例：
  ```c
  //計算出猜了幾次
  int main () {
    int num = 10;
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
  ```
## 7.4 求不定個數正整數的總和
- 範例：
  ```c
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
  ```
## 7.5 求不定個數正整數的平均值
- 範例：
  ```c
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
  ```
## 7.6 數數字
- 範例：
  ```c
  //數數字
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
  ```
# 第八章 至少做一次的重複執行（do-while述句）
## 8.1 do-while述句
- do {程式片段} while (表示式);
  - 當「表示式」成立時，就執行「程式片段」
- 範例：
  ```c
  int main () {
    int count = 0;
    do {
      printf("%d\n", count);
      count++;
    } while (count < 3);
    return 0;
  }
  ```
## 8.2 猜數字
- 範例：
  ```c
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
  ```
## 8.3 消費金額計算
- 範例（給定表格）：
  |case|價錢|
  |:-:|:-:|
  |1|90|
  |2|75|
  |3|83|
  |4|89|
  |5|71|
  ```c
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
  ```
# 第九章 計次型的重複執行（for述句）
## 9.1 for述句
- for (初始式; 條件式; 迴圈式) {程式片段}
  - 執行「初始式」
  - 當「條件式」成立時，執行「程式片段」，否則結束迴圈
  - 執行「迴圈式」後再回到上一步
- 範例：
  ```c
  int main () {
    for (int count = 1; count <= 10; count++) {
      printf("%d\n", count);
    }
    return 0;
  }
  ```
## 9.2 數數字
- 範例：
  ```c
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
  ```
## 9.3 等差數列
- 範例：
  ```c
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
  ```
## 9.4 特定條件數列
- 範例：
  ```c
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
  ```
## 9.5 求連續整數和
- 範例：
  ```c
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
  ```
## 9.6 用文字畫橫線
- 範例：
  ```c
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
  ```
## 9.7 找出所有正因數
- 讓使用者輸入一個正整數N，找出N的所有正因數
  - N的因數：可以整除N的整數（整除：餘數為0）
  - N的正因數：可以整除N的正整數
- 8的正因數
  - 可能的候選者：一定是正整數且小於等於8
    - 1, 2, 3, 4, 5, 6, 7, 8
  - 合格條件：可以整除8
    - 1, 2, 4, 8
- 範例：
  ```c
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
  ```
## 9.8 韓信點兵
- 今有物不知其數，三三數之剩二，五五數之剩三，七七數之剩二，問物幾何？
- 合格條件：number % 3 == 2 && number % 5 == 3 && number % 7 == 2
- 正整數
- 範例：
  ```c
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
  ```
## 9.9 質數判斷
- 質數：除了1和自己以外，沒有其他正因數的正整數
  - 不包括1
  - 例如：2, 3, 5, 7, 11, 13, 14, 19, 23, 29, ...
- 質數有無限多個
- 現代幾個密碼系統的基礎
  - 無法有效率進行質因數分解
- 範例：
  ```c
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
    for (num = 2; num < N && N % num != 0; ++num);//找到一個因數就會停止

    if (num == N) {
      printf("Yes\n");
    } else {
      printf("No\n");
    }
    return 0;
  }
  ```
## 9.10 九九乘法表
- 範例：
  ```c
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
  ```
## 9.11 用文字繪製長方形
- 範例：
  ```c
  //讓使用者輸入N，印出NxN個*的圖形
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
  ```
## 9.12 用文字繪製空心長方形
- 範例：
  ```c
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
  ```
## 9.13 用文字繪製三角形
- 範例：
  ```c
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
    int i, j;
    int n;
    printf("N = ");
    scanf("%d", &n);
    
    for (i = 1; i <= n; i++) {    
      for (j = 1; j < i; j++) {
        if (j == 1 || i == n ) {
          printf("*");
        } else {
          printf(" ");
        }
      }
      printf("*\n");
    }
    return 0;
  }
  ```
## 9.14 基於座標法用文字繪製三角形
- 範例：
  ```c
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
  //另一種空心三角形
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
  ```
## 9.15 找簡易方程式整數解
- 範例：
  ```c
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
  ```
# 第十章 終止重複執行（break與continue）
## 10.1 break述句：用來終止迴圈的執行
- break;
  - 中斷目前所屬的重複執行述句
- 範例：
  ```c
  int main () {
    int num;
    for (num = 1; num <= 10; num++) {
      if (num == 5) {
        break;
      }
      printf("%d\n", num);//1, 2, 3, 4
    }
  }
  ```
## 10.2 continue述句：用來跳過迴圈中的某次執行
- continue;
  - 在重複執行述句中跳過後面的程式區塊
- 範例：
  ```c
  int main () {
    int num;
    for (num = 1; num <= 10; ++num) {
      if (num == 5) {
        continue;
      }
      printf("%d\n", num);//1, 2, 3, 4, 6, 7, 8, 9, 10
    }
  }
  ```

# 第十一章 函式簡介
## 11.1.1 關於函式
- 數學的函數（function）
  - 一元多項是函數
    - f(x) = x + 3
    - f(4) = 7
- 可以把每個函式想成是一個獨立的程式模組（副程式），裡面包含了一塊程式片段，具有某種設計好的功能
- 函式定義
  - 一個函式可以接受零到多個參數，但只能回傳一個值
    ```c
    //函式內不能再定義函式
    回傳值的資料型態 函式名稱(參數的資料型態 參數名稱, ...) {
    //程式片段
    return 回傳值;
    }
    ```
- 使用自定義的函式
  - 在程式碼的順序中，呼叫函式前要先宣告或定義函式
    ```c
    //函式的定義
    int f(int x) {
      return x + 3;
    }

    int main () {
      printf("%d\n", f(4));//函式呼叫，7
      return 0;
    }
    //函式的宣告
    int f(int x);

    int main () {
      printf("%d\n", f(4));
      return 0;
    }

    int f(int x) {
      return x + 3;
    }
    ```
- 函式呼叫
  - 執行流程：
    - 計算引數值
      - 將引數值轉型到與參數型態相同
    - 執行函式，得到函式回傳值
  ```c
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

  int foo = 2;
  double bar = div2(foo * 2);//div2(4.0) = 2.0
  ```
## 11.1.2 C標準函式庫
- C標準函式庫與標頭檔
  - 除了制定各式語法讓程式設計師使用外，也制定了一系列的標準函式提供更高階的功能與系統操作
    - 一般的編譯器會依照C語言的規範實現標準函式，但不保證一定都有支援
  - 主要提供以下功能：
    - 輸入/輸出<stdio.h>
    - 字串處理<string.h>
    - 數學運算<math.h>
    - 記憶體管理<stdlib.h>
    - 其他跟作業系統相關的功能
  - 不同功能類型的函式宣告放置在不同的標頭檔
    - 標頭檔的副檔名是.h
    - 標頭檔通常以檔案的形式存放在編譯器知道的位置
    - 引用標頭檔的方式是在程式碼中使用#include指示
- C標準函式庫與目的檔
  - 通常標準函式庫的函式定義會事先編譯好存放在編譯器知道的位置。當在編譯時，一般編譯器會自動幫忙將程是罵與事先準備好的檔案（目的檔）連結產生最後的執行檔
    - 由於不同編譯器上的差異，有時候會需要額外的參數來指定標準函式庫的位置
- 常見的標準函式庫
  - 主要是數學運算、輸入輸出
    - 數學運算<math.h>
      - sqrt（求平方根）、ceil（無條件進位）、abs（求絕對值）等
    - 輸入輸出<stdio.h>
      - printf（輸出）、scanf（輸入）
  ```c
  #include <stdio.h>
  #include <math.h>
  int main () {
    printf("%d\n", printf("Hello world!\n"));//Hello world! 13
    return 0;
  }

  int main () {
    int N;
    printf("N = ");
    scanf("%d", &N);
    printf("%f\n", sqrt(N));
    return 0;
  }
  ```
## 11.1.3 對兩個變數求最大值
- 範例：
  ```c
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
  ```
## 11.1.4 關於變數名稱可視範圍（scope）
- 變數名稱的宣告
  - 變數名稱可以依照宣告的位置分為三種：
    - 全域變數（Global variable）
      - 宣告在函式定義外
      - 因為容易造成名稱污染，所以不建議使用
      ```c
      int i;
      int main () {
        return 0;
      }
      ```
    - 區域變數（Local variable）
      - 宣告在函式定義內
      ```c
      int main () {
        int i;
        return 0;
      }
      ```
    - 函式參數（Function parameter）
      ```c
      int f(int i) {
        return 0;
      }
      ``` 
  - 在同一組區塊{}內同名稱變數只能有一個
  - 同名的全域變數只能有一個
  - 同名的全域變數和函式只能有一個
    ```c
    int i;//全域變數
    int main () {
      int i;//區域變數
      {
        int i;//{}內的區域變數
      }
      return 0;
    }
    int f(int i) {//函式參數
      return 0;
    }
    ```
- 要在程式碼中使用某個已經宣告的變數名稱需要同時滿足以下兩個條件：
  - 在程式碼中位於該變數名稱的宣告之後
  - **該變數是全域變數**或者**被包含在該變數名稱宣告的區塊{}內**
    ```c
    int i = 1;
    int main () {
      printf("%d\n", i);//1
      int i = 2;
      printf("%d\n", i);//2
      {
        printf("%d\n", i);//2
        int i = 3;
        printf("%d\n", i);//3
      }
      printf("%d\n", i);//2
    }
    //範例一
    int i = 5;
    int f () {
      i = i + 1;
      printf("%d\n", i);//6，找近的
      return 0;
    }
    int main () {
      printf("%d\n", i);//5
      int i = 6;
      i = i + 1;
      f ();
      printf("%d\n", i);//7，找近的
      return 0;
    }
    //範例二
    int main () {
      int i = 3;
      printf("%d\n", i);//3
      if (i == 3) {
        i = i + 1;
        int i = 6;
        printf("%d\n", i);//6
        i = i + 1;
      }
      if (i == 3) {
        printf("%d\n", i);//4
      }
      return 0;
    }
    ```
## 11.1.5 對三個變數求最大值
- 範例：
  ```c
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
  //利用max(11.3)幫助判斷三個變數大小
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
  ```
## 11.1.6 用文字繪製三角形
- 範例：
  ```c
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
  ```
## 11.1.7 亂數生成
- 隨機產生整數
  - C標準函式庫中提供了亂數生成的函式rand()，在<stdlib.h>中
  - 使用srand()來設定亂數種子，在<stdlib.h>中
  - 利用取得系統時間的time()函式，在<time.h>中
  ```c
  #include <stdlib.h>
  #include <time.h>
  //亂數生成
  //5個亂數
  int main () {
    srand(time(0));//time(0)回傳目前時間，srand()用來設定亂數種子
    int i;
    for (i = 1; i <= 5; ++i) {
      printf("%d\n", rand());//每次呼叫rand()就會回傳一個隨機產生的亂數
    }
    return 0;
  }
  ```
## 11.1.8 擲骰子
- 範例：
  ```c
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
  ```
## 11.2.1 函式遞迴
```c
//無窮遞迴
void f(void);

int main () {
  f();
  return 0;
}

void f(void) {
  f();
}
//加上參數
void f(int);

int main () {
  printf("%d\n", f(0));
  return 0;
}

int f(int i) {
  return f(i + 1);//無窮遞迴
}
//
int f(int);

int main () {
  printf("%d\n", f(0));//呼叫int f(int i)函式，回傳值為0
  return 0;
}

int f(int i) {
  if (i == 2) {
      return i;
  } 
  return f(i + 1);//遞迴後回傳值
}
```
## 11.2.2 數數字
- 範例：
  ```c
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
  ```
## 11.2.3 連續整數和
- 遞迴
  - sum(1) = 1
  - sum(2) = 1 + 2
  - sum(3) = 1 + 2 + 3
  - 規律為：
    - sum(1) = 1
    - sum(2) = sum(1) + 2
    - sum(3) = sum(2) + 3
    - sum(n) = sum(n-1) + n
  - 歸納出sum(N)：
    - n = 1, sum(1) = 1
    - n > 1, sum(n) = sum(n-1) + n
- 範例：
  ```c
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
  ```
## 11.2.4 費波那契數列：上樓梯方法數
- 每次只走一階或兩階樓梯，印出走到第N階的方法數（N>=1）
- 規律為：
  - s(1) = 1
  - s(2) = 2
  - s(3) = s(1) + s(2)
  - s(4) = s(2) + s(3)
  - s(5) = s(3) + s(4)
- 歸納出s(N)：
  - N = 1, s(1) = 1
  - N = 2, s(2) = 2
  - N > 2, s(N) = s(N-1) + s(N-2)
- 範例：
  ```c
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
  ```
## 11.3 前置處理器-#define
### 11.3.1 使用#define
- #define定義：
  - **#define** 識別名稱 代換標記
  - 範例：
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #define BEGIN {
    #define END }
    int main(void)
    BEGIN
      int i, j;

      for(i = 1; i <= 5; i++)
      BEGIN
        for(j = 1; j <= i; j++)
          printf("*");
        printf("\n");
      END

      return 0;
    END
    ```
- 如果#define定義的內容很長時，可以利用反斜線\分成兩行
### 11.3.2 為什麼要用#define？
  - 增加程式的易讀性
  - 程式碼的重複使用
  - 範例：
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #define PI 3.14
    double area(double);

    int main(void) {
      printf("PI = %4.2f, area() = %6.2f\n", PI, area(2.0));
      return 0;
    }

    double area(double r) {
      return PI * r * r;
    }
    ```
### 11.3.3 利用#define取代簡單的函數
  - 巨集（marco）：可以想像成是一個簡單的指令來替代多個操作步驟，可以替換常數、字串、程式區段
  - 範例：
    ```c
    #include <stdio.h>
    #include <stdlib.h>
    #define SQUARE n*n
    int main(void) {
      int n;
      printf("Input an integer: ");
      scanf("%d", &n);
      printf("%d * %d = %d\n", n, n, SQUARE);//計算n*n
      return 0;
    }
    ```
### 11.3.4 使用有引數的巨集
- 範例：
  ```c
  #include <stdio.h>
  #include <stdlib.h>
  #define SQUARE(X) X*X//定義巨集SQUARE(X) = X*X
  int main(void) {
    int n;
    printf("Input an integer: ");
    scanf("%d", &n);
    printf("%d * %d = %d\n", n, n, SQUARE(n));//計算n*n
    return 0;
  }
  //將SQUARE(n)改成SQUARE(n+1)
  #include <stdio.h>
  #include <stdlib.h>
  #define SQUARE(X) X*X
  int main(void) {
    int n;
    printf("Input an integer: ");
    scanf("%d", &n);
    printf("%d * %d = %d\n", n+1, n+1, SQUARE(n+1));//會變成n+1*n+1
    //假設n為12，等於12+1*12+1 = 25
    return 0;
  }
  //將SQUARE(n)改成SQUARE(n+1)的正確寫法
  #include <stdio.h>
  #include <stdlib.h>
  #define SQUARE(X) (X)*(X)
  int main(void) {
    int n;
    printf("Input an integer: ");
    scanf("%d", &n);
    printf("%d * %d = %d\n", n+1, n+1, SQUARE(n+1));//計算(n+1)*(n+1)
    return 0;
    //結果為(n+1)*(n+1)，假設n為12，等於13*13 = 169
  }
  ```
# 第十二章 陣列
## 12.1.1 陣列變數
- 陣列是一群具有相同資料型態元素集合的資料型態
  - 在記憶體中，一個陣列會使用一段連續的記憶體空間來儲存
- 變數定義：
  - **元素資料型態** 陣列變數名稱[元素個數];
- 一般與陣列變數差異：
  - 一般變數：int var;
  - 陣列變數：int var[3];，等於int var0, var1, var2;
- 第一種用途：取代多個變數定義
  - 陣列元素的存取：**陣列變數名稱**[元素索引編號];
    ```c
    int v[3];//三個房間
    v[0] = 3;
    v[1] = 5;
    v[2] = 0;
    int max = v[0];
    if (v[1] > max) {
      max = v[1];
    }
    if (v[2] > max) {
      max = v[2];
    }
    printf("%d\n", max);
    ```
- 陣列元素的初始化
  - **元素資料型態** 陣列變數名稱[元素個數] = {元素1, 元素2, ...};
    ```c
    int v[3] = {3, 5, 0};
    ```
  - 初始化時最少需要指定一個值，而未定義的元素會被設定為0
    ```c
    int v[3] = {3, 5};，所以v[2] = 0
    ```
  - 初始化時，陣列元素個數值可以省略，會以初始化元素個數取代
    ```c
    int v[] = {3, 5, 0};
    ```
## 12.1.2 骰子點數出現統計
- 範例：
  ```c
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
  ```
## 12.1.3 循序存取陣列元素
- 第二種用途：循序存取陣列元素
  ```c
  int v[3] = {3, 5, 0};
  int i;
  int max = v[0];
  for (i = 1; i <= 2; ++i) {
    if (v[i] > max) {
      max = v[i];
    }
  }
  printf("%d\n", max);
  ```
- 範例：
  ```c
  //循序存取
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
  ```
## 12.1.4 隨機存取陣列元素
- 範例：
  ```c
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
  ```
## 12.1.5 兩顆骰子點數和出現次數統計
- 範例：
  ```c
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
  ```
## 12.1.6 查詢數字
- 範例：
  ```c
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
  ```
## 12.1.7 查詢範例內數字
- 範例：
  ```c
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
  ```
## 12.1.8 查詢上限內最大數字
- 範例：
  ```c
  //查詢上限內最大數字
  //輸入10個整數，輸入要查詢的數字後，顯示輸入的整數中最接近的一個
  //輸入0則結束
  int main () {
    int i, num[10], q;
    
    for (i = 1; i <= 10; i++) {
        scanf("%d", &num[i-1]);//代表第幾個數字
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
  ```
## 12.1.9 查詢最接近數字
- 範例：
  ```c
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
  ```
## 12.1.10 畫數字統計長條圖
- 範例：
  |區間n|區間-1(n-1)|計數器編號b[0]|
  |:-:|:-:|:-:|
  |1-10|0-9|0|
  |11-20|10-19|1|
  |21-30|20-29|2|
  |31-40|30-39|3|
  |41-50|40-49|4|
  |51-60|50-59|5|
  |61-70|60-69|6|
  |71-80|70-79|7|
  |81-90|80-89|8|
  |91-100|90-99|9|
  ```c
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
  ```
## 12.1.11 求小範圍內眾數
- 範例：
  ```c
  //求小範圍內的眾數
  //輸入10個0~9的整數，輸出眾數
  //當有一樣多的眾數時，輸出最大的
  int main () {
    int i, n, a[10] = {0};
    for (i = 1; i <= 10; i++) {
        scanf("%d", &n);
        a[n]++;//a[n]代表第幾個計數器（a[0]~a[9]）
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
  ```
## 12.1.12 數字統計
- 範例：
  ```c
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
  ```
## 12.1.13 陣列排序
- 範例：
  ```c
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
  ```
## 12.2 關於陣列的記憶體配置
- 陣列型態變數的記憶體配置
  - int v[6] = {1, 2, 3, 4, 5, 6};
- 元素型態是陣列的陣列
  - 2*3的陣列：int v[2][3] = {{1, 2, 3}, {4, 5, 6}};
    - v[0]包含三個元素：1, 2, 3；v[1]包含三個元素：4, 5, 6
      - v[0][0] = 1, v[0][1] = 2, v[0][2] = 3; v[1][0] = 4, v[1][1] = 5, v[1][2] = 6
  - 3*2的陣列：int v[3][2] = {{1, 2}, {3, 4}, {5, 6}};
    - v[0]包含兩個元素：1, 2；v[1]包含兩個元素：3, 4；v[2]包含兩個元素：5, 6
      - v[0][0] = 1, v[0][1] = 2; v[1][0] = 3, v[1][1] = 4; v[2][0] = 5, v[2][1] = 6
### 12.2.1 用二維陣列表示九宮格
- 範例：
  ```c
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
  ```
## 12.2.2 用一維陣列表示九宮格
- 範例：
  ```c
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
  ```
## 12.2.3 隨機生成九宮格
- 範例：
  ```c
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
  ```
## 12.3 亂數的產生
### 12.3.1 產生不重複亂數（使用陣列）
- 範例：
  ```c
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
  ```
### 12.3.2 用建表法產生不重複亂數（使用陣列）
- 範例：
  ```c
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
  ```
### 12.3.3 用交換法產生不重複亂數（使用陣列）
- 範例：
  ```c
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
  ```
## 12.4 全域（Global）變數與靜態（Static）區域變數
```c
//在函式定義外宣告定義變數
int k = 0;//全域變數，盡量避免使用全域變數

int count() {
    k++;//每次呼叫都存取同一個全域變數
    return k;
}

int main () {
    int i;
    for (i = 1; i <= 5; i++) {
        printf("%d ", count());
    }//1 2 3 4 5
    return 0;
}

//靜態區域變數
int count(void) {
    static int k = 0;//靜態的區域變數只會有一份，只會初始化一次
    k++;
    return k;
}

int main () {
    int i;
    for (i = 1; i <= 5; i++) {
        printf("%d ", count());
    }//1 2 3 4 5
    return 0;
}
```
## 12.5 整數的溢位
```c
//有號整數的溢位是未定義行為
int main () {
  int a = 1000;
  int b = a * a * a;
  int c = a * a * a * a;
  printf("%d %d\n", b, c);//1000000000 -727379968
  return 0;
}
//使用<limits.h>
//整數型態可表示的範圍由實作定義
#include <limits.h>
int main () {
  printf("%d\n", INT_MAX);//2147483647
  printf("%d\n", INT_MIN);//-2147483648
  return 0;
}
//如果是無號整數，則溢位是定義行為
int main () {
  unsigned int a = 1000;
  unsigned int b = a * a * a;
  unsigned int c = a * a * a * a;
  printf("%u\n", b);//1000000000
  printf("%u\n", c);//1000000000000%(UINT_MAX+1)
  printf("%u\n", UINT_MAX);//4294967295
  return 0;
}
```
## 12.6 自行生成偽亂數
- 產生混亂的數列
  - 每次將上一個數字乘以5
    - 1, 5, 25, 125, 625, 3125,...
  - 每次將上一個數字乘以5再加3
    - 1, 8, 43, 218, 1093, 5468,...
  - 每次將上一個數字乘以5再加3再除以13求餘數
    - (1, 8, 11, 10, 5 ,12, 15, 9, 0, 3, 2, 13, 4, 7, 6), 1, 8,...
- 如何產生偽亂數
  - 線性同餘法（Linear Congruential Generator）
    - Xn+1 = (Xn * a + c) % m
      - X0 = 1：亂數種
      - Xn+1 = (Xn * 1104515245 + 12345) % 4294967296
- 範例：
  ```c
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
  ```
### 12.6.1 自定義亂數函式
- 範例：
  ```c
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
  ```
## 12.7 陣列的複製
### 12.7.1 陣列的複製
|n[0]|n[1]|n[2]|n[3]|n[4]|n[5]|n[6]|n[7]|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|(int)1|(int)2|(int)3|(int)4|(int)5|(int)6|(int)7|(int)8|  

如何複製變成以下？

|v[0]|v[1]|v[2]|v[3]|v[4]|v[5]|v[6]|v[7]|
|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
|(int)1|(int)2|(int)3|(int)4|(int)5|(int)6|(int)7|(int)8|
- 直接複製陣列會消耗大量時間和資源，代價很高的操作 （例如：new_array = old_array;，C語言無法直接以此程式進行操作）因此在C語言裡面，對於一般變數和陣列其內部的操作會有所不同
  - 一般變數：會複製一個複製品到function裡面去做操作，，function內的操作直接只限於對複製品，而不會影響本尊
  - 陣列：不會複製一份陣列到function裡面，但function內的操作影響本尊的數值
- 範例：
  ```c
  //講解
  int main () {
    srand(time(0));
    int i, n[10], v[10];
    for (i = 0; i < 10; i++) {
        n[i] = rand() % 100;
    }
    //錯誤：v = n;、int v[10] = n;
    //正確：int v[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    return 0;
  }
  //逐次複製
  int main () {
    srand(time(0));
    int i, n[10], v[10];
    for (i = 0; i < 10; i++) {
        n[i] = rand() % 100;
    }
    for (i = 0; i < 10; i++) {
        v[i] = n[i];//一個一個複製
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", n[i]);
    }
    for (i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    return 0;
  }
  //函式寫法
  void printArray(int [10]);
  int main () {
    srand(time(0));
    int i, n[10], v[10];
    for (i = 0; i < 10; i++) {
        n[i] = rand() % 100;
    }
    for (i = 0; i < 10; i++) {
        v[i] = n[i];
    }
    printArray(n);
    printArray(v);
    return 0;
  }
  void printArray(int a[10]) {
    for (int i = 0; i < 10; i++) {
        printf("%d ", a[i]);
    }
    printf("\n");
  }
  //不同函式間的變數是獨立的，所以n不會改變
  void increase(int);
  int main () {
    int n = 1;
    increase(n);//呼叫函式時，n的值會被複製到函式的參數中
    printf("%d\n", n);//1
    return 0;
  }
  void increase(int n) {
    n++;//對n的操作不會影響到main函式中的n
  }
  //陣列是例外，當傳過去的是陣列時，函式得到的陣列是原本的陣列
  void increase(int[3]);
  int main () {
    int i, n[3] = {1, 2, 3};
    increase(n);
    for (i = 0; i < 3; i++) {
      printf("n[%d] = %d\n", i, n[i]);//
    }
    return 0;
  }
  void increase(int n[3]) {//n[3]得到的是本尊（原本的n[3]={1, 2, 3}）
    for (int i = 0; i < 3; i++) {
      n[i]++;
    }
  }
  ```
### 12.7.2 在函式間傳遞陣列
- 當函式參數是陣列型態時，與一般資料型態行為不一樣
  - 一般資料型態：函式內的操作只限於複製品，不會影響本尊
  - 陣列型態：函式內的操作會影響本尊
    - 『複製的是陣列第一個元素的記憶體位址』
- 當函式回傳值是陣列型態時，是不合法的
  - 為了做出等效於函釋回傳的效果，可以將陣列作為引數導入
  - 當陣列作為引數導入時，陣列內容的修改會套用到這個傳入的陣列本身
- 為了與一般資料型態的行為相符，C語言導入了「指標」來處理各種陣列複製與存取的行為，「指標是用來存記憶體位址」
- 範例：
  ```c
  //在函式間傳遞陣列
  int arrayMax(int[10]);
  void arrayPrint(int[10]);
  void arrayRand(int[10]);
  int main () {
    srand(time(0));
    //錯誤寫法：int v[10] = arrayRand();
    int v[10];
    arrayRand(v);
    arrayPrint(v);
    printf("Max: %d\n", arrayMax(v));
    return 0;
  }
  //arrayRand()
  //錯誤寫法：int[10] arrayRand() {}
  void arrayRand(int v[10]) {
    int i;
    for (i = 0; i < 10; i++) {
        v[i] = rand() % 100;
    }
  }
  //arrayMax()
  int arrayMax(int v[10]) {
    int i, max = v[0];
    for (i = 0; i < 10; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
  }
  //arrayPrint()
  void arrayPrint(int v[10]) {
    int i;
    for (i = 0; i < 10; i++) {
        printf("%d ", v[i]);
    }
    printf("\n");
  }
  ```
### 12.7.3 可對任意大小陣列求最大值
- 範例：
  ```c
  //可對任意大小陣列求最大值
  int maxv(int[], int N);

  int main () {
    int a[3] = {3, 9, 7};
    printf("Max: %d\n", maxv(a, 3));
    int b[5] = {3, 9, 1, 2, 7};
    printf("Max: %d\n", maxv(b, 5));
    return 0;
  }

  int maxv(int v[], int N) {//v[]代表陣列是誰，N代表陣列多大
    int max = v[0], i;
    for (i = 1; i < N; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
  }
  ```
### 12.7.4 存取陣列外元素的問題
```c
int main () {
  int v[3] = {1, 2, 3};
  printf("%d\n", v[0]);
  printf("%d\n", v[2]);
  printf("%d\n", v[3/2]);//v[1]
  printf("%d\n", v[0.5]);//編譯錯誤
  printf("%d\n", v[3/2.]);//編譯錯誤
  printf("%d\n", v[3]);//未定義行為
  printf("%d\n", v[4]);//未定義行為
  printf("%d\n", v[-1]);//未定義行為
  return 0;
}
//存取陣列外元素的問題
int max3(int[3]);

int main () {
    int a[3] = {3, 9, 7};
    printf("Max: %d\n", max3(a));
    int b[5] = {3, 2, 1, 9, 7};
    printf("Max: %d\n", max3(b));//只會比較b陣列前三個元素{3, 2, 1}
    return 0;
}

int max3(int v[3]) {
    int max = v[0], i;
    for (i = 1; i < 3; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}
//未定義行為
int max5(int[5]);

int main () {
    int a[3] = {3, 9, 7};
    printf("Max: %d\n", max5(a));//未定義行為
    int b[5] = {3, 2, 1, 2, 7};
    printf("Max: %d\n", max5(b));
    return 0;
}

int max5(int v[5]) {
    int max = v[0], i;
    for (i = 1; i < 5; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
}
```
## 12.8 使用sizeof()求陣列長度
- sizeof運算子
  - 資料型態佔用的記憶體空間大小大多是屬於「實作定義」，會隨著編譯器與設定上的不同而有所差異
  - 可以求出某個值或某種資料型態所佔用的記憶體空間大小（以位元組為單位）
    - 運算結果為size_t型態（在printf()中使用%zu），為無號整數（unsigned int）型態
      ```c
      printf("Size of long int: %zu\n", sizeof(long long));//8
      printf("Size of 3: %zu\n", sizeof(3));//4
      //直接宣告定義
      int main () {
        int v[3] = {1, 2, 3};
        printf("Size of int: %zu\n", sizeof(int));//4
        printf("Size of v[0]: %zu\n", sizeof(v[0]));//4
        printf("Size of v: %zu\n", sizeof(v));//12
        printf("Length of v: %zu\n", sizeof(v)/sizeof([0]));//12/4=3
      }
      //函式中無法用sizeof()求陣列長度
      void f(int v[3]);

      int main () {
          int v[3] = {1, 2, 3};
          f(v);
          return 0;    
      }
      //v[3]不是陣列，內容寫多少不會影響佔據記憶體空間的大小
      void f(int v[3]) {
          printf("Size of int: %zu\n", sizeof(int));
          printf("Size of v[0]: %zu\n", sizeof(v[0]));
          printf("Size of v: %zu\n", sizeof(v));
          printf("Length of v: %zu\n", sizeof(v)/sizeof(v[0]));
      }
      ```
## 12.9 用保留值標記陣列長度
```c
//用保留值標記陣列長度
int length(int[]);

int main () {
    int v[] = {1, 2, 3, -1};//自行決定陣列長度，此為-1停止
    printf("%d\n", length(v));
    return 0;    
}

int length(int v[]) {
    int i = 0;
    while (v[i] != -1) {//當遇到-1時
        i++;
    }
    return i+1;//表示陣列的長度。如果是i，則表示為幾筆資料
}
//範例
int maxv(int[]);

int main () {
    int a[4] = {3, 9, 7, -1};
    printf("Max: %d\n", maxv(a));
    int b[6] = {3, 9, 1, 2, 7, -1};
    printf("Max: %d\n", maxv(b));
    return 0;
}

int maxv(int v[]) {
    int max = v[0], i = 1;
    while (v[i] != -1) {
        if (v[i] > max) {
            max = v[i];
        }
        i++;
    }
    return max;
}
```
## 12.10 存取陣列元素的原理
- 記憶體的位址，每次執行可能不同
  - 陣列元素的存取是透過記憶體位址來進行的
  - v[i]的起始位址 ＝ 第一個元素的起始位址 ＋ i * sizeof(int)
## 12.11 在函式間傳遞陣列的原理
- 陣列a：初始位址：20000
  |a[0]|a[1]|a[2]|
  |:-:|:-:|:-:|
  |(int)3|(int)9|(int)7|
  |20000|20004|20008|  
- 陣列b：初始位址：20012
  |b[0]|b[1]|b[2]|b[3]|b[4]|
  |:-:|:-:|:-:|:-:|:-:|
  |(int)3|(int)9|(int)1|(int)2|(int)7|
  |20012|20013|20020|20024|20028|
- 範例：
  ```c
  //範例
  int maxv(int[], int N);

  int main () {
    int a[3] = {3, 9, 7};
    printf("Max: %d\n", maxv(a, 3));
    int b[5] = {3, 9, 1, 2, 7};
    printf("Max: %d\n", maxv(b, 5));
    return 0;
  }
  //v[]是陣列的起始位址，N是陣列的長度
  int maxv(int v[], int N) {
    int max = v[0], i;
    for (i = 1; i < N; i++) {
        if (v[i] > max) {
            max = v[i];
        }
    }
    return max;
  }
  ```
# 第十三章 字串簡介
## 13.1 字串
- 字串是字元的序列
  - 字元型態（char）可用來儲存「一個」字元，但須要處理的文字經常是「一串」字元
    - "Hello, World!"不只有一個字元
- C語言並替字串定義一個新的資料型態
  - 字串是用字元陣列（char[]）的形式來儲存
  - 透過在<string.h>內提供各種處理字元的韓式來實現對字串的操作作為
- 字元陣列
  - 字元與字元陣列
    - 一個字元型態可以存放一個字元
      - char ch = 'H';
    - 一個字元陣列型態變數可以存放一到多個字元
      - char str[] = {'H', 'e', 'l', 'l', 'o'};
  - 字串與字元陣列
    - 字串是以'\0'表示結尾的字元陣列
      - char str[] = {'H', 'e', 'l', 'l', 'o', '\0'};
    - 字元陣列可以用「字串內容」來初始化，會自動加上'\0'字元
      - char str[] = "Hello";
```c
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
//使用%s印出字串
void str_print(char str[]) {
    printf("%s\n", str);
}

int main () {
    char str[] = "Hello";
    str_print(str);
    return 0;
}
```
## 13.2 計算字串長度
- %zu為C99標準，如果編譯器不支援，則使用%lu或%u
- 假設宣告字串的空間大於字串的長度，會自動補'\0'字元
  ```c
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
  //字串空間大於字串長度
  int main () {
    char str[15] = "Hello world";
    printf("%zu\n", sizeof(str));//15
    printf("%d\n", str_len(str));//5
  }
  //字串空間小於字串長度：不合法
  int main () {
    char str[5] = "Hello world";
    printf("%zu\n", sizeof(str));
    printf("%d\n", str_len(str));
  }
  //未定義行為：可能存取到陣列以外的元素
  int main () {
    char str[11] = "Hello world";
    printf("%zu\n", sizeof(str));
    printf("%d\n", str_len(str));
  }
  ```
## 13.3 從鍵盤輸入讀入一行字
- 關於從鍵盤輸入
  - 一般情況：鍵盤—>Hello—>點擊Enter鍵—>stdin<—程式（scanf）
    - 標準輸入（stdin）就像是個檔案，在鍵盤點擊「輸入」（Enter）鍵後就會把輸入的資料「寫入」到標準輸入內
    - 執行到scanf時，程式會試著從stdin「讀入」資料。如果這時stdin裡沒有未讀的新資料，程式會卡住（blocking）
- 範例：
  ```c
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
  ```
## 13.4 關於讀入字串的緩衝區溢位問題
```c
void str_read(char[]);

int main () {
    //在讀入字串前就要決定存放字串的緩衝區大小
    char str[15];
    str_read(str);
    printf("%s\n", str);
    return 0;
}

void str_read(char str[]) {
    int i = 0;
    while (1) {
        scanf("%c", &str[i]);
        //當i=15，就會變成未定義行為
        if (str[i] == '\n')
            break;
        i++;    
    }
    str[i] = '\0';
}
//最多跑14次
void str_read(char[], int);

int main () {
    char str[15];
    str_read(str, 14);
    printf("%s\n", str);
    return 0;
}

void str_read(char str[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        scanf("%c", &str[i]);
        if (str[i] == '\n')
            break;   
    }
    str[i] = '\0';
}
```
## 13.5 使用scanf讀入資料的問題
```c
//忽略空白字元
int main () {
  int num;
  scanf("%d", &num);//輸入   3
  printf("%d\n", num);//輸出3
  return 0;
}
//輸入不是十進位整數
int main () {
  int num;
  scanf("%d", &num);//輸入abc
  printf("%d\n", num);//未定義行為
  return 0;
}
//判讀scanf函式是否成功讀入資料
int main () {
  int num;
  //有讀取資料的話，會回傳1，否則回傳0，不會進入迴圈
  if (scanf("%d", &num) == 1) {;
    printf("%d\n", num);
  } else {
    printf("Error: Invalid input\n");
  }
  return 0;
}
//持續讀取資料直到使用者輸入正確的資料
int main () {
  int num;
  //當scanf函式回傳值不等於1時，代表讀取失敗
  while (scanf("%d", &num) != 1) {
    printf("Error: Invalid input\n");
  }//會一直印出Error: Invalid input
  printf("%d\n", num);
  return 0;
}
```
# 第十四章 指標
## 14.1 沒有指標的世界
- 以前不能處理的問題
  - 在被呼叫的函式中修改引數值
    - 函式呼叫時，引數值會複製一份到被呼叫的韓式內作為參數使用。在函式內部對參數做任何的變動不會改變到原本的引數值
    ```c
    void addone(int n) {
      n = n + 1;
    }
    int main () {
      int a = 3;
      addone(a);//複製a的值作為n到addone函式中
      printf("%d\n", a);//3
      return 0;
    }
    ```
  - 直接複製陣列
    ```c
    int main () {
      int v[5] = {1, 2, 3, 4, 5};
      int n[5];
      n = v;//錯誤，編譯失敗
      return 0;
    }
    ```
  - 直接複製字串
    ```c
    int main () {
      char v[6] = "Hello";
      char n[6];
      n = v;//錯誤，編譯失敗
      return 0;
    }
    ```
  - 動態改變陣列長度
    - 在儲存資料前需要先配置陣列長度，如果一開始不知道資料總共有幾筆，要怎麼配置？
      - 例如要讓使用者輸入任意筆資料並儲存起來要怎麼辦？
    ```c
    int main () {
      char v[5];
      char n[10];
      n = v;//錯誤，編譯失敗
      return 0;
    }
    ```
- 指標型態
  - 『指標』是一種資料型態，用來儲存『記憶體位址』
    - 一般情況是不需要指標
    - 可以解決的問題
      - 在被呼叫的函式中修改引數值
      - 直接複製陣列
      - 直接複製字串
      - 動態改變陣列長度
### 14.1.1 指標變數宣告與取址運算
- 指標變數宣告（type *）
  - 『指標』（Pointer）是C語言的主要特性，是種儲存『記憶體位址』的資料型態
  - 語法：**資料型態** *變數名稱;
    - 表示變數內存放的是一個存放這種『資料型態』的『記憶體位址』
- 與其他變數差別
  - 宣告整數變數：int count;：代表count變數內存放的是整數值（int）
  - 宣告指標變數：int *countAddr;：代表countAddr變數內存放的是整數值（int）的記憶體位址
- 取址運算符（&）
  - 變數依照資料型態會佔據一定的記憶體空間。可以利用取址運算子（&）取得變數開頭的記憶體位址  
  ```c
  int count = 9;
  int *countAddr = &count;
  ```
  - count = 9(int)，位置在*2293620*
  - countAddr = *2293620*(int *)，位置在2293624
### 14.1.2 指標間接運算
- 間接運算子（*）
  - 可以利用間接運算子（*）從記憶體位址取得開頭位於該位址的變數（別跟宣告指標變數時用的 * 混淆）
  - 要讀寫某個變數的值，可以透過變數的名稱也可以透過變數所在的位址
  ```c
  //指標的特殊能力
  int count = 9;
  int *countAddr = &count;//*代表型態
  int result = *countAddr;//*透過count的位址讀count值
  //相等於
  int count = 9;
  int result = count;
  //此外
  int count = 9;
  int *countAddr = &count;
  *countAddr = 10;//透過count的位址寫count值
  //相等於
  int count = 9;
  count = 10;
  //不相等於
  int count = 9;
  int result = count;
  result = 10;
  //範例
  int countA = 9;
  int countB = 10;
  int *countAddr;

  countAddr = &countA;
  *countAddr = 0;

  countAddr = &countB;
  *countAddr = 0;
  //相等於
  int countA = 9;
  int countB = 10;
  countA = 0;
  countB = 0;
  ```
  |表示式|資料型態|值|
  |:-:|:-:|:-:|
  |count|int|9|
  |&count|int *|2293620|
  |countAddr|int *|2293620|
  |*countAddr|int|9|
  |result|int|9|
  ```c
  //指標變數與其他變數的差別
  int count = 9;

  int a;
  int *b;

  a = count;//(o) (int)=(int)
  b = count;//(x) (int *)!=(int)

  a = &count;//(x) (int)!=(int *)
  b = &count;//(o) (int *)=(int *)

  count = *a;//(x) (int)!=(int *)
  count = *b;//(o) (int *)=(int *)
  ```
### 14.1.3 更多指標與取址間接運算的細節
- 指標（type *）：可儲存記憶體位址的型態
- 取址運算子（&）：可取得變數的記憶體起始位址
  - &變數
- 間接運算子（*）：取得以該記憶體位址起始的變數
  - *記憶體位址
- 相鄰的* &可以抵銷
  - int result = *&count; –> int result = count;
  ```c
  int count = 9;
  int *countAddr = &count;
  int result = *countAddr;//等於*&count;
  *countAddr = 10;//等於count=10;
  *&*&*&result = 20;//等於result=20;
  ```
### 14.1.4 指標與函式呼叫
- 函式呼叫時複製記憶體位址
  - 呼叫函式時，可以將變數的『記憶體位址』作為引數傳入函式執行。此時函式內部對該參數透過『間接運算子』賦予新的數值就可以改變原本的變數值
  ```c
  void addone(int *n) {
    *n = *n + 1;//a = a + 1;
  }

  int main () {
    int a = 3;
    addone(&a);//複製a的記憶體位址傳入addone函式
    printf("%d\n", a);//4
    return 0;
  }
  ```
### 14.1.5 兩個變數數值交換
- 範例：
  ```c
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
  ```
### 14.1.6 兩個變數的排序
- 範例：
  ```c
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
  ```
### 14.1.7 該傳變數值還是位址
- 基本原則：
  - 可以傳值就傳值
    - 複製一份比較安全，不怕被修改，確保函式間乾淨的關係
    - 用起來比較方便，可以傳一般的常數
- 例外規則：
  - 作為引數的變數在呼叫函式後值會變動（例如排序、交換）
  - 無法直接複製值（例如陣列、字串）
  - 複製成本太高（例如較複雜的結構）
### 14.1.8 指標對整數的加減運算
```c
int v[5];
//可以透過將陣列元素的位址加減一個整數來求得其他元素位址
&v[0] + 1 == &v[1];//從v[0]位址往前移動一個陣列元素後的位址
&v[1] + 1 == &v[2];//從v[1]位址往前移動一個陣列元素後的位址
&v[1] - 1 == &v[0];//從v[1]位址往後移動一個陣列元素後的位址
&v[0] + &v[1];//錯誤，編譯失敗
&v[2] - &v[1] == 1;//從v[2]位址到v[1]位址距離1個元素
&v[3] - &v[0] == 3;//從v[3]位址到v[0]位址距離3個元素
```
## 14.2 指標與陣列
- 指標與陣列的不同
  ```c
  int v[5];//宣告定義一個有5個元素的陣列，佔據5個int大小的記憶體
  int *n;//宣告定義一個int指標，佔據1個int *大小的記憶體
  n = &v[0];//將v[0]的位址指定給n
  //陣列型態可隱性轉型成該陣列第一個元素記憶體位址的指標
  n = v;//等於n = &v[0];
  ```
- 透過指標運算存取陣列元素
  ```c
  int v[5];
  int *n = v;
  n == &v[0];//*n = 0等於v[0] = 0
  n+1 == &v[0]+1;//等於&v[1]，*(n + 1) = 0等於v[1] = 0
  n+2 == &v[0]+2;//等於&v[2]，*(n + 2) = 0等於v[2] = 0
  ```
### 14.2.1 循序存取陣列元素（使用指標）
```c
int main () {
  int v[5] = {1, 2, 3, 4, 5};
  int *n = v;//int *n = &v[0];
  int i;
  for (i = 0; i < 5; i++) {
    printf("%d\n", *(n+i));//v[i]
  }
  return 0;
}
//指標可以移動
int main () {
  int v[5] = {1, 2, 3, 4, 5};
  int *n = v;//n == &v[0];
  printf("%d\n", *n);//也可以變成printf("%d\n", *n++);（五次）
  n = n + 1;//n == &v[1];
  printf("%d\n", *n);
  n = n + 1;//n == &v[2];
  printf("%d\n", *n);
  n = n + 1;//n == &v[3];
  printf("%d\n", *n);
  n = n + 1;//n == &v[4];
  printf("%d\n", *n);
  return 0;
}
//可以變成
int main () {
  int v[5] = {1, 2, 3, 4, 5};
  int *n;
  //v[5]是不存在的，等於v+5，但是v[5]的位址是存在的
  for (n = v; n != &v[5]; n++) {
    printf("%d\n", *n);
  }
  return 0;
}
//等於
int main () {
  int v[5] = {1, 2, 3, 4, 5};
  int *n = v;
  while (n != &v[5]) {
    printf("%d\n", *n++);
  }
  return 0;
}
```
### 14.2.2 指標與下標運算子（[]）
```c
int v[5];
int *n = v;
//a[b]就是*(a+b)
n[0] = 0;//n[0]等於*(n+0)
v[0] = 0;//v[0]等於*(v+0)
0[v] = 0;//0[v]等於*(0+v)
n[0] == *n;//n[0] == *v;
n[1] == *(n+1);//n[1] == *(v+1);
n[2] == *(n+2);//n[2] == *(v+2);
```
### 14.2.3 在函式間傳遞陣列（使用指標）
```c
int maxv(int[]);

int main () {
  int a[3] = {3, 9, 7};
  printf("Max: %d\n", maxv(&a[0]));//maxv(a)隱性轉型成maxv(&a[0])
  return 0;
}

int maxv(int *v) {
  int max = *(v+0), i;//*(v+0)等於v[0]，存的是a[0]的值
  for (i = 1; i < 3; i++) {
    if (*(v+i) > max) {//*(v+1)等於v[1]，存的是a[1]的值
      max = *(v+i);
    }
  }
  return max;
}
//兩個陣列
int maxv(int[], int N);

int main () {
  int a[3] = {3, 9, 7};
  printf("Max: %d\n", maxv(a, 3));
  int b[5] = {3, 9, 1, 2, 7};
  printf("Max: %d\n", maxv(b, 5));
  return 0;
}

int maxv(int *v, int N) {
  int max = v[0], i;
  for (i = 1; i < N; i++) {
    if (v[i] > max) {
      max = v[i];
    }
  }
  return max;
}
```
### 14.2.4 指標與陣列的關係
- 指標儲存某陣列元素位址時的特殊性
  - 可以透過加減整數運算出同陣列其他元素的記憶體位址
    - 加N等於向後移動N個元素後的記憶體位址
    - 減N等於向前移動N個元素後的記憶體位址
  - a[b]運算等於*(a+b)，反之b[a]等於*(b+a)
    - 在該陣列中從a開始往後移動b所在的陣列元素
    - 當指標儲存某陣列第一個元素的記憶體位址時，用起來就跟該陣列一樣
- 陣列可以飲性轉型成該陣列第一個元素的記憶體位址
### 14.2.5 指標與遞增遞減運算子 
```c
//陣列歸零
int main () {
  int v[5];
  int *p;
  for (p = v; p != &v[5]; p++) {
    *p = 0;
  }
  /*
  while (p != v+5) {
    *p++ = 0;//*(p++) = 0;
  }
  */
  return 0;
}
```
## 14.3 指標與字串
```c
//在函式間傳遞字串
char strA[] = "test";
char strB[] = {'t', 'e', 's', 't', '\0'};

printf(strA);//隱性轉型成指標
printf(strB);//隱性轉型成指標

printf("test");//字串字面常數
printf({"t", "e", "s", "t", "\0"});//錯誤

char *strC = "test";//字串字面常數
char *strD = {'t', 'e', 's', 't', '\0'};//錯誤

printf((char[]){"t", "e", "s", "t", "\0"});//C99：複合字面常數
```
### 14.3.1 字串字面常數的特殊性
```c
char strA[] = "test";
char *strB = "test";//字串字面常數可隱性轉型成指標

strA[0] = 'T';//合法
strB[0] = 'T';//未定義行為

strA = "Test";//錯誤
strB = "Test";//合法
```
- strA[]  
  |strA[0]|strA[1]|strA[2]|strA[3]|strA[4]|
  |:-:|:-:|:-:|:-:|:-:|
  |'t'|'e'|'s'|'t'|'\0'|
- strB(char *)：只能讀取，不能寫入  
  |strB[0]|strB[1]|strB[2]|strB[3]|strB[4]|
  |:-:|:-:|:-:|:-:|:-:|
  |'t'|'e'|'s'|'t'|'\0'|
### 14.3.2 const修飾字
- 資料型態被const修飾的變數在「初始化」之外不能再被賦值
  - 在C語言裡可以刊成一個唯讀（read-only）的屬性
  ```c
  int a = 3;
  const int b = 5;
  const int c;//未定義行為
  a = 4;
  b = 6;//錯誤
  ```
- 對陣列元素使用const修飾字
  ```c
  int a[3] = {3, 4, 5};
  const int b[3] = {5, 6, 7};  
  a[0] = 4;
  b[0] = 6;//錯誤
  ```
### 14.3.3 字串字面常數與const char *
```c
char strA[] = "test";
const char *strB = "test";//字串字面常數可隱性轉型成指標

strA[0] = 'T';//合法
strB[0] = 'T';//錯誤

strA = "Test";//錯誤
strB = "Test";//合法
```
### 14.3.4 指標與const
```c
//Type * 可以轉成const Type *
char strA[] = "test";
char *strB = "test";
const char *strC = "test";

strA[0] = 'T';//合法
strB[0] = 'T';//未定義行為
strC[0] = 'T';//編譯失敗

strA = strB;//(x) (char []) = (char *)
strA = strC;//(x) (char []) = (const char *)
strB = strA;//(o) (char *) = (char [])
strB = strC;//(x) (char *) = (const char *)，從只能讀無法變成可讀可寫
//字元的陣列可以隱性轉型成字元指標，從可讀可寫變成只能讀
strC = strA;//(o) (const char *) = (char [])
strC = strB;//(o) (const char *) = (char *)
```
### 14.3.5 使用函式複製字串
- 複製字串函式：strcpy
  - char * strcpy(char *dest, const char *src);
    - 將src字串複製到dest字串
    - dest：目標字串
    - src：來源字串
    - 回傳值：dest
- 範例：
  ```c
  #include <string.h>
  //配置好空間才能複製
  int main () {
    const char *source = "test";//char source[5] = "test";
    //錯誤寫法：char *destination;
    char destination[5];//產生格子存取字元

    strcpy(destination, source);

    printf("%s\n", destination);//test
    return 0;
  }
  ```
### 14.3.6 指標陣列
- 陣列：  
  |v[0]|v[1]|v[2]|
  |:-:|:-:|:-:|
  |1(int)|2(int)|3(int)|
- 指標陣列：
  |p[0]|p[1]|p[2]|
  |:-:|:-:|:-:|
  |&v[0](int *)|&v[1](int *)|&v[2](int *)|
- 指標陣列的初始化
  ```c
  int v[3] = {1, 2, 3};
  int *p[3] = {&v[0], &v[1], &v[2]};
  //循序存取
  int i;
  for (i = 0; i < 3; i++) {
    *p[i] = 0;
  }
  //隨機存取
  *p[2] = 5;
  //也可以
  int a = 1, b = 2, c = 3;
  int *p[3] = {&a, &b, &c};
  //循序存取
  int i;
  for (i = 0; i < 3; i++) {
    *p[i] = 0;
  }
  //隨機存取
  *p[2] = 5;
  ```
- 指向陣列第一個元素的指標
  ```c
  int v[3] = {1, 2, 3};
  int *n = v;
  //循序存取
  int i;
  for (i = 0; i < 3; i++) {
    n[i] = 0;
  }
  //隨機存取
  *p[2] = 5;
  ```
- 不同陣列
  |a[0]|a[1]|b[0]|b[1]|c[0]|c[1]|
  |:-:|:-:|:-:|:-:|:-:|:-:|
  |1(int)|2(int)|3(int)|4(int)|5(int)|6(int)|

  |p[0]|p[1]|p[2]|
  |:-:|:-:|:-:|
  |&a[0](int *)|&b[0](int *)|&c[0](int *)|
  ```c
  //相同大小陣列
  int a[2] = {1, 2};
  int b[2] = {3, 4};
  int c[2] = {5, 6};
  int *p[3] = {a, b, c};
  //循序存取
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 2; j++) {
      p[i][j] = 0;
    }
  }
  //隨機存取
  p[2][0] = 7;//(&c[0])[0] = 7
  ```
  |a[0]|a[1]|a[2]|a[3]|b[0]|b[1]|c[0]|c[1]|
  |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
  |1(int)|2(int)|7(int)|8(int)|3(int)|4(int)|5(int)|6(int)|

  |p[0]|p[1]|p[2]|
  |:-:|:-:|:-:|
  |&a[0](int *)|&b[0](int *)|&c[0](int *)|
  ```c
  //不同大小陣列
  int a[4] = {1, 2, 7, 8};
  int b[2] = {3, 4};
  int c[3] = {5, 6};
  int *p[3] = {a, b, c};
  //循序存取
  int i, j;
  for (i = 0; i < 3; i++) {
    for (j = 0; j < 2; j++) {
      p[i][j] = 0;
    }
  }
  //隨機存取
  p[0][2] = 9;//(&a[0])[2] = 9
  p[1][2] = 10;//未定義行為，不能存取陣列範圍外的元素
  ```
### 14.3.7 陣列的指標
|v[3]|位址|
|:-:|:-:|
|{1, 2, 3}|int (*)[3]&v|  

|q|
|:-:|
|(int (*)[3])&v|
```c
int v[3] = {1, 2, 3};
int (*q)[3] = &v;//指向v的指標
//循序存取
int i;
for (i = 0; i < 3; i++) {
  (*q)[i] = 0;//(*q)[i]等於v[i]
}
//隨機存取
(*q)[2] = 5;//v[2] = 5
```
- 在函式間傳遞固定大小的陣列
  ```c
  void print(int (*q)[3]) {//代表整個陣列的位址
    int i;
    for (i = 0; i < 3; i++) {
      printf("%d\n", (*q)[i]);//(*q)[i]等於v[i]
    }
    printf("\n");
  }

  int main () {
    int v[3] = {1, 2, 3};
    print(&v);
    return 0;
  }
  //型態不同
  void print(int *n) {//代表陣列的第一個元素的位址
    int i;
    for (i = 0; i < 3; i++) {
      printf("%d\n", n[i]);
    }
    printf("\n");
  }

  int main () {
    int v[3] = {1, 2, 3};
    print(v);
    return 0;
  }
  ```
### 14.3.8 在函式間使用哪種指標傳遞陣列
|陣列編號|值|型態|
|:-:|:-:|:-:|
|v[0]|1|int|
|v[1]|2|int|
|v[2]|3|int|
|n|&v[0]：v[0]的位址|int *|
|p[0]|&v[0]|int *|
|p[1]|&v[1]|int *|
|p[2]|&v[2]|int *|
|q|&v|int (*)[3]|
```c
int v[3] = {1, 2, 3};
int *n = v;//整數陣列隱性轉型成整數指標，n只知道其中一個元素的位址
int *p[3] = {&v[0], &v[1], &v[2]};//指標陣列，每個元素都可以存v[0]陣列中的元素位址，順序可隨使用者調整
int (*q)[3] = &v;//q知道v是含有3個元素的陣列，可以存取整個陣列
```
- 用sizeof計算記憶體大小
  ```c
  int main () {
    int v[3] = {1, 2, 3};
    printf("%zu\n", sizeof(v));//sizeof(int[3])，12
    printf("%zu\n", sizeof(v[0]));//sizeof(int)，4
    printf("%zu\n", sizeof(&v[0]));//sizeof(int *)，8
    printf("%zu\n", sizeof(&v));//sizeof(int (*)[3])，8
  }
- 在函式間傳遞陣列
  ```c
  //如果要改變陣列v[3]大小，函式就需要改變
  void print(int (*q)[3]) {
    int i;
    //sizeof(*q)是整個陣列的大小，sizeof((*q)[0])是陣列中每個元素的大小
    //sizeof(*q)/sizeof((*q)[0])是陣列的元素個數
    for (i = 0; i < sizeof(*q)/sizeof((*q)[0]); i++) {
      printf("%d\n", (*q)[i]);
    }
    printf("\n");
  }

  int main () {
    int v[3] = {1, 2, 3};
    print(&v);
    return 0;
  }
  ```
### 14.3.9 指標間轉型的限制
- 大部分的情況下，指向不同型態的指標間是不能直接隱性轉型的
  ```c
  int intVar;
  double doubleVar;
  int intArray[3];

  int *intPointer = &doubleVar;//(x) (int *) != (double *)
  double *doublePointer = &intVar;//(x) (double *) != (int *)
  int **intPointerPointer1 = &intVar;//(x) (int **) != (int *)
  int **intPointerPointer2 = &intArray;//(x) (int **) != (int (*)[3])
  int **intPointerPointer3 = intArray;//(x) (int **) != (int [3])
  const int *c = &a;//(o) (const int *) = (int *)
  ```
### 14.3.10 合法的隱性轉型
- 合法的隱性轉型
```c
int intVar = 3;
char charVar = '3';
float floatVar = 3.5f;
double doubleVar = 3.5;
//同類型態內互轉（整數與整數間、浮點數與浮點數間）
floatVar = doubleVar;//(o) (float) = (double)
intVar = charVar;//(o) (int) = (char)
//整數與浮點數
intVar = doubleVar;//(o：無條件捨去) (int) = (double)
doubleVar = intVar;//(o) (double) = (int)
//陣列與指標
int v[3];
int *n;
const int *p;
//陣列可以隱性轉型成指向第一個元素的指標
n = v;//(o) (int *) = (int [3])
v = n;//(x) (int [3]) != (int *)
//Type * 可以轉成const Type *
p = n;//(o) (const int *) = (int *)
n = p;//(x) (int *) != (const int *)
//指標與指標
int main () {
  //void *與其他型態的指標「可能」可以互轉，其他大部分都是未定義行為
  int intVar = 3;
  void *voidPtr = &intVar;
  int *intPtr = voidPtr;
  printf("%d\n", *intPtr);
  return 0;
}
```
### 14.3.11 指標與整數間的轉型
- 指標是個儲存記憶體位址的資料型態
- 記憶體位址長怎樣？
  - 把記憶體想成一段連續的空間，以位元組為單位，替每個位元組獨一無二編號
  - 如何編編號？
    - 從0或1開始逐個加1？不能指定
- 哪些是可以的？
  - Type * <-> void *：轉過去再轉回來會一樣
  - Type * <-> int：不一定可以，需強制轉型。如果整數存得下則結果是實作定義，否則是未定義行為
  ```c
  int var = 3;
  int *pointer = &var;
  int pointerInt = (int)pointer;
  int *anotherPointer = (int *)pointerInt;//anotherPointer == pointer
  ```
  - 整數 -> Type *：不一定可以，需強制轉型，結果是實作定義
  ```c
  int *pointer = (int *)123;
  *pointer = 456;
  ```
  - TypeA <-> TypeB：不一定可以，需強制轉型，如果TypeB的對其較TypeA不嚴格則轉回來會一樣
### 14.3.12 指標與指標間的強制轉型
- 記憶體對齊
  - 例如：char對齊為1，int對齊為4，所以存char的位址不一定能存int
### 14.4.1 輸入任意個整數後一起印出（使用固定大小陣列）
- 範例：
  ```c
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
  ```
### 14.4.2 如何讓陣列變大？
- 遇到的問題
  - 陣列的大小在宣告定義的時候就已經決定了：陣列元素在記憶體中必須要連序擺放
    - 已經宣告定義好的陣列無法改變大小
- 需要變大的時候
  - 1.產生一個較大的新陣列
  - 2.將舊有的資料複製到新陣列
  - 3.用新陣列取代舊有的陣列
  ```c
  int main () {
    int num[0];//儲存輸入的數字//長度不能為0
    int length = 0;//目前已輸入的數字個數
    while (1) {//最多輸入10個數字
        int input;
        scanf("%d", &input);//從鍵盤輸入數字
        if (input == 0) break;//輸入0結束
        int larger[length + 1];//產生一個大一格的新陣列//C99後可以
        for (int i = 0; i < length; i++) {
            larger[i] = num[i];//將舊有的資料複製到新陣列
        }
        num = larger;//將num設為剛產生的新陣列//陣列不能放在賦值運算子左邊
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
  ```
### 14.4.3 用同一個指標指向不同的陣列
- 指標變數可改變所指向的陣列
  ```c
  int main () {
    int *numbers;
    int length = 0;

    int larger1[1] = {1};
    numbers = larger1;
    length++;
    for (int i = 0; i < length; i++) {
      printf("%d ", numbers[i]);//等於printf("%d ", larger1[i]);
    }
    printf("\n");

    int larger2[2] = {2, 3};
    numbers = larger2;
    length++;
    for (int i = 0; i < length; i++) {
      printf("%d ", numbers[i]);//等於printf("%d ", larger2[i]);
    }
    printf("\n");
    return 0;
  }
  ```
### 14.4.4 變數的生命週期
- 每個變數需要配置「專屬」的記憶體空間
  - 透過sizeof運算子可以得知需要多少空間（位元組）
  - 專屬表示該記憶體空間不會被挪用
  - 記憶體空間有限，用完了怎麼辦？有借有還，再借不難
- 自動變數的生命週期
  - 記憶體空間的配置：執行到進入變數可視範圍時
  - 記憶體空間的釋放：執行到離開變數可視範圍時
  ```c
  {//在變數可視範圍外的程式碼不可以使用該變數名稱存取變數
    int a;//配置記憶體
    //...
  }//釋放記憶體
  ```
### 14.4.5 使用自動變數所遇到的問題
```c
//存取已釋放的記憶體空間為未定義行為
int main () {
  int *num;
  int length = 0;
  while (1) {
    int input;
      scanf("%d", &input);
      if (input == 0) break;
      int larger[length + 1];//配置記憶體
      for (int i = 0; i < length; i++) {
        larger[i] = num[i];//透過num去存取的陣列已經被釋放了
      }
      num = larger;
      num[length] = input;
      length++;
  }//釋放記憶體
    
  printf("Numbers: ");
  for (int i = 0; i < length; i++) {
    printf("%d ", num[i]);//透過num去存取的陣列已經被釋放了
  }
  printf("\n");
  return 0;
}
```
### 14.4.6 動態配置記憶體
- 使用malloc函使動態配置記憶體
  - <stdlib.h>提供malloc函式讓使用者動態配置記憶體
  ```c
  void *malloc(size_t size);
  ```
  - size為非負整數型態（size_t），代表要配置的記憶體空間大小（位元組）
    - 可使用sizeof運算子取得需要配置多少記憶體空間
  - 回傳值為void *，代表可以隱性轉型成其他資料型態的指標
  ```c
  //使用malloc配置的記憶體不會自動釋放
  #include <stdlib.h>
  int main () {
    int *num;//儲存輸入的數字
    int length = 0;//目前已輸入的數字個數
    while (1) {
        int input;
        scanf("%d", &input);//從鍵盤輸入數字（假設依序輸入1, 2, 3,...）
        if (input == 0) break;//輸入0結束
        int *larger = malloc(sizeof(int) * (length + 1));//動態配置記憶體
        for (int i = 0; i < length; i++) {
          larger[i] = num[i];//複製舊陣列到新陣列
        }
        num = larger;//將num設為剛產生的新陣列
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
  ```
### 14.4.7 釋放動態配置的記憶體
- 記憶體洩漏：記憶體有借無還
- 使用free函式釋放動態配置的記憶體
  ```c
  void free(void *ptr);
  ```
  - ptr為要釋放的記憶體空間的位址
    - 該記憶體空間是由malloc或其他動態配置記憶體函式所配置的
  ```c
  //使用free釋放動態配置的記憶體
  #include <stdlib.h>
  int main () {
    int *num = 0;//0代表空指標（null）
    int length = 0;//目前已輸入的數字個數
    while (1) {
        int input;
        scanf("%d", &input);//從鍵盤輸入數字（假設依序輸入1, 2, 3,...）
        if (input == 0) break;//輸入0結束
        int *larger = malloc(sizeof(int) * (length + 1));//動態配置記憶體
        for (int i = 0; i < length; i++) {
          larger[i] = num[i];//複製舊陣列到新陣列
        }
        free(num);//釋放舊陣列的記憶體
        num = larger;//將num設為剛產生的新陣列
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
  ```
### 14.4.8 重新配置記憶體
- 使用realloc函式重新配置記憶體
  ```c
  void *realloc(void *ptr, size_t size);
  ```
  - ptr為要重新配置記憶體空間的位址
    - 原本由malloc或其他動態配置記憶體函式所配置的
  - size是重新配置後的記憶體空間大小（位元組）
  - 回傳值重新配置後的記憶體空間開頭位址
    - 有可能不需要搬家！會更有效率
  ```c
  //使用realloc重新配置記憶體
  #include <stdlib.h>
  int main () {
    int *num = 0;//0代表空指標（null）
    int length = 0;//目前已輸入的數字個數
    while (1) {
        int input;
        scanf("%d", &input);//從鍵盤輸入數字（假設依序輸入1, 2, 3,...）
        if (input == 0) break;//輸入0結束
        num = realloc(num, sizeof(int) * (length + 1));//重新配置記憶體
        num[length] = input;//將輸入數字加在最後面
        length++;//將輸入的數字個數加1
    }
    
    printf("Numbers: ");
    for (int i = 0; i < length; i++) {//數每個輸入的數字
      printf("%d ", num[i]);
    }
    printf("\n");
    free(num);//釋放記憶體
    return 0;
  }
  ```
### 14.5.1 在函式間傳遞二維陣列
```c
//無法把二維陣列變成一個指標
void print(int **v, int height, int width) {
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      printf("%d ", v[i][j]);
    }
    printf("\n");
  }
}

int main () {
  int v[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  print(v, 3, 3);//(x) (int **) != (int (*)[3])，已經隱性轉型一次，不能再轉
  return 0;
}
```
### 14.5.2 使用指標陣列傳遞二維陣列
```c
void print(int *v[], int height, int width) {
  int i, j;
  for (i = 0; i < height; i++) {
    for (j = 0; j < width; j++) {
      printf("%d ", v[i][j]);
    }
    printf("\n");
  }
}

int main () {
  int v[2][3] = {{1, 2, 3}, {4, 5, 6}};
  int *p[2] = {v[0], v[1]};//(int *) = (int [3])，等於(&v[0][0], &v[1][0])，p[0]儲存的是v[0]的位址，p[1]儲存的是v[1]的位址
  print(p, 2, 3);//(int **) = (int *[2])
  return 0;
}
```
- p陣列提供了v陣列的位址
### 14.5.3 在函式間傳遞任意長寬的二維陣列
- 在函式間傳遞一維陣列
  - 直接傳遞陣列的指標：存陣列的位址，不能改變陣列大小
    ```c
    void print(int (*v)[3]);
    ```
  - 隱性轉型後傳遞陣列第一個元素的指標與陣列長度：存陣列中第一個元素的位址，可以改變陣列大小
    ```c
    void print(int *v, int N);
    ```
- 在函式間傳遞二維陣列
  - 直接傳遞陣列的指標：存陣列的位址，不能改變陣列大小
    ```c
    void print(int (*v)[3][3]);
    ```
  - 隱性轉型後傳遞陣列第一個元素的指標與陣列長度：存陣列中第一個元素的位址，可以改變陣列大小，在第二維度不能有任意多個
    ```c
    void print(*v, int height, int width);
    ```
- 從傳入的width算出
  ```c
  void print(int *v, int height, int width) {
    int i, j;
    for (i = 0; i < height; i++) {
      for (j = 0; j < width; j++) {
        printf("%d ", *(v + i * width + j));
      }
      printf("\n");
    }
  }

  int main () {
    int v[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    //剛好可以強制轉型
    print((int *)v, 3, 3);//(int *) = (int *[3])
    return 0;
  }
  ```
## 14.6 儲存多個字串
- 使用二維陣列儲存多個字串
  ```c
  char strA[3][4] = {"How", "are", "you"};
  ```
  - strA：
    |字元|'H'|'o'|'w'|'\0'|
    |:-:|:-:|:-:|:-:|:-:|
    |位址|100|101|102|103|
    |字元|'a'|'r'|'e'|'\0'|
    |位址|104|105|106|107|
    |字元|'y'|'o'|'u'|'\0'|
    |位址|108|109|110|111|
    ```c
    //可以修改字串
    strA[2][0] = 'Y';//(o) char * = char *
    //不能修改整個字串
    strA[2] = "What";//(x) char * != char *
    strcpy(strA[0], "What");//(x) 字元數不夠
    ```
- 使用指標陣列儲存多個字串
  ```c
  const char *strB[3] = {"How", "are", "you"};
  ```
  - 型態：const char，不能被修改
    |字元|'H'|'o'|'w'|'\0'|
    |:-:|:-:|:-:|:-:|:-:|
    |位址|100|101|102|103|
    |字元|'a'|'r'|'e'|'\0'|
    |位址|104|105|106|107|
    |字元|'y'|'o'|'u'|'\0'|
    |位址|108|109|110|111|
  - strB：型態為const char *，指向'How'、'are'、'you'的開頭位址
    |位址|100|104|108|
    |:-:|:-:|:-:|:-:|
    ```c
    //不能修改字串
    strB[2][0] = 'Y';//(x) const char * != char *
    //可以改變整個字串
    strB[2] = "What";//(o) const char * = const char *
    //將原本指向'you'的指標改為指向'What'
    ```
## 14.7 可修改內容的多個字串
- strA：型態為char
  |字元|'H'|'o'|'w'|'\0'|
  |:-:|:-:|:-:|:-:|:-:|
  |位址|100|101|102|103|
  |字元|'a'|'r'|'e'|'\0'|
  |位址|104|105|106|107|
  |字元|'y'|'o'|'u'|'\0'|
  |位址|108|109|110|111|
- strB：型態為char *
  |位址|100|104|108|
  |:-:|:-:|:-:|:-:|
  ```c
  char strA[3][4] = {"How", "are", "you"};
  char *strB[3] = {strA[0], strA[1], strA[2]};
  strB[2][0] = 'Y';//(o) char * = char *
  char strC[5] = "What";
  strB[0] = strC;
  strB[0][0] = 'w';//(o) char * = char *
  ```
- strB修改後
  |位址|200|104|108|
  |:-:|:-:|:-:|:-:|
  指向->
  |字元|'W'|'h'|'a'|'t'|'\0'|
  |位址|200|201|202|203|204|  
### 14.7.1 輸入不定個數字串
- 範例：
  ```c
  //輸入不定個數字串
  //輸入多個字串後，印出使用者輸入的字串
  //輸入END結束輸入
  int main () {
    char str[100][5];
    char input[5];
    int len = 0;
    while (1) {
        scanf("%s", input);//不用加&
        if (strcmp(input, "END") == 0) break;//strcmp比較兩個字串是否相等
        strcpy(str[len], input);//將input複製到str[len]
        ++len;
    }
    printf("-------\n");
    int i;
    for(i = 0; i < len; i++) {
        printf("%s ", str[i]);
    }
    printf("\n");
    return 0;
  }
  ```
### 14.7.2 輸入不定個數字串的優化
```c
#include <string.h>
int main () {
  char raw[5000];
  char *str[100];
  char input[50];
  int size = 0;//目前已輸入的字元個數
  while (1) {
    scanf("%s", input);
    if (strcmp(input, "END") == 0) break;
    str[len] = &raw[size];//將raw[size]的位址存到str[len]
    strcpy(&raw[size], input);//將input複製到raw[size]
    size += strlen(input) + 1;//strlen計算字串長度，+1是為了'\0'
    ++len;
  }
  printf("-------\n");
  int i;
  for(i = 0; i < len; i++) {
    printf("%s ", str[i]);
  }
  printf("\n(%d, %d)\n", len, size);
  return 0;
}
```
## 14.8 函式指標
```c
//編譯失敗
int main () {
  void hello();
  void func() = hello;//函式型態不可以複製
  func();
  return 0;
}

void hello() {
  printf("Hello\n");
}
//指標型態可以複製
int main () {
  void hello();//宣告hello函式，型態為void
  void (*func)() = &hello;//宣告func指標，指向一個型態為void的函式
  (*func)();//呼叫func函式
  return 0;
}

void hello() {//定義hello函式
  printf("Hello\n");
}
```
### 14.8.1 函式指示符與其特殊性
- 函式與物件的不同
  - 在C語言中，函式跟物件是不同的概念但又有相似之處
    - 共用「名稱」的概念
      - 變數：可用來存取對應的特定物件
      - 函式名稱／指示符：可用來代表某個特定函式
    - 都可使用「指標」運算
      - 可對名稱取址（&）獲得指標值（T*）
      - 可用指標變數（T*）儲存位址
      - 對指標（T*）進行間接運算（*）可取得該位址代表的特定物件或特定函式
  ```c
  int main () {
    printf("Hello\n");//printf是函式名稱（name）也是函式指示符（designator）
    (&printf)("Hello\n");//&printf是函式指標，指向printf代表的函式
    (*printf)("Hello\n");//*printf是？本身不是函式指標
    return 0;
  }
  //在C語言中，函式（function）是透過函式指標呼叫的
  int main () {
    printf("Hello\n");//printf可自動隱性轉型成&printf
    (&printf)("Hello\n");//&printf是指向printf的函式指標，可透過（）近行函式呼叫
    (*printf)("Hello\n");//printf會自動轉型成&printf
    //*printf–>*&printf–>printf–>&printf
    return 0;
  }
  ```
### 14.8.2 函式指標相關運算的化簡
```c
void hello();//宣告hello函式，型態為void

int main () {
  void (*func)() = hello;//hello可自動轉型成&hello
  func();//呼叫func指標所指向的函式
  return 0;
}

void hello() {
  printf("Hello\n");
}
```
### 14.8.3 在函式間傳遞函式
```c
int add(int, int);//add是韓式指示符，型態為int (int, int)

int main () {
  int (*op)(int, int) = add;//op是函式指標，指向型態為int (int, int)的函式
  int result = op(3, 5);//呼叫op指標所指向的函式
  printf("%d\n", result);//8
  return 0;
}

int add(int a, int b) {
  return a + b;
}
//應用
int calculate(int (*)(int, int));
int add(int, int);
int multiply(int, int);

int main () {
  printf("%d\n", calculate(add));//1+2+3+4+5=15
  printf("%d\n", calculate(multiply));//1*2*3*4*5=120
  return 0;
}

int calculate(int (*op)(int, int)) {
  int result = 1;
  for (int i = 2; i <= 5; i++) {
    result = op(result, i);
  }
  return result; 
}

int add(int a, int b) {
  return a + b;
}

int multiply(int a, int b) {
  return a * b;
}
```
## 14.9 main函式的回傳值
### 14.9.1 main函式
- 由作業系統呼叫：main函式是C語言程式的進入點
  - 程式執行時會從main函式開始
  - main函式的回傳值代表程式的結束狀態
### 14.9.2 在程式內執行其他程式
- 使用system()函式可以執行其他程式，宣告於<stdlib.h>
  ```c
  int system(const char *command);
  ```
  - system()會執行檔案路徑為command的程式
    - system("hello.exe")會執行同一個目錄內叫做hello.exe的執行檔
      - 可以想成會呼叫hello.exe內的main函式
  - system()的回傳值就是所呼叫程式內main函式的回傳值
- 範例：執行自己寫的Hello world程式
  - 1.撰寫hello.cpp，編譯成hello.exe
  ```c
  //hello.cpp
  #include <stdio.h>
  int main () {
    printf("Hello world!\n");
    return 0;
  }
  //執行hello.exe，會印出Hello world!
  ```
  - 2.撰寫test1.cpp，編譯成test1.exe
  ```c
  //test1.cpp
  #include <stdlib.h>
  int main () {
    system("hello.exe");
    return 0;
  }
  ```
  - 3.執行test1.exe，會呼叫hello.exe，印出Hello world!
- 範例：印出自己寫的程式回傳值
  - 1.撰寫input.cpp，編譯成input.exe
  ```c
  //input.cpp
  #include <stdio.h>
  int main () {
    int N;
    scanf("%d", &N);
    return N - 1;
  }
  //執行input.exe，輸入3，回傳2
  ```
  - 2.撰寫test2.cpp，編譯成test2.exe
  ```c
  //test2.cpp
  #include <stdio.h>
  #include <stdlib.h>
  int main () {
    printf("%d\n", system("input.exe"));
    return 0;
  }
  ```
  - 3.執行test2.exe，會呼叫input.exe，輸入3，印出2
# 第十五章 結構
## 15.1 結構的定義與宣告
- 語法：
  ```c
  struct 結構名稱 {//定義結構
    型態1 成員名稱1;
    型態2 成員名稱2;
    ...
  };
  ```
  - 結構名稱：自訂的名稱
  - 成員名稱：結構內的變數名稱
- 宣告結構變數
  ```c
  struct 結構名稱 變數名稱 變數1, 變數2, ...;
  //合併後
  struct 結構名稱 {//定義結構
    型態1 成員名稱1;
    型態2 成員名稱2;
    ...
  } 變數1, 變數2, ...;//宣告結構變數
  ```
## 15.1.1 結構成員存取運算子（點號運算子「.」）
- 語法：
  ```c
  結構變數名稱.成員名稱
  ```
- 範例：
  ```c
  int main (void) {
    struct data {
      char name[10];
      int math;
    } student;

    printf("Name: ");
    gets(student.name);
    printf("Math: ");
    scanf("%d", &student.math);

    printf("Name: %s\n", student.name);
    printf("Math: %d\n", student.math);

    return 0;
  }
  ```
# 第十六章 位元處理
## 16.1 二進位系統
### 16.1.1 二進位轉十進位
- 數字89等於89/2=44餘1，44/2=22餘0，22/2=11餘0，11/2=5餘1，5/2=2餘1，2/2=1餘0，1/2=0餘1
  - 89 = 1011001
### 16.1.2 十進位轉二進位
- 1011001 = 1 * 2^6 + 0 * 2^5 + 1 * 2^4 + 1 * 2^3 + 0 * 2^2 + 0 * 2^1 + 1 * 2^0 = 89
- 範例：
  ```c
  #define size 8

  void show_binary(int);
  int main (void) {
    printf("89的二進位為： ");
    show_binary(89);
    return 0;
  }

  void show_binary(int num) {
    int i, b[size]={0};
    for(i = 1, i < size, i++) {
      b[size - i] = num % 2;
      num /= 2;
    }
    for(i = 0; i < size; i++) {
      printf("%d\n", b[i]);
    }
  }
  ```
## 16.2 其他的進位系統
### 16.2.1 八進位系統
- 以8為基底的進位系統
  - 0, 1, 2, 3, 4, 5, 6, 7, 10, 11, 12, 13, 14, 15, 16, 17, 20, ...
  - 346 = 3 * 8^2 + 4 * 8^1 + 6 * 8^0 = 230
  |八進位|0|1|2|3|4|5|6|7|
  |:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|:-:|
  |二進位|000|001|010|011|100|101|110|111|
### 16.2.2 十六進位系統
- 以16為基底的進位系統
  |十進位|二進位|八進位|十六進位|
  |:-:|:-:|:-:|:-:|
  |0|0000|0|0|
  |1|0001|1|1|
  |2|0010|2|2|
  |3|0011|3|3|
  |4|0100|4|4|
  |5|0101|5|5|
  |6|0110|6|6|
  |7|0111|7|7|
  |8|1000|10|8|
  |9|1001|11|9|
  |10|1010|12|A|
  |11|1011|13|B|
  |12|1100|14|C|
  |13|1101|15|D|
  |14|1110|16|E|
  |15|1111|17|F|
## 16.3 位元運算子
### 16.3.1 位元運算子
- 位元運算子：共有4種，分別為NOT、AND、OR、XOR
  |位元邏輯運算子|意義|
  |:-:|:-:|
  |~|NOT|
  |&|AND|
  |\||OR|
  |^|XOR|
  - NOT運算子「~」：將位元顛倒
    |a|~a|
    |:-:|:-:|
    |0|1|
    |1|0|
  - AND運算子「&」：兩者皆為1時為1，否則為0
    |a|b|a & b|
    |:-:|:-:|:-:|
    |0|0|0|
    |0|1|0|
    |1|0|0|
    |1|1|1|
    - 範例：
      ```c
      int main () {
        int a = 105, b = 26;
        printf("%d & %d = %d\n", a, b, a & b);//計算a&b
        return 0;
      }
      ```
  - OR運算子「|」：兩者皆為0時為0，否則為1
    |a|b|a \| b|
    |:-:|:-:|:-:|
    |0|0|0|
    |0|1|1|
    |1|0|1|
    |1|1|1|
  - XOR運算子「^」：兩者相同時為0，不同時為1
    |a|b|a ^ b|
    |:-:|:-:|:-:|
    |0|0|0|
    |0|1|1|
    |1|0|1|
    |1|1|0|
### 16.3.2 位元位移運算子
- C語言提供「左移」、「右移」運算子
  |位元位移運算子|意義|
  |:-:|:-:|
  |num << n|左移，將num的位元向左移n位|
  |num >> n|右移，將num的位元向右移n位|
  - 左移運算子「<<」：將num的位元向左移n位
    - 範例：
      ```c
      #include <stdio.h>
      #include <stdlib.h>
      #define SIZE 8
      void show_binary(int);
      int main (void) {
        int a;
        a = (89 << 1);//將89向左移1位，然後設定給變數a存放

        printf("89的二進位為： ");//01011001
        show_binary(89);
        printf("左移一位後： ");//10110010
        show_binary(a);
        printf("左移一位後的十進位： %d\n", a);//178
        return 0;
      }

      void show_binary(int num) {
        int i, b[size]={0};
        for(i = 1, i <= size, i++) {
          b[size - i] = num % 2;
          num /= 2;
        }
        for(i = 0; i < size; i++) {
          printf("%d\n", b[i]);
        }
      }
      ```
  - 右移運算子「>>」：將num的位元向右移n位
## 16.4 位元欄位
- 位元欄位：能充分使用到結構變數中的每一個位元
  ```c
  struct 位元欄位結構的名稱 {
    資料型態 欄位名稱1 : 位元長度;
    資料型態 欄位名稱2 : 位元長度;
    ...
    資料型態 欄位名稱n : 位元長度;
  };
  ```
- 範例：
  ```c
  int main(void) {
    struct status {
    unsigned sex: 1;
    unsigned marriage: 1;
    unsigned age: 7;
    };
    struct status tom = {1, 0, 25};

    if(tom.sex == 0)
      printf("性別：女,");
    else
      printf("性別：男,");

    if(tom.marriage == 0)
      printf("未婚,");
    else
      printf("已婚,");
    
    printf("%d歲\n", tom.age);
    printf("sizeof(tom)=%d\n", sizeof(tom));
    return 0;
  }
  ```