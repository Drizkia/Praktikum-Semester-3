#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
};

Node *front = nullptr;
Node *rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueue(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;

    if (isEmpty()) {
        front = rear = newNode;
        rear->next = front; // circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // circular link
    }
    cout << value << " dimasukkan ke queue.\n";
}

void dequeue() {
    if (isEmpty()) {
        cout << "Queue kosong, tidak bisa dequeue.\n";
        return;
    }

    Node *temp = front;

    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
        rear->next = front; // circular link
    }

    cout << temp->data << " dihapus dari queue.\n";
    delete temp;
}

void display() {
    if (isEmpty()) {
        cout << "Queue kosong.\n";
        return;
    }

    Node *temp = front;
    cout << "Isi queue: ";
    do {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != front);
    cout << endl;
}

int main() {
    enqueue(10);
    enqueue(20);
    enqueue(30);
    display();

    dequeue();
    display();

    enqueue(40);
    display();

    return 0;
}