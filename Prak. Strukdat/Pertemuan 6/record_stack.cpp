#include <iostream>
using namespace std;

#define max 5

struct tumpukan {
    int top;
    int elemen[max]; //ini datanya
};

tumpukan stack;

void createstack() {
    stack.top = -1;
}

bool isempty() {
    if (stack.top = -1) {
        return true;
    } else {
        return false;
    }
}

bool isfull() {
    if (stack.top == max - 1) {
        return true;
    } else {
        return false;
    }    
}

void push(int value) {
    if (isfull()) {
        cout << "Stack Penuh" << endl;
    } else {
        stack.top++;
        stack.elemen[stack.top] = value;
    }
}

void pop() {
    int IP;
    if (isempty()) {
        cout << "Stack masih kosong" << endl;
    } else {
        IP = stack.elemen[stack.top];
        stack.top--;
        cout << "Elemen dengan nilai " << IP << "telah dihapus" << endl;
    }
}

void display() {
    for (int i = stack.top; i >= 0; i--) {
        cout << stack.elemen[i] << endl;
    }
}

int main() {
    createstack();
    push(100);
    push(50);
    display();
    pop();
    display();
}