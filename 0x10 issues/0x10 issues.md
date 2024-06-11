# 0x10個問題
## 預處理器(Preprocessor)
### 第一個問題：用#define定義一年的秒數
- Using the #define statement, how would you declare a maifest constant that returns the number of seconds in a year?Disregard leap years.  
  
  使用#define，如何宣告常數來回傳一年秒數數量？忽略閏年。
  ```c
  #define SECONDS_PER_YEAR (60UL * 60UL * 24UL * 365UL)
  ```
- 可以觀察到幾件事情：
  - (a) Basic knowledge of the #define syntax (i.e. no semi-colon at the end, the need to parenthesize etc.).  
  
    對於#define語法的基礎知識(例如: 不需要在尾端加分號，對括號的需求等)
  - (b) A good choice of name, with capitalization and underscores.  
    
    選擇好的名子，包含大寫以及底線
  - (c) An understanding that the pre-processor will evaluate constant expressions for you. Thus, it is clearer, and penalty free to spell out how you are calculating the number of seconds in a year, rather than actually doing the calculation yourself.  
    
    了解到預處理器會去計算常數運算式。所以簡潔、無誤的拼出你是如何計算一年的秒數的數量，而不是真正的由你自己計算
  - (d) A realization that the expression will overflow an integer argument on a 16 bit machine — hence the need for the L, telling the compiler to treat the expression as a Long.  
    
    理解到運算式可能會在一個16 bit的機器上對整數產生溢位，因此需要L，告訴編譯器對待運算式為Long
  - (e) As a bonus, if you modified the expression with a UL (indicating unsigned long), then you are off to a great start because you are showing that you are mindful of the perils of signed and unsigned types — and remember, first impressions count!  
    
    另外，如果你更改運算式為UL(意指unsigned long)，你會有一個好的開始，因為注意到signd與unsigned型態的危險
- 範例：
  ```c
  #include <stdio.h>
  #define SECONDS_PER_YEAR (60UL * 60UL * 24UL * 365UL)

  int main() {
    printf("%lu\n", SECONDS_PER_YEAR);
    return 0;
  }
  //output: 31536000
  ```
### 第二個問題：用marco寫函數比大小
- Write the ‘standard’ MIN macro. That is, a macro that takes two arguments and returns the smaller of the two arguments.  
  
  寫一個標準的MIN macro。也就是說，一個macro接收兩個參數並且回傳這兩個參數中較小的那個
  ```c
  #define MIN(A,B) ((A) <= (B) ? (A) : (B))
  ```
- 這個問題的目的是為了測試以下項目：
  - (a) Basic knowledge of the #define directive as used in macros. This is important, because until the inline operator becomes part of standard C, macros are the only portable way of generating inline code. Inline code is often necessary in embedded systems in order to achieve the required performance level.  
  
    對#defince指令用在macros中的基礎知識。因為直到inline operator變成standard C的一部分之前，macros是唯一的可攜式的方式來產生inline code。Inline code在嵌入式系統通常是必要的，為了要達到要求的性能水平
  - (b) Knowledge of the ternary conditional operator. This exists in C because it allows the compiler to potentially produce more optimal code than an if-then-else sequence. Given that performance is normally an issue in embedded systems, knowledge and use of this construct is important.  
    
    三元運算子的知識。這個在C語言中的存在因為它允許編譯器有潛力的製作比if-then-eles更佳的程式。鑒於性能是一個在嵌入式系統很平常的問題，這方面的知識以及使用這個構造是重要的。
  - (c) Understanding of the need to very carefully parenthesize arguments to macros.  
    
    在macros需要非常小心的加括號
  - (d) I also use this question to start a discussion on the side effects of macros, e.g. what happens when you write code such as :  
    
    我也會使用這個問題來開始一個討論在macros的副作用，例如: 當你寫程式像這樣會發生什麼?
    ```c
    least = MIN(*p++, b);
    ```
- 範例：
  ```c
  #include <stdio.h>
  #define MIN(A,B) ((A) <= (B) ? (A) : (B))

  int main() {
    printf("%d\n", MIN(3, 7));
    return 0;
  }
  //output: 3
  int main() {
    int a[3] = {3, 4, 5};
    int *p = &a;
    printf("least value: %d\n", MIN(*p++, 7));
    //output: least value: 4
    printf("current value: %d\n", *p);
    //output: current value: 5，代表位址已經移動兩個整數
    return 0;
  }
  ```
  - 使用了least = MIN(*p++, b);，會造成原本的位置被偏移了兩次，而進行比較的數值，是偏移一次的結果。如果是使用變數而不是陣列的話，會產生不可預期的錯誤，因為我們並沒有對偏移一個整數與兩個整數位置的地方初始化
### 第三個問題：#error指令的目的
- What is the purpose of the preprocessor directive #error?  
  
  預處理指令#error的目的是什麼?  
  
  Either you know the answer to this, or you don’t. If you don’t, then see reference 1. This question is very useful for differentiating between normal folks and the nerds. It’s only the nerds that actually read the appendices of C textbooks that find out about such things. Of course, if you aren’t looking for a nerd, the candidate better hope she doesn’t know the answer.  
  
  你可能會知道或不知道如何回答這題。如果不知道，可以看reference 1。這題是來區分normal folks與nerds。只有nerds會實際的去讀C教科書的附錄並且找到相關的東西。當然，如果你不想找到nerds，面試者最好希望自己不知道這題的答案。
  - 原文附的reference 1：In Praise of the #error directive. ESP September 1999.
  - #error預處理：
    - 生成編譯錯誤的訊息，然後會停止編譯，可以用在檢查程式是否是照自己所預想的執行。例如說我們可以可以我們可以在程式碼加些#ifndef，如果偵測到沒有被define，我們就可以出現使用#error訊息中止程式
  - 範例：
  ```c
  //沒#define NUM1的情況下，使用了#ifndef NUM1，然後就印出#error訊息: No defined NUM1
  #include <stdio.h>

  int main() {
  #ifndef NUM1
    #error No defined NUM1
  #endif 
    printf("%d\n", NUM1);
    return 0;
  }
  //定義NUM1
  #include <stdio.h>
  #define NUM1 5

  int main() {
  #ifndef NUM1
    #error No defined NUM1
  #endif 
    printf("%d\n", NUM1);
    return 0;
  }
  //output: 5
  ```
## 無窮迴圈(Infinite Loops)
### 第四個問題：無窮迴圈
- Infinite loops often arise in embedded systems. How does one code an infinite loop in C?  
  
  無窮迴圈常出現在嵌入式系統。如何用C寫一行無窮迴圈的程式？
- There are several solutions to this question. My preferred solution is:  
  
  有多種方法來解答這提問題，我比較喜歡的解法是：
  ```c
  while(1) {
    //do something
  }
  ```
- Another common construct is:  
    
  另一個常見的構造是：
  ```c
  for(;;) {
    //do something
  }
  ```
  Personally, I dislike this construct because the syntax doesn’t exactly spell out what is going on. Thus, if a candidate gives this as a solution, I’ll use it as an opportunity to explore their rationale for doing so. If their answer is basically — ‘I was taught to do it this way and I have never thought about it since’ — then it tells me something (bad) about them. Conversely, if they state that it’s the K&R preferred method and the only way to get an infinite loop passed Lint, then they score bonus points.  
    
    我不喜歡這種結構因為這個語法沒有精確的拼出發生什麼事。因此，如果一個被面試的人給出這個解法，我會使用這個當成一個機會來探索用這個合理的原因。如果他們的答案基本上是 — 「我被教使用這種方法，而且之前我從來沒有想過關於它」 — 然後告訴我一些關於它們事情(不好的)。相反的，如果他們描述說這是K&R喜歡用的方式，並且是為一個方法來達成無窮迴圈且通過Lint。
- A third solution is to use a goto:  
  
  第三個解法是使用goto:
  ```c
  start: goto start;
  ```
## 資料宣告(Data Declarations)
### 第五個問題：資料宣告
- Using the variable a, write down definitions for the following:  
    
    使用變數a，寫下下列的定義
  - (a) An integer: 一個整數
    - int a;
  - (b) A pointer to an integer: 一個指向整數的指標
    - int *a;
  - (c) A pointer to a pointer to an integer: 一個指向指標的指標，它指向的指標是指向一個整數
    - int **a;
  - (d) An array of ten integers: 一個有十個整數的陣列
    - int a[10];
  - (e) An array of ten pointers to integers: 一個有十個指標的陣列，該指標是指向一個整數型的
    - int *a[10];
  - (f) A pointer to an array of ten integers: 一個指向有十個整數型陣列的指標
    - int (*a)[10];
  - (g) A pointer to a function that takes an integer as an argument and returns an integer: 一個指向函數的指標，該函數有一個整數型參數並返回一個整數
    - int (*a)(int);
  - (h) An array of ten pointers to functions that take an integer as an argument and return an integer: 一個有十個指標的陣列，該指標指向一個函數，該函數有一個整數型參數並返回一個整數
    - int (*a[10])(int);
  - 範例：
    - int *a[10]:
      ```c
      #include <stdio.h>

      int main() {
        int *a[3];
        int b = 20, c = 40, d = 60;
    
        a[0] = &b;
        a[1] = &c;
        a[2] = &d;

        printf("*a[0]: %d\n", *a[0]);//output: 20
        printf("*a[1]: %d\n", *a[1]);//output: 40
        printf("*a[2]: %d\n", *a[2]);//output: 60
        return 0;
      }
      //對每個指標加1
      #include <stdio.h>

      int main() {
        int *a[3];
        int b = 20, c = 40, d = 60;
    
        a[0] = &b;
        a[1] = &c;
        a[2] = &d;

        printf("*a[0]: %d\n", *a[0]);//output: 20
        printf("*a[1]: %d\n", *a[1]);//output: 40
        printf("*a[2]: %d\n", *a[2]);//output: 60
    
        (*a[0])++;
        (*a[1])++;
        (*a[2])++;

        printf("*a[0]: %d and b is %d\n", *a[0], b);//output: 21
        printf("*a[1]: %d and c is %d\n", *a[1], c);//output: 41
        printf("*a[2]: %d and d is %d\n", *a[2], d);//output: 61
        return 0;
      }
      ```
    - int (*a)[10]:
      ```c
      #include <stdio.h>

      int main() {
        int (*a)[3];
        int b[2][3]={{1,2,3},{4,5,6}};

        a = b;

        printf("%d\n", *(*a));//output: 1
        printf("%d\n", *(*a+1));//output: 2
        printf("%d\n", *(*a+2));//output: 3
      
        printf("%d\n", *(*(a+1)));//output: 4
        printf("%d\n", *(*(a+1)+1));//output: 5
        printf("%d\n", *(*(a+1)+2));//output: 6
        return 0;
      }
      ```
    - int (*a)(int):
      ```c
      #include <stdio.h>

      int func(int num) {
        return num;
      }

      int main(int argc, char* argv[]) {
        int (*a)(int) = func;
        //use function pointer
        printf("%d\n", a(10));//output: 10
        return 0;
      }
      ```
    - int (*a[10])(int):
      ```c
      #include <stdio.h>

      int b(int num) {
        return 2*num;
      }

      int c(int num) {
        return 3*num
      }

      int d(int num) {
        return 4*num
      }

      int main(int argc, char* argv[]) {
        int (*a[3])(int);

        a[0] = b;
        a[1] = c;
        a[2] = d;

        printf("%d\n", a[0](1));//output: 2
        printf("%d\n", a[1](1));//output: 3
        printf("%d\n", a[2](1));//output: 4
        return 0;
      }
      ```
## Static
### 第六個問題：Static的用法
- What are the uses of the keyword static?  
  - (a) A variable declared static within the body of a function maintains its value between function invocations.  
  
    在函數裡面的被宣告為static的變數會在函數呼叫之間維持它的數值
  - (b) A variable declared static within a module [1], (but outside the body of a function) is accessible by all functions within that module. It is not accessible by functions within any other module. That is, it is a localized global.  
  
    一個變數在一個module內被宣告為static，(但是在函數的body之外)是可以被在同一個module內的所有的函數存取的。在其他module中的函數不能存取。也就是說，這是個區域變數。
  - (c) Functions declared static within a module may only be called by other functions within that module. That is, the scope of the function is localized to the module within which it is declared.  
    
    在一個module內宣告為static的函數只可以被其他同一個module內的其他函數呼叫。也就是說，這個函數的範圍對它所宣告在的module而言是區域性的。
  - 範例：
    1. 在修飾變數的時候，static修飾的靜態區域變數只執行初始化一次，而且延長了區域變數的生命週期，直到程式運行結束以後才釋放。
      ```c
      #include <stdio.h>

      int func();

      int main() {
        func();
        func();
        return 0;
      }

      int func() {
        static int a = 0;
        a++;
        printf("%d\n", a);//output: 1 2
      }
      ```
    2. static修飾全域變數的時候，這個全域變數只能在本檔中訪問，不能在其它檔中訪問，即便是extern外部聲明也不可以。
      ```c
      //宣告變數num
      int num = 20;
      //創立另一個檔案將這個變數印出來
      #include <stdio.h>

      int main() {
        extern int num;
        printf("%d\n", num);//output: 20
        return 0;
      }
      //變成static
      static int num = 20;
      //在編譯時會出現錯誤: undefined reference to `num'
      ```
    3. static 修飾一個函數，則這個函數的只能在本檔中調用，不能被其他檔調用。
      ```c
      //宣告header和C檔，來宣告一個函數func()，並回傳值10
      //C檔
      int func();
      //header檔
      #include "Embedded_system_0x10_issues_0x6_4.h"

      int func() {
        return 10;
      }
      //接著再宣告一個檔案印出這個函數的回傳值
      #include <stdio.h>
      #include "Embedded_system_0x10_issues_0x6_4.h"

      int func();

      int main() {
        printf("%d\n", func());//output: 10
        return 0;
      }
      //如果將Embedded_system_0x10_issues_0x6_4.h的func()改成static
      #include "Embedded_system_0x10_issues_0x6_4.h"

      static int func() {
        return 10;
      }
      //在編譯時會出現錯誤: undefined reference to `func'
      ```
## Const
### 第七個問題：Const的用法
- What does the keyword const mean?
  - As soon as the interviewee says ‘const means constant’, I know I’m dealing with an amateur. Dan Saks has exhaustively covered const in the last year, such that every reader of ESP should be extremely familiar with what const can and cannot do for you. If you haven’t been reading that column, suffice it to say that const means “read-only”. Although this answer doesn’t really do the subject justice, I’d accept it as a correct answer. (If you want the detailed answer, then read Saks’ columns — carefully!).  
  
    當應試者回答說「const就是常數」，我知道我會認為他們是業餘的。Dan Saks去年已經辛苦的概括const，因此每一個ESP(Embedded System Programming)的讀者應該要很熟悉const對你而言可以做什麼以及不能做什麼。如果你還沒有讀到這個專欄，只要說const代表「read-only」就夠了。雖然這個答案並不是完全，但我接受它是一個正確的答案。(如果你想要知道更詳細的答案，那仔細的就去讀Saks的專欄)
  - There are several uses
    - const int a;
    - int const a;
    - const int *a;
    - int * const a;
    - int const * a const;  
    
      The first two mean the same thing, namely a is a const (read-only) integer. The third means a is a pointer to a const integer (i.e., the integer isn’t modifiable, but the pointer is). The fourth declares a to be a const pointer to an integer (i.e., the integer pointed to by a is modifiable, but the pointer is not). The final declaration declares a to be a const pointer to a const integer (i.e., neither the integer pointed to by a, nor the pointer itself may be modified).  
      
      前兩個代表同一件事情，也就是說a是個const(read-only)整數。第三個代表a是個指向const int的指標(意即，整數無法修改，但是指標可以)。第四個宣告a是個指向整數的const指標(意即，被指到的整數可以修改，但是指標沒辦法)。最後一個宣告a是代表const指標指到const integer(意即，被a指到的整數，或者是指標本身都無法修改)
  - Incidentally, one might wonder why I put so much emphasis on const, since it is very easy to write a correctly functioning program without ever using it. There are several reasons:
    - (a) The use of const conveys some very useful information to someone reading your code. In effect, declaring a parameter const tells the user about its intended usage. If you spend a lot of time cleaning up the mess left by other people, then you’ll quickly learn to appreciate this extra piece of information. (Of course, programmers that use const, rarely leave a mess for others to clean up...)  
    
      使用 const 概括一些非常有用的資訊對那些正在讀你程式的人。實際上，宣告一個 parameter const 會告訴使用者關於它的預期使用。如果你付了很多時間在清理其他人留下的混亂，你將會更快的學到感謝這個多餘的訊息。(當然，程式設計師使用 const ，很少會留下混亂給其他人清理)
    - (b) const has the potential for generating tighter code by giving the optimizer some additional information.
    
      Const有潛力產生更緊湊的程式碼藉由給予優化器一些附加資訊
    - (c) Code that uses const liberally is inherently protected by the compiler against inadvertent coding constructs that result in parameters being changed that should not be. In short, they tend to have fewer bugs.
      
      使用const的程式碼自然的是固有的被編譯器保護來對抗不注意的程式結構導致不該改變的參數被改變。簡而言之，它們傾向擁有更少的bug
  - 範例：
    1. const int a;
      ```c
      #include <stdio.h>
    
      int main() {
        const int a = 0;
        a = 20;
        printf("%d\n", a);
        return 0;
      }
      //無法改變變數a的值
      ```  
    2. int const a;
      ```c
      #include <stdio.h>

      int main() {
        int const a = 0;;
        a = 20;
        printf("%d\n", a);
        return 0;
      }
      //無法改變變數a的值
      ```  
    3. const int *a;
      ```c
      #include <stdio.h>
    
      int main() {
        const int *a;
        int b = 7;
        a = &b;

        *a = 8;

        printf("%d\n", *a);
        return 0;
      }
      //無法改變指標a指向的值
      //可以更改指到的變數，讓*a指到b，印出b的值，接著讓*a指到c，印出c的值
      #include <stdio.h>

      int main() {
        const int *a;
        int b = 7;
        a = &b;
        printf("%d\n", *a);//output: 7
      
        int c = 8;
        a = &c;
        printf("%d\n", *a);//output: 8
        return 0;
      }
      ```
    4. int * const a;
      ```c
      #include <stdio.h>

      int main() {
        int b = 7;
        int * const a = &b;
        printf("Before modification: %d\n", *a);//output: 7

        *a = 8;
        printf("After modification: %d\n", *a);//output: 8
        return 0;
      }
      //如果讓*const a指到其他變數
      #include <stdio.h>

      int main() {
        int b = 7;
        const int * const a = &b;

        *a = 8;
        printf("%d\n", *a);
        return 0;
      }
      //結果為不能修改
      ```
    5. int const * a const;
      ```c
      #include <stdio.h>

      int main() {
        int b = 7;
        const int * const a = &b;
        printf("%d\n", *a);//output: 7
        return 0;
      }
      //更改*a的數值為8
      #include <stdio.h>

      int main() {
        int b = 7;
        const int * const a = &b;
        printf("%d\n", *a);//output: 7

        *a = 8;
        printf("%d\n", *a);//無法更改
        return 0;
      }
      //更改*a指到的變數
      #include <stdio.h>

      int main() {
        int b = 7;
        const int * const a = &b;

        int c = 8;
        a = &c;
        printf("%d\n", *a);//無法更改
        return 0;
      }
      ```
## Volatile
### 第八個問題：Volatile的用法
- What does the keyword volatile mean? Give three different examples of its use.
  - A volatile variable is one that can change unexpectedly. Consequently, the compiler can make no assumptions about the value of the variable. In particular, the optimizer must be careful to reload the variable every time it is used instead of holding a copy in a register. Examples of volatile variables are:  
    
    一個 volatile 變數會被不可預期的改變。因此，編譯器可以使這個變數沒有假設。具體來說，編譯器會小心的重載這個變數當這個變數每次被使用時，而不是保存一份拷貝在編譯器中。Volatile變數的範例如下:
    - (a) Hardware registers in peripherals (e.g., status registers)  
    
      周邊設備的硬體暫存器 (如: 狀態暫存器)
    - (b) Non-stack variables referenced within an interrupt service routine.  
    
      中斷程式routine會訪問到的 Non-statck 變數
    - (c) Variables shared by multiple tasks in a multi-threaded application.  
      
      多執行緒應用中多個任務共享的變數
  - If a candidate does not know the answer to this question, they aren’t hired. I consider this the most fundamental question that distinguishes between a Non-automatic variables and an ‘embedded systems programmer’. Embedded folks deal with hardware, interrupts, RTOSes, and the like. All of these require volatile variables. Failure to understand the concept of volatile will lead to disaster.
      
      如果一個應試者不知道這個問題的答案，他們不會被錄取。我認為這是區分「C語言程式設計師」和「嵌入式系統程式設計師」之間最基本的問題。嵌入式系統需要處理硬體、中斷、RTOSes等等。所有這些都需要volatile變數，不理解volatile的概念將會導致災難。  
  - On the (dubious) assumption that the interviewee gets this question correct, I like to probe a little deeper, to see if they really understand the full significance of volatile. In particular, I’ll ask them the following:
    - (a) Can a parameter be both const and volatile? Explain your answer.  
      - Yes. An example is a read only status register. It is volatile because it can change unexpectedly. It is const because the program should not attempt to modify it.
        
        可以的。一個範例是一個唯獨的status register。它是volatile因為它可以不可預期的改變。它是const因為程式不應該企圖改變它。
    - (b) Can a pointer be volatile? Explain your answer.  
      - Yes. Although this is not very common. An example is when an interrupt service routine modifies a pointer to a buffer.  
      
        可以的。雖然這並不普遍。一個例子是中斷服務routine改變一個指向 buffer的指標
    - (c)What is wrong with the following function?
      ```c
      int square(volatile int *ptr) {
        return *ptr * *ptr;
      }
      ```
      - This one is wicked. The intent of the code is to return the square of the value pointed to by *ptr. However, since *ptr points to a volatile parameter, the compiler will generate code that looks something like this:  
        
        這個程式的意圖是為了回傳被 *ptr 指到的數的平方。然而，因為 *ptr 指到的是 volatile parameter，編譯器會產生看起來像是以下的程式碼：
        ```c
        int square(volatile int *ptr) {
          int a,b;
          a = *ptr;
          b = *ptr;
          return a * b;
        }
        ```
        Since it is possible for the value of *ptr to change unexpectedly, it is possible for a and b to be different. Consequently, this code could return a number that is not a square! The correct way to code this is:  
          
          因為 *ptr 有可能不可預期的改變，很有可能 a 與 b 會是不同的。所以，這個程式碼可能會回傳布是平方的數值。正確寫法的程式碼應該要像是：
        ```c
        long square(volatile int *ptr) {
          int a;
          a = *ptr;
          return a * a;
        }
        ```
## 位元操作(Bit Manipulation)
### 第九個問題：Bit操作
- Embedded systems always require the user to manipulate bits in registers or variables. Given an integer variable a, write two code fragments. The first should set bit 3 of a. The second should clear bit 3 of a. In both cases, the remaining bits should be unmodified.  

  嵌入式系統總是需要使用者去操作暫存器或變數的位元。給定一個整數變數a，寫下兩個程式碼片段。第一個應該設定a的第三位元。第二個應該清除a的第三位元。在這兩種情況下，其餘的位元應該是不變的。  
  1. Use bit fields. Bit fields are right up there with trigraphs as the most brain-dead portion of C. Bit fields are inherently non-portable across compilers, and as such guarantee that your code is not reusable.  
    
      使用位元欄。位元欄與三元運算符一樣是C中最腦死的部分。位元欄在不同的編譯器間是不可移植的，因此保證你的程式碼是不可重複使用的。
  2. Use #defines and bit masks. This is a highly portable method, and is the one that should be used. My optimal solution to this problem would be:  
    
      使用 #defines與bit masks。這是個高度可移植的方法，而且也是個該使用的方法。我對這題的最佳解是：
      ```c
      #define BIT3 (0x1 << 3)

      static int a;

      void set_bit3(void) {
        a |= BIT3;
      }

      void clear_bit3(void) {
        a &= ~BIT3;
      }
      ```
  Some people prefer to define a mask, together with manifest constants for the set & clear values. This is also acceptable. The important elements that I’m looking for are the use of manifest constants, together with the |= and &= ~ constructs.  
    
  有些人喜歡定義mask，與明白的常數對set & clear數值。這也是可接受的。重點是我要看到明白的常數與使用 |= 以及 &= ~結構。
- Set Bit:
  - 假定現在有一個變數a為0，要設定第3的位元為1，那這個時候，就讓它|= (1 << 3)，也就是說去|= 1向左位移3個位元的數，也就是說a這個數值要去| 100這個數，就是下方這個結果
    ```c
    000 | 100 = 100
    ```
    由於是|=，這個數值就會賦予給a
    ```c
    //a |= (1 << n)，n為要設定的位元
    #include <stdio.h>

    int main() {
      int a = 0;
      a |= (1 << 3);
      printf("%d\n", a);//output: 8
      return 0;
    }
    ```
- Clear Bit:
  - 假設現在設定了第三個位元，如果現在想要清掉第三個位元的話，該如何實作?這裡int是32位元，這裡只呈現一開始的8位元，來簡化說明，a現在的二進位是00000100，我們如果讓一個1的數值，同樣也向左位移3位元，也就是00000100，然後這時候反轉，則數值會變為11111011，這時候再&起來，則就可以清除掉第3個位元
    ```c
    //a為32位元，這裡只呈現8位元
    00000100 & 11111011 = 00000000
    ```
    由於是&=，這個數值就會賦予給a
    ```c
    //a &= ~(1 << n)，n為要清除的位元
    #include <stdio.h>

    int main() {
      int a = 0;
      a |= (1 << 3);
      printf("Set bit: %d\n", a);//output: 8
      
      a &= ~(1 << 3);
      printf("Clear bit: %d\n", a);//output: 0
      return 0;
    }
    ```
- Toggle Bit:
  - 如果要一次set bit，一次clear bit，那麼我們可以使用toggle bit的方式。我們可以使用 xor 運算子。
  - T為1，F為0，相同為0，相異為1
    ||T|F|
    |:-:|:-:|:-:|
    |T|0|1|
    |F|1|0|
  - 當數值為0的時候，這時候第一次toggle，這時候就會變成8
    ```c
    000 ^ 100 = 100
    ```
    再次toggle，這時候就會變成0
    ```c
    100 ^ 100 = 000
    ```
    以上數值都是^=，這個數值就會賦予給a
    ```c
    //a ^= (1 << n)，n為要toggle的位元
    #include <stdio.h>

    int main() {
      int a = 0;
      a |= (1 << 3);
      printf("Set bit: %d\n", a);//output: 8

      a &= ~(1 << 3);
      printf("Clear bit: %d\n", a);//output: 0

      a ^= (1 << 3);
      printf("Toggle bit 3(First time): %d\n", a);//output: 8

      a ^= (1 << 3);
      printf("Toggle bit 3(Second time): %d\n", a);//output: 0
      return 0;
    }
    ```
## 存取固定的記憶體位置(Accessing fixed memory locations)
### 第十個問題：存取固定的記憶體位置
- Embedded systems are often characterized by requiring the programmer to access a specific memory location. On a certain project it is required to set an integer variable at the absolute address 0x67a9 to the value 0xaa55. The compiler is a pure ANSI compiler. Write code to accomplish this task.This problem tests whether you know that it is legal to typecast an integer to a pointer in order to access an absolute location. The exact syntax varies depending upon one’s style. However, I would typically be looking for something like this:
  
  嵌入式系統通常需要程式設計師去存取特定的記憶體位置。在某個專案中，需要將一個整數變數設定在絕對地址0x67a9的值為0xaa55。編譯器是一個純粹的ANSI編譯器。寫下程式碼來完成這個任務。這個問題測試你是否知道這是合法的去型別轉換一個整數成一個指標為了存取一個絕對位置。確切的語法根據每個人的風格因人而異。然而，我在找的是像這個：
  ```c
  int *ptr;
  ptr = (int *)0x67a9;
  *ptr = 0xaa55;
  //更混淆的寫法
  *(int *const)0x67a9 = 0xaa55;
  ```
## 中斷(Interrupts)
### 第十一個問題：中斷
- Interrupts are an important part of embedded systems. Consequently, many compiler vendors offer an extension to standard C to support interrupts. Typically, this new key word is __interrupt. The following code uses __interrupt to define an interrupt service routine. Comment on the code.  
  
  中斷是嵌入式系統很重要的一部分。因此，很多編譯器供應商提供一個標準C的擴展來支持中斷。典型的，這個新的key word是__interrupt。以下的程式碼使用__interrupt來定義一個中斷service routine。評論這個程式碼
  ```c
  __interrupt double compute_area(double radius) {
    double area = PI * radius * radius;
    printf("nArea = %f\n", area);
    return area;
  }
  ```
  This function has so much wrong with it, it’s almost tough to know where to start.  
  - (a) Interrupt service routines cannot return a value. If you don’t understand this, then you aren’t hired.  
  
    中斷service routines無法回傳數值。
  - (b) ISR’s cannot be passed parameters. See item (a) for your employment prospects if you missed this.  
  
    ISR無法傳遞參數。
  - (c) On many processors / compilers, floating point operations are not necessarily re-entrant. In some cases one needs to stack additional registers, in other cases, one simply cannot do floating point in an ISR. Furthermore, given that a general rule of thumb is that ISRs should be short and sweet, one wonders about the wisdom of doing floating point math here.  

    在許多處理器/編譯器上，浮點運算不一定是可重入的。在一些案例中需要堆積額外的暫存器，而在其他情況下，根本無法在ISR中執行浮點運算。此外，鑑於ISR應該是短且有效率的，在ISR中做浮點運算是不明智的。
  - (d) In a similar vein to point (c), printf() often has problems with reentrancy and performance. If you missed points (c)& (d) then I wouldn’t be too hard on you. Needless to say, if you got these two points, then your employment prospects are looking better and better.
    
      與(c)點相似，printf()經常在可重入性和性能方面出現問題。如果你錯過了(c)和(d)點，那麼我對你不會太苛刻。
## 程式範例(Code Examples)
### 第十二個問題：整形提升的問題
- What does the following code output and why?
  ```c
  void foo(void) {
    unsigned int a = 6;
    int b = -20;

    (a+b > 6) ? puts("> 6") : puts("<= 6");
  }
  ```
  This question tests whether you understand the integer promotion rules in C — an area that I find is very poorly understood by many developers. Anyway, the answer is that this outputs “> 6”. The reason for this is that expressions involving signed and unsigned types have all operands promoted to unsigned types. Thus –20 becomes a very large positive integer and the expression evaluates to greater than 6. This is a very important point in embedded systems where unsigned data types should be used frequently (see reference 2). If you get this one wrong, then you are perilously close to not being hired.  

  這個問題測試你是否了解C中的整型提升規則-這是許多開發人員非常不了解的領域。無論如何，答案是這個輸出"> 6"。這是因為涉及有符號和無符號類型的表達式，所有的操作數都被提升為無符號類型。因此，-20變成了一個非常大的正整數，表達式的值大於6。這是嵌入式系統中非常重要的一點，無符號數據類型應該經常使用(參見參考2)。
  - 範例：
    ```c
    #include <stdio.h>

    int main() {
      unsigned int a = 6;
      int b = -20;

      (a+b > 6) ? puts("> 6") : puts("<= 6");
      return 0;
    }
    //output: > 6，代表b被提升為無符號整數(4294967276)，所以a+b>6
    ```
### 第十三個問題：0的一補數
- Comment on the following code fragment?
  ```c
  unsigned int zero = 0;
  unsigned int compzero = 0xFFFF; /*1’s complement of zero */
  //On machines where an int is not 16 bits, this will be incorrect. It should be coded:
  unsigned int compzero = ~0;
  ```
  This question really gets to whether the candidate understands the importance of word length on a computer. In my experience, good embedded programmers are critically aware of the underlying hardware and its limitations, whereas computer programmers tend to dismiss the hardware as a necessary annoyance.  
    
    這個問題真的可以知道應試者是否了解字組長度在電腦的重要性。在我的經驗中，好的嵌入式程式設計師會嚴謹的知道硬體的細節與它的限制，然後電腦程式設計師傾向忽視硬體並把它視為一個必要的麻煩。
  - 範例：
    ```c
    //compzero被設為0xFFFF，但機器有可能不是16位元
    unsigned int compzero = 0xFFFF;
    //假設系統是64位元，int為32位元
    #include <stdio.h>

    int main() {
      unsigned int zero = 0;
      unsigned int compzero = 0xFFFF;
      unsigned int compzero_with_tilde = ~0;

      printf("compzero: %x\n", compzero);//output: ffff
      printf("compzero_with_tilde: %x\n", compzero_with_tilde);//output: ffffffff
      return 0;
    }
    ```
## 動態記憶體配置(Dynamic Memory Allocation)
### 第十四個問題：動態記憶體配置
- Although not as common as in non-embedded computers, embedded systems still do dynamically allocate memory from the heap. What are the problems with dynamic memory allocation in embedded systems?  
  
  雖然在非嵌入式系統上並不常見，嵌入式系統仍然在heap上做動態的配置記憶體。做動態記憶體配置在嵌入式系統上會有什麼問題?  
- Here, I expect the user to mention memory fragmentation, problems with garbage collection, variable execution time, etc. This topic has been covered extensively in ESP, mainly by Plauger. His explanations are far more insightful than anything I could offer here, so go and read those back issues! Having lulled the candidate into a sense of false security, I then offer up this tidbit:  
  
  這裡，我預期使用者描述到記憶體碎片、回收垃圾的問題、變數的執行時間等。這些議題已經被Plauger在ESP雜誌上廣泛的涉及。他的解釋遠是更深刻見解的遠超任何我在這裡可以提供的，所以去並且讀這些議題。緩和應試者進入一個虛假安全的感覺後，接著我會提供這個題目：  
  - What does the following code fragment output and why?
    ```c
    char *ptr;

    if((ptr = (char *)malloc(0)) == NULL) {
      puts("Got a null pointer");
    } else {
      puts("Got a valid pointer");
    }
    ```
    This is a fun question. I stumbled across this only recently, when a colleague of mine inadvertently passed a value of 0 to malloc, and got back a valid pointer! After doing some digging, I discovered that the result of malloc(0) is implementation defined, so that the correct answer is ‘it depends’. I use this to start a discussion on what the interviewee thinks is the correct thing for malloc to do. Getting the right answer here is nowhere near as important as the way you approach the problem and the rationale for your decision.  
      
      這是個有趣的問題。我最近偶然發現，當一個我的同事不慎的傳入0的數值進入malloc，然後得到一個有效的指標!在做了一些挖掘之後，我發現這個malloc(0)的結果是實作定義的，所以正確的答案是「要看情況」。我使用這個來開啟一個討論來看應試者怎麼思考malloc所做的正確的事情。這裡得到正確的答案並不比你靠近這個問題以及你決定的原理闡述重要。
  - 範例：
    ```c
    //malloc(0)的結果是實作定義的，所以正確的答案是「要看情況」
    #include <stdio.h>
    #include <stdlib.h>

    int main() {
      char *ptr;

      if((ptr = (char *)malloc(0)) == NULL) {
        puts("Got a null pointer");
      } else {
        puts("Got a valid pointer");
      }
      return 0;
    }
    //output: Got a valid pointer
    ```
## Typedef
### 第十五個問題：Typedef
- Typedef is frequently used in C to declare synonyms for pre-existing data types. It is also possible to use the preprocessor to do something similar. For instance, consider the following code fragment:  
  
  Typedef 頻繁的在C語言中使用來對之前存在的資料型態宣告為同義詞。這也是有可能的使用預處理器來做相似的事情。舉例來說，考慮下方的程式碼片段：
  ```c
  #define dPS struct s *
  typedef struct s *tPS;
  ```
  The intent in both cases is to define dPS and tPS to be pointers to structure s. Which method (if any) is preferred and why?  
    
    在這兩個案例的目的是去定義 dPS 與 tPS來當指向結構 s 的指標。哪個方法(如果有的話) 是比較偏向的並且解釋為什麼？
  This is a very subtle question, and anyone that gets it right (for the right reason) is to be congratulated or condemned (“get a life“ springs to mind). The answer is the typedef is preferred. Consider the declarations:  
    
    這是一個非常微妙的問題，而且任何答對這題的人(要有正確的理由)是可以被恭喜或者是譴責(「找點有意思的事」浮現在腦中)。這個答案是 typedef 是比較好的。 思考下面的宣告：
    ```c
    dPS p1, p2; 
    tPS p3, p4;
    //第一個會被擴展成
    struct s *p1, p2;
    //定義p1會變成指向結構的指標而p2會變成一個真正的結構，變成可能不是你想要的。第二個範例正確的定義p3&p4成為指標
    ```
  - 範例：
    - 先宣告一個struct s，裡面只有一個成員int a，接著我們也照原文中宣告#define dPS struct s * 與 typedef struct s * tPS;，並在主程式中用struct s宣告了一個s_data，並將成員a設為5，接著我們也跟著原文一樣宣告了dPS p1,p2;與tPS p3,p4;
    ```c
    #include <stdio.h>

    struct s {
      int a;
    };

    #define dPS struct s *
    typedef struct s *tPS;

    int main() {
      struct s s_data;
      s_data.a = 5;
      dPS p1, p2;
      tPS p3, p4;
      return 0;
    }
    //讓p1與p2分別指向 s_data，p1 = &s_data; p2 = &s_data;，然後編譯
    #include <stdio.h>

    struct s {
      int a;
    };
    
    #define dPS struct s *
    typedef struct s *tPS;

    int main() {
      struct s s_data;
      s_data.a = 5;
      dPS p1, p2;
      tPS p3, p4;
      p1 = &s_data;
      p2 = &s_data;

      printf("p1: %d\n", p1->a);
      printf("p2: %d\n", p2->a);
      return 0;
    }
    //出現錯誤，p2 不是指標，接著我們對p2的成員a給予值，然後印出p1的a數值與p2的a數值
    #include <stdio.h>

    struct s {
      int a;
    };

    #define dPS struct s *
    typedef struct s *tPS;

    int main() {
      struct s s_data;
      s_data.a = 5;
      dPS p1, p2;
      tPS p3, p4;
      p1 = &s_data;
      p2.a = 10;
      
      printf("value of a in p1: %d\n", p1->a);
      printf("value of a in p2: %d\n", p2.a);
      return 0;
    }
    //輸出結果為p1的成員a為5，p2的成員a為10。所以當我們宣告成: dPS p1,p2，會如原文所說的擴展成這樣struct s * p1, p2;，p1還是指標，而p2是一個結構變數，接著將p3與p4指向s_data
    #include <stdio.h>

    struct s {
      int a;
    };

    #define dPS struct s *
    typedef struct s *tPS;

    int main() {
      struct s s_data;
      s_data.a = 5;
      dPS p1, p2;
      tPS p3, p4;
      p1 = &s_data;
      p2.a = 10;
      printf("value of a in p1: %d\n", p1->a);
      printf("value of a in p2: %d\n", p2.a);

      p3 = &s_data;
      p4 = &s_data;
      printf("value of a in p3: %d\n", p3->a);
      printf("value of a in p4: %d\n", p4->a);
      return 0;
    }
    //將p3與p4的成員a也都印出來，發現都是5，tPS p3,p4;這樣宣告確實可以讓p3與p4都是指標
    ```
## 混淆的語法(Obfuscated Syntax)
### 第十六個問題：a++的問題
- C allows some appalling constructs. Is this construct legal, and if so what does this code do?  
  
  C語言允許一些可怕的結構。這個結構合法嗎？如果合法的話這段程式碼會做什麼？
  ```c
  int a = 5, b = 7, c;
  c = a+++b;
  ```
  This question is intended to be a lighthearted end to the quiz, as, believe it or not, this is perfectly legal syntax. The question is how does the compiler treat it? Those poor compiler writers actually debated this issue, and came up with the “maximum munch” rule, which stipulates that the compiler should bite off as big a (legal) chunk as it can. Hence, this code is treated as:  

    這個問題是為這個測驗的一個愉快的結束。不管你相信或不相信，這是個完全的合法語法。這個問題是編譯器如何處理它? 那些不好的編譯器作者實際上爭論這個問題。根據 “maximum munch”規則，明確說明編譯器應該要盡可能地咬掉最大的一個(合法個)chunk。因此，這個程式碼要被處理為：
    ```c
    c = a++ + b;
    ```
  Thus, after this code is executed, a = 6, b = 7 & c = 12;.If you knew the answer, or guessed correctly — then well done. If you didn’t know the answer then I would not consider this to be a problem. I find the biggest benefit of this question is that it is very good for stimulating questions on coding styles, the value of code reviews and the benefits of using lint.  

    因此，在這個程式碼執行之後，a = 6, b = 7 & c = 12;，如果你知道這個答案，或者是猜對 — 那做得好。如果你不知道這個答案那麼我不會認為這是一個問題。我發現這個問題的最大益處是這是個非常好的激勵問題在於程式風格，程式碼審查的價值以及使用lint的益處。
  - 範例：
    ```c
    #include <stdio.h>

    int main() {
      int a = 5, b = 7, c;
      c = a+++b;
      printf("a: %d\n, b: %d\n, c: %d\n", a, b, c);//output: a: 6, b: 7, c: 12
      return 0;
    }
    //a會先與b相加，所以是5+7=12，c的數值是12，b的數值不會變是7，a跟b加完之後，接著會a++，所以a變成6，其實a++就是後做，先運算完之後再++，所以才會5加完7之後，a自身才++變成6
    #include <stdio.h>

    int main() {
      int a = 5, b = 7, c;
      c = a++
      printf("a: %d\n, b: %d\n, c: %d\n", a, b, c);//output: a: 6, b: 7, c: 5

      c = ++b;
      printf("a: %d\n, b: %d\n, c: %d\n", a, b, c);//output: a: 6, b: 8, c: 8
      return 0;
    }
    //讓 c = a++的話，則c會等於5，接著a++再運算，a變成6，接著讓c = ++b，++b會先運算，所以b會等於8，而c當然接收8的數值，所以數值為8
    #include <stdio.h>

    int main() {
      int a = 5, b = 7;
      printf("a: %d\n", a++);//output: a: 5
      printf("After a++, a: %d\n", a);//output: After a++, a: 6
      printf("b: %d\n", ++b);//output: b: 8
      printf("After ++b, b: %d\n", b);//output: After ++b, b: 8
      return 0;
    }
    ```