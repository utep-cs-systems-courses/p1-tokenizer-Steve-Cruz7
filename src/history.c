#include "stdio.h"
#include "stdlib.h"
#include "history.h"

List *init_history(){
  Item root;             //Creating the root of the linked list and giving it ID 0
  root.id = 0;
  Item *pointer = malloc(sizeof(struct Item));
  *pointer = root;        //Creating a pointer to the root
  List list;
  list.root = pointer; //Initializing list by giving it the pointer to the root
  List *linkedlist = malloc(sizeof(struct List));
  *linkedlist = list;
  return linkedlist;
}

void add_history(List *list, char *str){
  List *copy = list;
  if(copy->root->id == 0){
    copy->root->str = str;
  }
  else{
    Item node;
    int id;
    while(copy->root->next != NULL){
      id = copy->root->id;
      copy->root = copy->root->next;
    }
    node.id = id +1;
    node.str = str;
    copy->root->next = malloc(sizeof(struct Item));
    *(copy->root->next) = node;
  }
}

char *get_history(List *list, int id){
  List *copy = list;
  while(copy->root->id != id){
    if(copy->root->next != NULL){
      copy->root = copy->root->next;
    }
    else {
      return "Not a valid ID";
    }
  }
  return copy->root->str;
}

void print_history(List *list){
  List *copy = list;
  while(copy->root->next != NULL){
    printf("%s\n", copy->root->str);
    copy->root = copy->root->next;
  }
}

void free_history(List *list){
  List *copy = list;
  while(copy->root->next != NULL){
   Item *next = copy->root->next;
   free(copy->root);
   copy->root = next;
  }
  free(list);
}
