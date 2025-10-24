#include <iostream>
using namespace std;

struct Node {
    string buku;
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

void push() {
    newnode = new Node();
        // newnode->info = value;
    newnode->next = NULL;
    newnode->prev = NULL;

    cout << "masukkan nama: ";
    cin.ignore();
        getline(cin, newnode->buku);

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
            cout << "Buku Teratas: " << temp->buku << endl;
    }
}

void count() {
    int x;
    if (isEmpty()) {
        cout << "Stack kosong" << endl;
    } else {
        temp = top;
        while (temp != NULL) {
            x++;
            temp = temp->prev;
        }
        cout << "Jumlah Buku: " << x << endl;
    }
}

int main() {
    int menu;
    bool x = false;
    while (!x) {
        cout << "1. tambah buku" << endl;
        cout << "2. ambil buku" << endl;
        cout << "3. lihat buku" << endl;
        cout << "4. hitung buku" << endl;
        cout << "5. exit" << endl;
        cout << "Input menu: ";
        cin >> menu;
        
        switch (menu) {
            case 1:
                push();
            break;
            
            case 2:
                pop();
            break;
            
            case 3:
                display();
            break;
            
            case 4:
                count();
            break;
            
            case 5:
                exit(0);
                x = true;
            break;
            
            default:
                cout << "Menu tidak ada" << endl;
            break;
        }
    }
}