#include <stdio.h>
#define SIZE 5

int cq[SIZE];
int front = -1, rear = -1;

int isEmpty(){
    return (front == -1);
}

int isFull(){
    return ((rear + 1) % SIZE == front);
}

void enqueue(int x){
    if(isFull()){
        printf("Circular Queue Full\n");
        return;
    }
    if(isEmpty()){
        front = rear = 0;
    } else {
        rear = (rear + 1) % SIZE;
    }
    cq[rear] = x;
    printf("%d inserted\n", x);
}

void dequeue(){
    if(isEmpty()){
        printf("Circular Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", cq[front]);

    if(front == rear){
        front = rear = -1;
    } else {
        front = (front + 1) % SIZE;
    }
}

void display(){
    if(isEmpty()){
        printf("Circular Queue Empty\n");
        return;
    }

    printf("Circular Queue: ");
    int i = front;
    while(1){
        printf("%d ", cq[i]);
        if(i == rear) break;
        i = (i + 1) % SIZE;
    }
    printf("\n");
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    return 0;
}