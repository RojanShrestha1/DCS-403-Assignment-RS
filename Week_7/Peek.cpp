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

void peek(){
    if(front == -1){
        printf("Queue Empty\n");
        return;
    }
    printf("Front element: %d\n", q[front]);
}

int main(){
    enqueue(11);
    enqueue(22);
    peek();
    return 0;
}