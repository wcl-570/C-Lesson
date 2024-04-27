#include <stdio.h>

//if述句
int main () {
  int a = 3;
  if (a > 4) {
    printf("a is larger than 4.\n");//不會執行
  }
  int b = 5;
  if(b > 4){
    printf("b is larger than 4.\n");//會執行
  }
  int c;
  printf("c = ");
  scanf("%d", &c);
  if(c > 4){
    printf("c is larger than 4.\n");
  }
  return 0;
}

//大於、小於、等於
int main(){
  int a = 5;//可以改變a的值
  if(a > 4){
    printf("a is larger than 4.\n");
  }
  if(a < 4){
    printf("a is smaller than 4.\n");
  }
  if(a == 4){//不能用「=」，要用「==」，因為「=」是指定值
    printf("a is equal to 4.\n");
  }
  return 0;
  }

//猜數字
int main () {  
  int answer = 5;
  int guess;
  printf("Please enter your guess: ");
  scanf("%d", &guess);
  if (guess > answer) {
    printf("Too large!\n");
  }
  if (guess < answer) {
    printf("Too small!\n");
  }
  if (guess == answer) {
    printf("Correct!\n");
  }
  return 0;
}

//滿額折扣
//第一種
int main () {  
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
  return 0;
}
//第二種
int main () {  
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
  return 0;
}
//第三種
int main () {
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

//正三角形判斷：三邊等長
int main () {
  int side1, side2, side3;
  printf("Please enter the lengths: ");
  scanf("%d%d%d", &side1, &side2, &side3);
  if (side1 == side2)
    if (side2 == side3) {//if (side1 == side2 && side2 == side3)也可以
      printf("Regular triangle\n");
  }
  return 0;
}
//等腰三角形判斷：有兩邊一樣長
int main () {
  int side1, side2, side3;
  printf("Please enter the lengths: ");
  scanf("%d%d%d", &side1, &side2, &side3);
  if (side1 == side2 || side1 == side3 || side2 == side3) {
    printf("Isosceles triangle\n");
  }
  return 0;
}

//直角三角形判斷：兩邊長的平方和等於第三邊的平方
int main () {
  int side1, side2, side3;
  printf("Please enter the lengths: ");
  scanf("%d%d%d", &side1, &side2, &side3);
  if (side1 * side1 + side2 * side2 == side3 * side3 ||
      side1 * side1 + side3 * side3 == side2 * side2 ||
      side2 * side2 + side3 * side3 == side1 * side1) {
    printf("Rectangular triangle\n");
  }
  return 0;
}

//三角形種類判斷
int main () {
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
  return 0;
}

//由小到大
int main () {
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

//對兩個變數求最大值
//第一種
int main () {
  int a, b, max;
  printf("Enter first integer: ");
  scanf("%d", &a);
  printf("Enter second integer: ");
  scanf("%d", &b);
  if (a >= b) {
    max = a;
  }
  if (a < b) {
    max = b;
  }
  printf("The maximum is %d.\n", max); 
  return 0;
}
//第二種
int main () {
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
  return 0;
}

//對三個變數求最大值
//第一種
int main () {
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
  return 0;
}
//第二種
int main () {
  int a, b, c, max;
  printf("Enter three integers: ");
  scanf("%d%d%d", &a, &b, &c);
  max = a;
  if (b > max) {
    max = b;
  }
  if (c > max) {
    max = c;
  }
  printf("The maximum is %d.\n", max);
  return 0;
}

//對四個變數求最大值
//第一種
int main () {
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
  return 0;
}
//第二種
int main () {
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
  return 0;
}
//第三種
int main () {
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

//對兩個變數求最小值
//第一種
int main () {
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
  return 0;
}
//第二種
int main () {
  int a, b, min;
  printf("Enter two intrgers: ");
  scanf("%d%d", &a, &b);
  min = a;
  if (a > b) {
    min = b;
  }
  printf("The minimum is %d.\n", min);
  return 0;
}

//對三個變數求最小值
//第一種
int main () {
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
  return 0;
}
//第二種
int main () {
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

//對三個變數求中位數
//第ㄧ種
int main () {
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
  return 0;
}
//第二種
int main () {
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

//對兩個變數依照大小排序：使用數值交換的做法
//由小到大
int main () {
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

//對三個變數依照大小排序：賦值順序調整
int main () {
  int a = 2, b = 4, c = 6, t;
  printf("Before: %d %d %d\n", a, b, c);
  t = a;
  a = b;
  b = c;
  c = t;
  printf("After: %d %d %d\n", a, b, c);
  return 0;
}

//使用兩次兩個變數的數值交換
int main () {
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

//對三個變數按照大小排序（a, b, c）
int main () {
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
//簡化上述程式碼
int main () {
  int a, b, c, t;
  scanf("%d%d%d", &a, &b, &c);
  printf("Before: %d %d %d\n", a, b, c);
  if (b < a) {//將a, b中最小的數值換到變數a
    t = b; b = a; a = t;
  }
  if (c < a) {//將a, c中最小的數值換到變數a
    t = c; c = a; a = t;
  }
  if (c < b) {//將b, c中最小的數值換到變數b
    t = c; c = b; b = t;
  }
  printf("After: %d %d %d\n", a, b, c);
  return 0;
}

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