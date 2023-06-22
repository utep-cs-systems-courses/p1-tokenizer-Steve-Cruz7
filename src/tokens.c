#inlcude "stdio.h"
#include "tokenizer.h"

int space_char(char c){
  if(c == ' ' || c =='\t')
    return 1;
  else
    return 0;
}

int not_space_char(char c){
  if(c == '\0')
    return 0;
  else
    return (space_char(c) ^ 1); //Using exclusive or to guarantee opposite result of space_char
}

char *token_start(char *s){
  while(space_char(*s)){
    s++;
  }
  if(*s == '\0')
    return 0;
  else
     return s;
}
