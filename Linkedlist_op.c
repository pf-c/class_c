#include <stdio.h>
#include <stdlib.h>

struct node{
    int value;
    struct node *next;
};
// Inser at the begining
void insertAtBegining(struct node **head, int value){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}
// Insert at the end
void insertAtEnd(struct node **head, int value){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    if(*head == NULL){
        *head = newNode;
        return;
    }
    struct node *last = *head;
    while (last->next != NULL)
    {
        last = last->next;
    }
    last->next = newNode;
}

// Insert at the given position
void insertAtPosition(struct node **head, int value, int position){
    struct node *newNode = malloc(sizeof(struct node));
    newNode->value = value;
    newNode->next = NULL;
    if(position == 1){
        newNode->next = *head;
        *head = newNode;
        return;
    }
    struct node *temp = *head;
    for (int i = 0; i < position-2 && temp != NULL; i++)
    {
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position is greater than the number of nodes\n");
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}
// Delete at the begining
void deleteAtBegining(struct node **head){
    if(*head == NULL){
        printf("Linkedlist is empty\n");
        return;
    }
    struct node *temp = *head;
    *head = temp->next;
    free(temp);
}
// Delete at the end
void deleteAtEnd(struct node **head){
    if(*head == NULL){
        printf("Linkedlist is empty\n");
        return;
    }
    struct node *temp = *head;
    struct node *prev = NULL;
    while (temp->next != NULL)
    {
        prev = temp;
        temp = temp->next;
    }
    if(prev == NULL){
        *head = NULL;
    }else{
        prev->next = NULL;
    }
    free(temp);
}
// Delete at the given position
void deleteAtPosition(struct node **head, int position){
    if(*head == NULL){
        printf("Linkedlist is empty\n");
        return;
    }
    struct node *temp = *head;
    if(position == 1){
        *head = temp->next;
        free(temp);
        return;
    }
    struct node *prev = NULL;
    for (int i = 0; i < position-1 && temp != NULL; i++)
    {
        prev = temp;
        temp = temp->next;
    }
    if(temp == NULL){
        printf("Position is greater than the number of nodes\n");
        return;
    }
    prev->next = temp->next;
    free(temp);
}
//print linkedlist
void printLinkedlist(struct node *p){
    while (p !=NULL)
    {
        printf("%d ",p->value);
        p=p->next;
    }    
}

int main(){
    struct node *head = NULL;
    insertAtBegining(&head, 1);
    insertAtEnd(&head, 3);
    insertAtBegining(&head, 2);
    insertAtEnd(&head, 4);
    insertAtPosition(&head, 5, 3);
    printLinkedlist(head);
    printf("\n");
    deleteAtBegining(&head);
    deleteAtEnd(&head);
    deleteAtPosition(&head, 2);
    printLinkedlist(head);
}