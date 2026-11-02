#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

Node* top = NULL;


void push(int value) {

    Node* newNode = new Node;

    newNode->data = value;
    newNode->next = top;

    top = newNode;

    cout << value << " pushed\n";
}

void pop() {

    if(top == NULL) {
        cout << "Stack Underflow\n";
        return;
    }

    Node* temp = top;

    cout << "Popped: " << temp->data << endl;

    top = top->next;

    delete temp;
}

void display() {

    if(top == NULL) {
        cout << "Stack is Empty\n";
        return;
    }

    Node* temp = top;

    cout << "Stack: ";

    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << endl;
}

int main() {

    push(10);
    push(20);
    push(30);

    display();

    pop();

    display();

    return 0;
}