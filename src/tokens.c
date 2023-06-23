#include "stdio.h"
#include "tokenizer.h"

int space_char(char c){
  if(c == ' ' || c =='\t')
    return 1;
  else
    return 0;
}

int non_space_char(char c){
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

char *token_terminator(char *token){
  while(non_space_char(*token)){
    token++;
  }
  token -= 1;
  printf("Printing last letter of token, %c", *token);
  return token;
}

int count_tokens(char *str){
  int count = 0;
  str = token_start(str);
  count ++;
  while(*str != '\0'){
    if(non_space_char(*str)){
	str++;
   }else{
        count++;
        str = token_start(str);
    }
  }
  return count;
}

char *copy_str(char *inStr, short len){
  char word[len+1];
  char *p = word;
  while(*inStr != '\0'){
    *p = *inStr;
    inStr++;
    p++;
  }
  *p = '\0';
  p -= len;
  return p;
}
      
      
 
