#include <iostream>
using namespace std;

// Deklarasi
struct Node {
    int info;
    Node *next, *prev;
};

Node *head, *tail, *newnode, *temp, *del;

void createlist() {
    head = NULL;
    tail = NULL;
}

bool isempty(){
    return head == NULL;
}

// Insert
void insertdepan(int IB) {
    newnode = new Node();
    newnode->info = IB;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (isempty()) {
        head = newnode;
        tail = newnode;
    } else if (IB > head->info) {
        cout << "IB : " << IB << "lebih besar dari head->info " << head->info << endl;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertmid(int IB) {
    newnode = new Node();
    newnode->info = IB;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (isempty()) {
        head = newnode;
        tail = newnode;
    } else {
        temp = head;
        while (temp->next != NULL && temp->next->info < IB) {
            temp = temp->next;
        }
        newnode->next = temp->next;
        if (temp->next != NULL) {
            temp->next->prev = newnode;
        }
        temp->next = newnode;
        newnode->prev = temp;
    }
}

void insertbelakang(int IB) {
    newnode = new Node();
    newnode->info = IB;
    newnode->next = NULL;
    newnode->prev = NULL;

    if (isempty()) {
        head = newnode;
        tail = newnode;
    } else if (IB < tail->info) {
        cout << "IB : " << IB << "lebih kecil dari tail->info " << tail->info << endl;
    } else {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

// Display
void displaydepan() { // kaya descend besar ke kecil
    if (isempty()) {
        cout << "Tidak ada list" << endl;
    } else {
        temp = head;
        while (temp != NULL) {
            cout << temp->info << " ";
            temp = temp->next;
        }
    cout << endl;
    }
}

void displaybelakang() { // kaya ascend kecil ke besar
    if (isempty()) {
        cout << "Tidak ada list" << endl;
    } else {
        temp = tail;
        while (temp != NULL) {
            cout << temp->info << " ";
            temp = temp->prev;
        }
    cout << endl;
    }
}

// Delete
void deletedepan() {
    if (isempty()) {
        cout << "isi dulu bro" << endl;
    } else {
        temp = head;
        head = head->next;
        head->prev = NULL;
        delete temp;
    }
}

void deletebelakang() {
    if (isempty()) {
        cout << "isi dulu bro" << endl;
    } else {
        tail = tail;
        tail = tail->prev;
        tail->next = NULL;
        delete temp;
    }
}

void hapustengah(int IH) {
    if (isempty()) {
        cout << "isi dulu bro" << endl;
    } else if (IH == head->info) {
        // hapus depan
        del = head;
        if (head == tail){
            head = NULL;
            tail = NULL;
        } else {
            head = head->next;
            head->prev = NULL;
        }
        delete del;
    } else {
        temp = head;
        while (temp != tail && temp->next->info != IH) {
            temp = temp->next;
        }
        // hapus belakang
        if (temp != tail && temp->next->info == IH) {
            del = temp->next;
            if (del == tail) {
                tail = temp;
                tail->next = NULL;
            } else {
                temp->next = del->next;
                del->next->prev = temp;
            }
            delete del;
        } else {
            cout << "Node dengan IH : " << IH << "tidak ditemukan" << endl;
        }
    }
}

int main() {
    createlist();
    insertdepan(5);
    insertdepan(4);
    displaybelakang();
    displaydepan();
    cout << endl;
    insertbelakang(7);
    insertmid(6);
    displaybelakang();
    displaydepan();
    cout << endl;
    return 0;
}