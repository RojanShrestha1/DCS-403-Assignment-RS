#include <stdio.h>
#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

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

void enqueue(int x){
    if(rear == SIZE - 1){
        printf("Queue Full\n");
        return;
    }
    if(front == -1) front = 0;
    rear++;
    q[rear] = x;
    printf("%d inserted\n", x);
    display();   // updated queue
}

int main(){
    enqueue(5);
    enqueue(15);
    enqueue(25);
    return 0;
}