#include <stdio.h>
#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

void enqueue(int x){
    if(rear == SIZE - 1){
        printf("Queue Full\n");
        return;
    }
    if(front == -1) front = 0;
    rear++;
    q[rear] = x;
}

void display(){
    if(front == -1){
        printf("Queue Empty\n");
        return;
    }
    printf("Queue: ");
    for(int i = front; i <= rear; i++){
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main(){
    enqueue(1);
    enqueue(2);
    enqueue(3);
    display();
    return 0;
}