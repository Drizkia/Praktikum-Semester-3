#include <iostream>
using namespace std;

#define max 50

int top = 0;
int stack[max];

void createStack() {
    stack[top] = 0;
}

bool isempty() {
    if (top == 0) {
        return true;
    } else {
        return false;
    }
}

bool isfull() {
    if (top == max - 1) {
        return true;
    } else {
        return false;
    }
}

void push(int value) {
    if (isfull()) {
        cout << "Stack Penuh" << endl;
    } else {
        top++;
        stack[top] = value;
        stack[0] = top;
    }
}

void pop() {
    int IP;
    if (isempty()) {
        cout << "Stack masih kosong" << endl;
    } else {
        IP = stack[top];
        top--;
        stack[0] = top;
        cout << "Elemen atas dengan nilai " << IP << "telah dihapus" << endl;
    }
}

void display() {
    for (int i = top; i > 0; i--) {
        cout << stack[i] << endl;
    }
}

int main() {
    createStack(); // top = 0 atau stack[0] = 0
    push(2); // top = 1; stack[0] = 2;
    push(4);
    display();
}