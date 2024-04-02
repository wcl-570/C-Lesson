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