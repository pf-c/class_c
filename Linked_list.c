#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};
void printLinkedlist(struct node *p){
    while (p !=NULL)
    {
        printf("%d",p->value);
        p=p->next;
    }
    
}

int main(){
    struct node *head;
    struct node *one = NULL;
    struct node *two = NULL;
    struct node *three = NULL;

    one = malloc(sizeof(struct node));
    two = malloc(sizeof(struct node));  
    three = malloc(sizeof(struct node));
    // Assign value values
  one->value = 1;
  two->value = 2;
  three->value = 3;

  // Connect nodes
  one->next = two;
  two->next = three;
  three->next = NULL;

  // printing node-value
  head = one;
  printLinkedlist(head);
}