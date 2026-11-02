#include <iostream>
using namespace std;

char st[100];
int top = -1;

void push(char x) {
    st[++top] = x;
}

char pop() {
    return st[top--];
}

int precedence(char x) {

    if(x == '*' || x == '/')
        return 2;

    if(x == '+' || x == '-')
        return 1;

    return 0;
}

int main() {

    string infix = "A+B*(C-D)";
    string postfix = "";

    for(int i = 0; i < infix.length(); i++) {

        char ch = infix[i];

        if((ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9')) {

            postfix += ch;
        }

        else if(ch == '(') {
            push(ch);
        }

        else if(ch == ')') {

            while(top != -1 && st[top] != '(') {
                postfix += pop();
            }

            if(top != -1)
                pop();
        }

        else {

            while(top != -1 &&
                  st[top] != '(' &&
                  precedence(st[top]) >= precedence(ch)) {

                postfix += pop();
            }

            push(ch);
        }
    }

    while(top != -1) {
        postfix += pop();
    }

    cout << "Postfix Expression: " << postfix;

    return 0;
}