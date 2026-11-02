#include <iostream>
using namespace std;

#define SIZE 5

class CircularQueue {

    int a[SIZE];
    int front, rear;

public:

    CircularQueue() {
        front = -1;
        rear = -1;
    }

    
    void enqueue(int value) {

        if((rear + 1) % SIZE == front) {
            cout << "Queue is Full\n";
            return;
        }

        if(front == -1) {
            front = 0;
        }

        rear = (rear + 1) % SIZE;

        a[rear] = value;

        cout << value << " inserted\n";
    }


    void dequeue() {

        if(front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Deleted: " << a[front] << endl;

        if(front == rear) {
            front = rear = -1;
        }
        else {
            front = (front + 1) % SIZE;
        }
    }

   
    void display() {

        if(front == -1) {
            cout << "Queue is Empty\n";
            return;
        }

        cout << "Queue: ";

        int i = front;

        while(true) {

            cout << a[i] << " ";

            if(i == rear)
                break;

            i = (i + 1) % SIZE;
        }

        cout << endl;
    }
};

int main() {

    CircularQueue q;

    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);

    q.display();

    q.dequeue();

    q.display();

    q.enqueue(40);
    q.enqueue(50);

    q.display();

    return 0;
}