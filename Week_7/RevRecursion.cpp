#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* insertEnd(struct Node* head, int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = NULL;

    if(head == NULL) return newNode;

    struct Node* temp = head;
    while(temp->next != NULL) temp = temp->next;
    temp->next = newNode;
    return head;
}

void display(struct Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

void printReverse(struct Node* head){
    if(head == NULL) return;
    printReverse(head->next);
    printf("%d ", head->data);
}

int main(){
    struct Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    printf("Original: ");
    display(head);

    printf("Reverse print (without changing list): ");
    printReverse(head);
    printf("\n");

    return 0;
}