#include <stdio.h>
#define SIZE 5

int q[SIZE];
int front = -1, rear = -1;

int isEmpty(){
    return (front == -1);
}

int isFull(){
    return (rear == SIZE - 1);
}

int main(){
    printf(isEmpty() ? "Queue Empty\n" : "Queue Not Empty\n");
    printf(isFull() ? "Queue Full\n" : "Queue Not Full\n");
    return 0;
}