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

int search(struct Node* head, int x){
    int pos = 1;
    struct Node* temp = head;

    while(temp != NULL){
        if(temp->data == x) return pos;
        temp = temp->next;
        pos++;
    }
    return -1;
}

int main(){
    struct Node* head = NULL;
    head = insertEnd(head, 10);
    head = insertEnd(head, 20);
    head = insertEnd(head, 30);

    int x = 20;
    int ans = search(head, x);

    if(ans == -1) printf("%d not present\n", x);
    else printf("%d found at position %d\n", x, ans);

    return 0;
}