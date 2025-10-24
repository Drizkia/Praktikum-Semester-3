#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
    Node *prev;
};

Node *top, *bottom, *newnode, *del, *temp;

// Bikin stack
void createStack() {
    top = NULL;
    bottom = NULL;
}

// Is empty
bool isEmpty() {
    if (top == NULL) {
        return true;
    } else {
        return false;
    }
}

void push(int value) {
    newnode = new Node();
        newnode->info = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    // cout << "masukkan nama: ";
    //     cin >> newnode->nama;

    if(isEmpty()) {
        top = newnode;
        bottom = newnode;
    } else {
        top->next = newnode;
        newnode->prev = top;
        top = newnode;
    }
}

void pop() {
    if (isEmpty()) {
        cout << "Stack Masih Kosong" << endl;
    } else {
        del = top;
        if (top == bottom) {
            top = bottom = NULL;
        } else {
            top = top->prev;
            top->next = NULL;
        }
        delete del;
    }
}

void display() {
    if (isEmpty()) {
        cout << "Stack kosong" << endl;
    } else {
        temp = top;
        while (temp != NULL) {
            cout << temp->info << endl;
            temp = temp->prev;
        }
    }
}

int main() {
    createStack();
    push(5);
    push(10);
    display();

}