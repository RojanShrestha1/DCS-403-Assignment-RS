#include <iostream>
using namespace std;

#define SIZE 5 

class Queue {
private:
    int items[SIZE], front, rear;

public:
    Queue() {
        front = -1;
        rear = -1;
    }

    
    bool isFull() {
        return (rear == SIZE - 1);
    }

  
    bool isEmpty() {
        return (front == -1 || front > rear);
    }

  
    void enqueue(int value) {
        if (isFull()) {
            cout << "Queue is full!" << endl;
        } else {
            if (front == -1) front = 0; 
            rear++;
            items[rear] = value;
            cout << "Inserted " << value << endl;
        }
    }

    
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty!" << endl;
        } else {
            cout << "Deleted " << items[front] << endl;
            front++;
        }
    }

    
    void peek() {
        if (!isEmpty()) {
            cout << "Front element is: " << items[front] << endl;
        }
    }
};

int main() {
    Queue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.peek();
    q.dequeue();
    q.peek();

    return 0;
}