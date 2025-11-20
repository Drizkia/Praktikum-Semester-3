#include <iostream>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node *prev;
};

    Node *front = nullptr;
    Node *rear = nullptr;

bool isEmpty() {
    return front == nullptr;
}

void enqueueFront(int value){
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = front;
    newNode->prev = nullptr;

    if (isEmpty()) {
    front = rear = newNode;
    } else {
    front->prev = newNode;
    front = newNode;
    }
    cout << value << " dimasukkan ke depan deque.\n";
}

void enqueueRear(int value) {
    Node *newNode = new Node();
    newNode->data = value;
    newNode->next = nullptr;
    newNode->prev = rear;

    if (isEmpty()) {
        front = rear = newNode;
    } else {
        rear->next = newNode;
        rear = newNode;
    }
    cout << value << " dimasukkan ke belakang deque.\n";
}

void dequeueFront() {
    if (isEmpty()) {
        cout << "Deque kosong, tidak bisa hapus dari depan.\n";
        return;
    }

    Node *temp = front;

    if (front == rear) {
        front = rear = nullptr;
    } else {
        front = front->next;
        front->prev = nullptr;
    }

    cout << temp->data << " dihapus dari depan deque.\n";
    delete temp;
}

void dequeueRear() {
    if (isEmpty()) {
        cout << "Deque kosong, tidak bisa hapus dari belakang.\n";
        return;
    }

    Node *temp = rear;

    if (front == rear) {
        front = rear = nullptr;
    } else {
        rear = rear->prev;
        rear->next = nullptr;
    }

    cout << temp->data << " dihapus dari belakang deque.\n";
    delete temp;
}

    // Tampilkan isi deque dari depan ke belakang
void display(){
    if (isEmpty()) {
        cout << "Deque kosong.\n";
        return;
    }

    Node *temp = front;
    cout << "Isi deque: ";
    while (temp != nullptr) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int main() {
    enqueueRear(10);
    enqueueRear(20);
    enqueueFront(5);
    display();

    dequeueFront();
    display();

    enqueueRear(30);
    enqueueFront(2);
    display();

    dequeueRear();
    display();

    return 0;
}
