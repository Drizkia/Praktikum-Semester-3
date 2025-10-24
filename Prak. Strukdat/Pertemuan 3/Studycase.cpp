#include <iostream>
using namespace std;

struct Node {
    int nim;
    string nama;
    Node *next;
};

Node *head, *tail, *cur, *del, *newnode;

void in() {
    head = NULL;
    tail = NULL;
}

<<<<<<< HEAD
=======
void sisipTengah(int ni, string nm) {
    newnode = new Node();
    newnode->nim = ni;
    newnode->nama = nm;
    newnode->next = NULL;

    if (head == NULL || ni < head->nim) {
        newnode->next = head;
        head = newnode;
        if (tail == NULL) tail = newnode;
    } else {
        cur = head;
        while (cur->next != NULL && cur->next->nim < ni) {
            cur = cur->next;
        }
        newnode->next = cur->next;
        cur->next = newnode;
        if (newnode->next == NULL) tail = newnode;
    }
}

void masuk() {
    int ni;
    string nm;
    cout << "NIM : ";
    cin >> ni;
    cout << "Nama : ";
    cin.ignore();
    getline(cin, nm);
    sisipTengah(ni, nm);
}

void display() {
    cur = head;
    while (cur != NULL) {
        cout << cur->nim << " - " << cur->nama << endl;
        cur = cur->next;
    }
}

void hapusTengah(int H) {
    cur = head;
    if (head != NULL && head->nim == H) {
        del = head;
        head = head->next;
        delete del;
        return;
    }
    while (cur->next != NULL && cur->next->nim != H) {
        cur = cur->next;
    }
    if (cur->next == NULL) {
        cout << "Tidak ada NIM " << H << endl;
    } else {
        del = cur->next;
        cur->next = del->next;
        if (del == tail) tail = cur;
        delete del;
    }
}

void Cari(int H) {
    cur = head;
    while (cur != NULL && cur->nim != H) {
        cur = cur->next;
    }
    if (cur == NULL) {
        cout << "Tidak ada NIM " << H << endl;
    } else {
        cout << "Ditemukan: " << cur->nim << " - " << cur->nama << endl;
    }
}

int main() {
    in();
    int X, Y;
    do {
        cout << "1. Tambah\n2. Hapus\n3. Baca\n4. Cari\n5. out\nMasuk: ";
        cin >> X;
        switch (X) {
        case 1: masuk(); break;
        case 2: cout << "NIM yang dihapus: "; cin >> Y; hapusTengah(Y); break;
        case 3: display(); break;
        case 4: cout << "NIM yang dicari: "; cin >> Y; Cari(Y); break;
        }
    } while (X != 5);
}
>>>>>>> 2e488e5e2d5447ee4b0b114db23cf66fdd4373f7
