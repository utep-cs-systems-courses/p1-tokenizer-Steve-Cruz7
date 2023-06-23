/*This is going to be the User Interface that just echoes input for now*/
#include <stdio.h>
#include "tokenizer.h"
#define MAX 100

int main(){
  char input[MAX];

  while(1){
    putchar('>');
    fgets(input, MAX, stdin);
    printf("%s", input);
    
  }
}
