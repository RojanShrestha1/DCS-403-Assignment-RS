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

struct Node* insertBegin(struct Node* head, int x){
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = x;
    newNode->next = head;
    return newNode;
}

int main(){
    struct Node* head = NULL;

    head = insertBegin(head, 20);
    head = insertBegin(head, 10);

    printf("Before: ");
    display(head);

    head = insertBegin(head, 5);

    printf("After inserting at beginning: ");
    display(head);

    return 0;
}