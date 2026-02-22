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
}

void dequeue(){
    if(front == -1){
        printf("Queue Empty\n");
        return;
    }

    printf("Deleted: %d\n", q[front]);

    if(front == rear){
        front = rear = -1;
    } else {
        front++;
    }

    display(); // updated queue
}

int main(){
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    dequeue();
    dequeue();
    dequeue(); // empty case

    return 0;
}