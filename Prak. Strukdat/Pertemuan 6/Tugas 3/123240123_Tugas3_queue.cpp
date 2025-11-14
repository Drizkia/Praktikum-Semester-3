#include <iostream>
using namespace std;

struct Node {
    string roti, nama_pembeli;
    int jumlah, harga;
    Node *next;
};

Node *newnode, *temp_del, *temp, *rear = NULL, *front = NULL;

bool isempty() {
    if (front == NULL)
        return true;
    return false;
}

void menu() {
    cout << "a. Roti Gulung (Rp20.000)" << endl;
    cout << "b. Roti Brownies (Rp25.000)" << endl;
    cout << "c. Roti Lapis (Rp30.000)" << endl;
    cout << "d. Roti Nastar (Rp40.000)" << endl;
}

void pesan() {
    int z, h;
    char s;
    bool x = false, y = false;
    string c;
        cout << "\n======================" << endl;
        cout << "#       PESAN        #" << endl;
        cout << "======================" << endl;
        while (!x) {
            cout << "Banyak pemesan: ";
                cin >> z;
            if (z > 0) {
                x = true;
            } else {
                cout << "Harus Angka Positif" << endl;
            }
        }
        
        for (int i = 0; i < z; i++) {
            y = false;
        newnode = new Node();
            cout << "Pesanan ke-" << i+1 << endl;
            cout << "Nama: ";
            cin.ignore();
                getline(cin, newnode->nama_pembeli);
            menu();
            cout << "Pilih menu (a/b/c/d): ";
                cin >> s;
            
            switch (s) {
                case 'a':
                    newnode->roti = "Roti Gulung";
                    cout << "[Roti Gulung]" << endl;
                    while (!y) {
                        cout << "Jumlah pesanan: ";
                        cin >> newnode->jumlah;
                        if (newnode->jumlah > 0) {
                            y = true;
                        } else {
                            cout << "Harus Angka Positif" << endl;
                        }
                    }
                        h = 20000;
                        newnode->harga = h * newnode->jumlah;
                    cout << endl;
                    break;
                
                case 'b':
                    newnode->roti = "Roti Brownies";
                    cout << "[Roti Brownies]" << endl;
                    while (!y) {
                        cout << "Jumlah pesanan: ";
                        cin >> newnode->jumlah;
                        if (newnode->jumlah > 0) {
                            y = true;
                        } else {
                            cout << "Harus Angka Positif" << endl;
                        }
                    }
                        h = 25000;
                        newnode->harga = h * newnode->jumlah;
                    cout << endl;
                    break;
                
                case 'c':
                    newnode->roti = "Roti Lapis";
                    cout << "[Roti Lapis]" << endl;
                    while (!y) {
                        cout << "Jumlah pesanan: ";
                        cin >> newnode->jumlah;
                        if (newnode->jumlah > 0) {
                            y = true;
                        } else {
                            cout << "Harus Angka Positif" << endl;
                        }
                    }
                        h = 30000;
                        newnode->harga = h * newnode->jumlah;
                    cout << endl;
                    break;
                
                case 'd':
                    newnode->roti = "Roti Nastar";
                    cout << "[Roti Nastar]" << endl;
                    while (!y) {
                        cout << "Jumlah pesanan: ";
                        cin >> newnode->jumlah;
                        if (newnode->jumlah > 0) {
                            y = true;
                        } else {
                            cout << "Harus Angka Positif" << endl;
                        }
                    }
                        h = 40000;
                        newnode->harga = h * newnode->jumlah;
                    cout << endl;
                    break;
            default:
                cout << "Menu tidak ada, ulangi" << endl;
                i -= 1;
                break;
            }
            if (isempty()) {
                front = rear = newnode;
            } else {
                rear->next = newnode;
                rear = newnode;
            }
        }
}

void antri() {
    if (isempty()) {
        cout << "Antrian Kosong" << endl;
        return;
    }
    int i = 0;
    cout << "\n======================" << endl;
    cout << "#       ANTRIAN       #" << endl;
    cout << "======================" << endl;
    cout << "[Nama, Pesanan, Jumlah, Total]" << endl;
    cout << endl;
    
    temp = front;
    while (temp != NULL) {
        i += 1;
        cout << i << "[" << temp->nama_pembeli << ", " << temp->roti << ", " << temp->jumlah << ", Rp" << temp->harga << "]" << endl;
        temp = temp->next;
    }
}

void ambil() {
    if (isempty()) {
        cout << "Antrian kosong" << endl;
        return;
    } 
    temp = front;
    cout << "\n======================" << endl;
    cout << "#        AMBIL       #" << endl;
    cout << "======================" << endl;
    cout << "Nama: " << temp->nama_pembeli << endl; 
    cout << "Pesanan: " << temp->roti << endl; 
    cout << "Jumlah: " << temp->jumlah << endl; 
    cout << "Total: " << temp->harga << endl;
    cout << "PESANAN BERHASIL DIAMBIL" << endl;
    
    front = front->next;
    delete temp;
}

int main() {
    bool x = false;
    char o;
    int z;
    while (!x) {
        cout << "\n======================" << endl;
        cout << "#   TOKO ROTI ENAK   #" << endl;
        cout << "======================" << endl;
        cout << "|1. Pesan            |" << endl;
        cout << "|2. Ambil            |" << endl;
        cout << "|3. Lihat Antrian    |" << endl;
        cout << "|4. Exit             |" << endl;
        cout << "======================" << endl;
        cout << "Pilih (1-4): ";
            cin >> z;
        
        switch (z) {
            case 1:
                pesan();
                break;
            
            case 2:
                ambil();
                break;
            
            case 3:
                antri();
                break;
            
            case 4:
                x = true;
                cout << "Terimakasih ^_^" << endl;
                exit(0);
                break;
            
            default:
                cout << "Pilihan tidak ada, ulangi!" << endl;
                break;
            }

            cout << "Ulang menu (y/n): ";
                cin >> o;
            if (o != 'y' && o != 'Y') {
                break;
            } else {
                x = false;
            }
    }
}