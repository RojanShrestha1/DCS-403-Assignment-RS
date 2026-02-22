#include <stdio.h>
#include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

void display(struct Node* head){
    while(head != NULL){
        printf("%d ", head->data);
        head = head->next;
    }
    printf("\n");
}

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

int main(){
    struct Node* head = NULL;

    head = insertEnd(head, 10);
    head = insertEnd(head, 20);

    printf("Before: ");
    display(head);

    head = insertEnd(head, 99);

    printf("After inserting at end: ");
    display(head);

    return 0;
}