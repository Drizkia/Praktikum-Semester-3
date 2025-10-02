#include <iostream>
using namespace std;

struct Node {
        int lama_inap;
        string nama;
        int kamar;
        int id = 0;
        string kode;
    Node *next;
    Node *prev;
};

struct Note {
        int lama_inap;
        string nama;
        int kamar;
        int id = 0;
        string kode;
    Note *next;
    Note *prev;
};

Node *head, *tail, *newnode, *temp, *del;
Note *hd, *tl, *nw, *tmp, *dele;
bool kamar_ada[6] = {false, true, true, true, true, true};
int ini_id = 0;

void createList() {
    head = NULL;
    tail = NULL;

    hd = NULL;
    tl = NULL;
}

bool isEmpty() {
    return head == NULL;
}

bool isEmpt() {
    return hd == NULL;
}

bool cek_kamar(int no_kammar) {
    if (no_kammar < 1 || no_kammar > 5) {
        return false;
    }
    return kamar_ada[no_kammar];
    
}

void tampil_kamar() {
    int length = sizeof(newnode->kamar);
    cout << "Kamar yang tersedia : ";
    for (int i = 1; i <= length+1; i++) {
        if (kamar_ada[i] == true) {
            cout << i << " | ";
        }
    }
    cout << endl;
}

void checkout() {
    cout << "==================================" << endl; 
    cout << "|          MENU CHECKOUT         |" << endl; 
    cout << "==================================" << endl;
    newnode = new Node();

    if (isEmpty()) {
        cout << "Belum Ada Data Tersimpan" << endl;
        return;
    }
    
    string code;
    char P;
    cout << endl;
    cout << "Masukkan Kode Unik yang ingin di cari : ";
        cin >> code; 
    cout << endl;

    temp = head;
while (temp != NULL) {
    if (code == temp->kode) {
        cout << "Data ditemukan di list ke-" << temp->id << endl;
        cout << "Id : " << temp->id << endl;
        cout << "Nama : " << temp->nama << endl;
        cout << "Lama Inap : " << temp->lama_inap << endl;
        cout << "No Kamar : " << temp->kamar << endl;

        del = temp;

        cout << "Apakah ingin checkout ? [y/n] ";
            cin >> P;
        if (P == 'y' || P == 'Y') {
            cout << "[ Terima kasih atas kunjungan :3 ]" << endl;
                if (del == head && del == tail) {
                    head = NULL;
                    tail = NULL;
                } else if (del == head) {
                    head = head->next;
                    head->prev = NULL;
                } else if (del == tail) {
                    tail = tail->prev;
                    tail->next = NULL;
                } else {
                    del->prev->next = del->next;
                    del->next->prev = del->prev;
                }
            
            delete(del);

                kamar_ada[temp->kamar] = true;
        } else {
            cout << "Anda Tidak Jadi Checkout" << endl;
            return;
        }        
    }
    temp = temp->next;
}
}

void input() {
    cout << "==================================" << endl; 
    cout << "|           MENU INPUT           |" << endl; 
    cout << "==================================" << endl;

    if (isEmpty()) {
        createList();
    }
    
    int dat;
    string A, B, C;

    tampil_kamar();
    cout << "Masukkan jumlah data yang ingin diinput : ";
        cin >> dat;
        cin.ignore();
    cout << endl;
    
    for (int j = 1; j <= dat; j++) {
        newnode = new Node();
        nw = new Note();
        newnode->next = NULL;
        nw->next = NULL;
        newnode->prev = NULL;
        nw->prev = NULL;

        cout << "Data ke-" << j << endl;
        cout << "Nama           : ";
            getline(cin, newnode->nama);
        cout << "Lama Menginap  : ";
            cin >> newnode->lama_inap;
        cout << "No Kamar       : ";
            cin >> newnode->kamar;
                cin.ignore();

        if (!cek_kamar(newnode->kamar)) {
            cout << "Kamar tidak tersedia" << endl;
            j--;
            delete newnode;
            continue;
        } else {
            ini_id++;
            newnode->id = ini_id;
            A = to_string(ini_id);
            B = to_string(newnode->lama_inap);
            C = to_string(newnode->kamar);

            newnode->kode = A + B + C;
            cout << "Kode unik kamar : " << newnode->kode << endl;
            cout << endl;
            cout << endl;

            kamar_ada[newnode->kamar] = false;
            tampil_kamar();
            cout << endl;

            nw->id = newnode->id;
            nw->nama = newnode->nama;
            nw->kamar = newnode->kamar;
            nw->kode = newnode->kode;
            nw->lama_inap = newnode->lama_inap;


            if (isEmpty()) {
                head = newnode;
                tail = newnode;
            } else {
                tail->next = newnode;
                newnode->prev = tail;
                tail = newnode;
            }

            if (isEmpt()) {
                hd = nw;
                tl = nw;
            } else {
                tl->next = nw;
                nw->prev = tl;
                tl = nw;
            }
        }
    }
    char P;
    cout << "Kembali ke menu ?[y/n] ";
        cin >> P;
    if (P == 'y' || P == 'Y') {
        return;
    } else {
        exit(0);
    }
}

void Cetak_Laporan() {
    cout << "==================================" << endl; 
    cout << "|          MENU LAPORAN          |" << endl; 
    cout << "==================================" << endl;

    if (isEmpt()) {
        cout << "Tidak ada Data" << endl << endl;
        return;
    } else {
        tmp = hd;
        while (tmp != NULL) {
            cout << "Id : " << tmp->id << endl;
            cout << "Nama : " << tmp->nama << endl;
            cout << "Lama Inap : " << tmp->lama_inap << endl;
            cout << "No Kamar : " << tmp->kamar << endl;
                tmp = tmp->next;
        }
    cout << endl;
    }
}

void Cetak_Laporan_Aktif() {
    cout << "==================================" << endl; 
    cout << "|          MENU LAPORAN          |" << endl; 
    cout << "==================================" << endl;

    if (isEmpty()) {
        cout << "Tidak ada Data" << endl << endl;
        return;
    } else {
        temp = head;
        while (temp != NULL) {
            cout << "Id : " << temp->id << endl;
            cout << "Nama : " << temp->nama << endl;
            cout << "Lama Inap : " << temp->lama_inap << endl;
            cout << "No Kamar : " << temp->kamar << endl;
                temp = temp->next;
        }
    cout << endl;
    }
}

void hapus_data() {
    cout << "==================================" << endl; 
    cout << "|           MENU DELETE          |" << endl; 
    cout << "==================================" << endl;

    newnode = new Node();

    if (isEmpty()) {
        cout << "Belum Ada Data Tersimpan" << endl;
        return;
    }
    
    string code;
    char P;
    cout << endl;
    cout << "Masukkan Kode Unik yang ingin di cari : ";
        cin >> code;
    cout << endl;

    tmp = hd;
    while (tmp != NULL) {
        if (code == tmp->kode) {
            dele = tmp;

            temp = head;
            while (temp != NULL) {
                if (temp->kode == code) {
                    cout << "Belum Checkout, Checkout dulu yaa" << endl;
                    return;
                } else {
                    break;
                }
                temp = temp->next;
            }
            

            cout << "Apakah ingin checkout ? [y/n] ";
                cin >> P;
            if (P == 'y' || P == 'Y') {
                cout << "[ Node ditemukan dan telah dihapus ]" << endl << endl;
                    if (dele == hd && dele == tl) {
                        hd = NULL;
                        tl = NULL;
                    } else if (dele == hd) {
                        hd = hd->next;
                        hd->prev = NULL;
                    } else if (dele == tl) {
                        tl = tl->prev;
                        tl->next = NULL;
                    } else {
                        dele->prev->next = dele->next;
                        dele->next->prev = dele->prev;
                    }

                delete(dele);

            } else {
                cout << "Anda Tidak Ada Data" << endl;
                return;
            }        
        }
        tmp = tmp->next;
    }
}

int main() {
    int menu; 

    do {
        cout << "\n==================================" << endl; 
        cout << "|     MENU PESAN KAMAR HOTEL     |" << endl; 
        cout << "==================================" << endl;
        cout << "1. Pesan Kamar" << endl;
        cout << "2. Checkout Kamar" << endl;
        cout << "3. Cetak Laporan Keseluruhan" << endl;
        cout << "4. Cetak Laporan Pengunjung Aktif" << endl;
        cout << "5. Hapus Data Laporan" << endl << endl;
        cout << "0. Keluar" << endl;
        cout << "----------------------------------" << endl;
        cout << "Pilih menu : ";
            cin >> menu;
        
        switch (menu) {
        case 1:
        cout << endl;
            input();
            break;
        
        case 2:
        cout << endl;
            checkout();
            break;
        
        case 3:
        cout << endl;
            Cetak_Laporan();
            break;

        case 4:
        cout << endl;
            Cetak_Laporan_Aktif();
            break;
        
        case 5:
        cout << endl;
            hapus_data();
            break;
        
        case 0:
            exit(0);
            break;
        
        default:
        cout << endl;
            cout << "Pilihan Menu Tidak Ada, Ulangi!" << endl;
            break;
        }
    } while (menu != 0);
    
}