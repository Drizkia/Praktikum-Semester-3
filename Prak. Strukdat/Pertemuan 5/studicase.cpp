#include <iostream>
#include <string>
using namespace std;

struct Node {
    int durasi;
    string judul;
    Node *next;
    Node *prev;
};

Node *head, *tail, *newnode, *temp, *del;

void createList() {
    head = nullptr;
    tail = nullptr;
}

bool isEmpty() {
    return head == nullptr;
}

void insertDepan(const string &judul, int dur) {
    newnode = new Node();
    newnode->judul = judul;
    newnode->durasi = dur;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    if (isEmpty()) {
        head = tail = newnode;
    } else {
        newnode->next = head;
        head->prev = newnode;
        head = newnode;
    }
}

void insertBelakang(const string &judul, int dur) {
    newnode = new Node();
    newnode->judul = judul;
    newnode->durasi = dur;
    newnode->next = nullptr;
    newnode->prev = nullptr;

    if (isEmpty()) {
        head = tail = newnode;
    } else {
        newnode->prev = tail;
        tail->next = newnode;
        tail = newnode;
    }
}

void displayDepan() {
    if (isEmpty()) {
        cout << "Tidak ada list\n";
        return;
    }
    temp = head;
    cout << "Daftar (dari depan ke belakang):\n";
    while (temp != nullptr) {
        cout << "- " << temp->judul << " (" << temp->durasi << " menit)\n";
        temp = temp->next;
    }
}

void hapusTengah(const string &IH) {
    if (isEmpty()) {
        cout << "List kosong. Isi dulu bro.\n";
        return;
    }
    if (head->judul == IH) {
        del = head;
        if (head == tail) {
            head = tail = nullptr;
        } else {
            head = head->next;
            head->prev = nullptr;
        }
        delete del;
        cout << "Berhasil menghapus: " << IH << "\n";
        return;
    }

    temp = head;
    while (temp->next != nullptr && temp->next->judul != IH) {
        temp = temp->next;
    }

    if (temp->next == nullptr) {
        cout << "Node dengan judul \"" << IH << "\" tidak ditemukan.\n";
    } else {
        del = temp->next;
        if (del == tail) {
            tail = temp;
            tail->next = nullptr;
        } else {
            temp->next = del->next;
            del->next->prev = temp;
        }
        delete del;
        cout << "Berhasil menghapus: " << IH << "\n";
    }
}

void tambahData() {
    string judul;
    int dur;

    cout << "Judul : ";
    cin.ignore(); // buang newline sisa dari cin >>
    getline(cin, judul);

    cout << "Durasi (menit) : ";
    cin >> dur;

    cout << "Pilih posisi:\n1. Depan\n2. Belakang\nPilihan: ";
    int Y;
    cin >> Y;

    if (Y == 1) insertDepan(judul, dur);
    else if (Y == 2) insertBelakang(judul, dur);
    else cout << "Pilihan salah.\n";
}

int main() {
    createList();
    int X;
    string Z;

    do {
        cout << "Pilihan: ";
        cin >> X;

        switch (X) {
            case 1:
                tambahData();
                break;
            case 2:
                displayDepan();
                break;
            case 3:
                cin.ignore();
                cout << "Masukkan judul yang akan dihapus: ";
                getline(cin, Z);
                hapusTengah(Z);
                break;
            case 4:
                cout << "Keluar program.\n";
                break;
            default:
                cout << "Pilihan tidak dikenali.\n";
                break;
        }
    } while (X != 4);

    while (!isEmpty()) {
        del = head;
        head = head->next;
        delete del;
    }

    return 0;
}
