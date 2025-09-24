#include <iostream>
using namespace std;

struct Node {
    int info;
    Node *next;
};

Node *head, *tail, *cur, *del, *newnode, *maha;

void in() {
    head = NULL;
    tail = NULL;
}

void sisipTengah(int ni, string nm) {

    newnode = new Node();
    newnode->info = ni;
    newnode->info = nm;
    newnode->next = NULL;

    cur = head;
    if (head == NULL) {
        head = newnode;
        tail = newnode;
    } else {
        while (cur->next != NULL && cur->next->info < maha->mahasiswa.nim) {
            cur = cur->next; 
        }
    }
    
    newnode->next = cur->next;
    cur->next = newnode;
}

void masuk() {
    char Z;
    int ni;
    string nm;
    cout << "NIM : ";
        cin >> ni;
    cout << "Nama : ";
    cin.ignore();
        getline(cin, nm);
    sisipTengah(ni, nm)
}

void display() {
    cur = head;
    while (cur != NULL) {
        cout << cur->info << " | ";
        cur = cur->next;
    }
}

void hapusTengah(int H) {
    cur = head;
    while (cur->next != NULL && cur->next->info != H) {
        cur = cur->next;
    }
    
    if (cur->next == NULL) {
        cout << "Tidak ada nilai " << H << " di dalam data" << endl;
    } else {
        del = cur->next;
        cur->next = del->next;
        if (del == tail) {
            tail = cur;
        }
        delete del;
    }
    
}

void Cari(int H) {
    cur = head;
    while (cur->next != NULL && cur->next->info != H) {
        cur = cur->next;
    }
    
    if (cur->next == NULL) {
        cout << "Tidak ada nilai " << H << " di dalam data" << endl;
    } else {
        cout << cur << endl;
    }
    
}

int main(){
    in();
    int X, Y;
do {
    cout << "1. Tambah" << endl;
    cout << "2. Hapus" << endl;
    cout << "3. Baca" << endl;
    cout << "4. Cari" << endl;
    cout << "5. out" << endl;
    cout << "Masuk: ";
    cin >> X;

    switch (X) {
    case 1:
        masuk();
        break;
    
    case 2:
        cout << "brp:";
            cin >> Y;
            hapusTengah(Y);
        break;
    
    case 3:
        display();
        break;
    
    case 4:
        /* code */
        break;

    default:
        break;
    }
cin.ignore();
} while (X != 5);
}