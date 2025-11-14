#include <iostream>
#include <iomanip>
using namespace std;


struct Bagasi {
	int ft; //* Flight Time
    float bb; //* Berat Bagasi
};

struct Node {
	Bagasi bubi;
    Node *kiri, *kanan;
};

struct queue {
	Bagasi bubi;
	queue *next;
};

queue *front = NULL;
queue *rear = NULL;

bool isEmptyQ() {
	return front == nullptr;
}

struct stack {
	Bagasi bubi;
    stack *next;
    stack *prev;
};

stack *top, *bottom, *newnode, *del, *temp;

void cetakBagasi(Bagasi b) {
	cout << "[Flight:" << setfill('0') << setw(4) << b.ft 
		<< "|Berat:" << fixed << setprecision(1) << b.bb << "kg]";
}

void createStack() {
    top = NULL;
    bottom = NULL;
}

bool isEmptyS() {
    if (top == NULL) {
        return true;
    } else {
        return false;
    }
}

bool berhasil = false;

Node *buatNode(int ft, float bb) {
    Node *baru = new Node();
    baru->bubi.ft = ft;
    baru->bubi.bb = bb;
    baru->kiri = baru->kanan = NULL;

    return baru;
}

Node *sisipNode(Node* akar, int ft, float bb) {
    if (akar == NULL) {
        return buatNode(ft, bb);
    }
    
    if (ft < akar->bubi.ft) {
        akar->kiri = sisipNode(akar->kiri, ft, bb);
    } else if (ft > akar->bubi.ft) {
        akar->kanan = sisipNode(akar->kanan, ft, bb);
    } else {
        cout << "Gagal memasukkan Flight Time, sudah ada" << endl;
		berhasil = false;
    }
    return akar;
}

Node* satu(Node *akar) {
	int ft;
	float bb;
	bool a = false, b = false;
	berhasil = true;

	cout << "--- Input Data Bagasi Baru ---" << endl;
	while (!a) {
		cout << "Flight Time (Format HHMM, cth: 1430): ";
		cin >> ft;
		if (ft < 0 || ft > 2359) {
			cout << "ERROR: Format jam tidak valid (0000 - 2359, menit 00-59)." << endl;
			system("pause");
		} else {
			a = true;
		}
	}
	
	while (!b) {
		cout << "Berat Bagasi (kg, harus > 0): ";
			cin >> bb;
		if (bb < 0) {
			cout << "ERROR: Berat harus positif." << endl;
			system("pause");
		} else {
			b = true;
		}
	}
	
	akar = sisipNode(akar, ft, bb);
	return akar;
}

void dua(Node *akar) {
	if (akar != NULL) {
        dua(akar->kiri);
		// cout << "->";
		// cetakBagasi(akar->bubi); //* Gamau Ga Rapi
		// cout << endl;
        cout << "-> [Flight: " << akar->bubi.ft << " | " << "Berat: " << akar->bubi.bb << " ]" << endl;
        dua(akar->kanan);
	} 
}

void enqueue(int ft, float bb) {
	queue *newNode = new queue();
	newNode->bubi.ft = ft;
	newNode->bubi.bb = bb;
	newNode->next = nullptr;

	if (isEmptyQ()) {
		front = rear = newNode;
		rear->next = front; // circular link
	} else {
		rear->next = newNode;
		rear = newNode;
		rear->next = front; // circular link
	}
}

Node *nilaiMinimum(Node *akar) {
    while (akar && akar->kiri != NULL) {
        akar = akar->kiri;
    }
    return akar;
}

Node *hapusNode(Node *akar, int ft, int bb) {
    if (akar == NULL) {
        return akar;
    }
    
    if (ft < akar->bubi.ft) {
        akar->kiri = hapusNode(akar->kiri, ft, bb);
    } else if (ft > akar->bubi.ft) {
        akar->kanan = hapusNode(akar->kanan, ft, bb);
    } else {
		Node* temp = akar;
        if (akar->kiri == NULL) {
			akar = akar->kanan;
        } else if (akar->kanan == NULL) {
			akar = akar->kiri;
        }
        delete temp;
    }
    return akar;
}

void tiga(Node *&akar) {
	if (akar == NULL) {
		cout << "GAGAL: PTB Kosong! Input data dulu di Menu 1." << endl;
		return;
	}

	while (akar != NULL) {
		Node *X = nilaiMinimum(akar);

		enqueue(X->bubi.ft, X->bubi.bb);

		int fdel = X->bubi.ft;
		float bdel = X->bubi.bb;

		akar = hapusNode(akar, fdel, bdel);
	}
	cout << "-> SUKSES: Semua data dipindahkan dari PTB ke Queue Konveyor." << endl;
	cout << "-> INFO: Database PTB sekarang telah dikosongkan." << endl;
}

void empat() {
	if (isEmptyQ()) {
		cout << "(Queue kosong.)" << endl;
		return;
	}

	queue *temp = front;
	do {
		// cout << "-> ";
		// cetakBagasi(temp->bubi); //* Gamau Ga Rapi
		// cout << endl;
		cout << "-> [Flight: " << temp->bubi.ft << " | " << "Berat: " << temp->bubi.bb << " ]" << endl;
		temp = temp->next;
	} while (temp != front);
	cout << endl;
}

void push(int ft, float bb) {
    newnode = new stack();
	newnode->bubi.ft = ft;
	newnode->bubi.bb = bb;
    newnode->next = NULL;
    newnode->prev = NULL;

    if(isEmptyS()) {
        top = newnode;
        bottom = newnode;
    } else {
        top->next = newnode;
        newnode->prev = top;
        top = newnode;
    }
}

void lima() {
	if (isEmptyQ()) {
		cout << "GAGAL: Konveyor kosong! Load data dulu di Menu 3." << endl;
		return;
	}

	string status = "", kata = "";

	while (!isEmptyQ()) {
		queue *temp = front;
		if (front == rear) {
			front = rear = nullptr;
		} else {
			front = front->next;
			rear->next = front;
		}
		
		if (temp->bubi.bb <= 9.3) {
			status = "AMAN";
			kata = " (Lolos ke Pesawat)";
		} else {
			status = "OVERWEIGHT";
			kata = "! (Push ke Stack)";
		}
	
		cout << "Scan: ";
		// cetakBagasi(temp->bubi); //* Gamau Ga Rapi
		cout << "Scan: [Flight:" << temp->bubi.ft << " | Berat:" << temp->bubi.bb << "kg]";
		cout << " -> STATUS: " << status << kata << endl;
		if (status == "OVERWEIGHT") {
			push(temp->bubi.ft, temp->bubi.bb);
		} 
		delete temp;
		status = kata = "";
	}
	cout << "-> Konveyor telah kosong. Proses scanning selesai." << endl;
}

void enem() {
    if (isEmptyS()) {
        cout << "(Stack Kosong)" << endl;
		return;
    }

        temp = top;
        while (temp != NULL) {
            cout << "[TOP] [Flight: " << temp->bubi.ft << " | ";
            cout << "Berat: " << temp->bubi.bb << "]" << endl;
            temp = temp->prev;
        }
}

void pitu() {
    if (isEmptyS()) {
        cout << "INFO: Stack kosong. Tidak ada bagasi overweight." << endl;
		return;
    }
	
	del = top;
	while (del != NULL) {
		cout << "Petugas memeriksa: [Flight: " << del->bubi.ft << " | ";
		cout << "Berat: " << del->bubi.bb << "] -> SELESAI DIPERIKSA." << endl;
		if (top == bottom) {
			top = bottom = NULL;
		} else {
			top = top->prev;
			top->next = NULL;
		}
		delete del;
		del = del->prev;
	}
	cout << "-> Semua bagasi overweight telah diperiksa. Tumpukan kosong." << endl;
}

int main() {
	bool y = false;
	int x;
	Node *akar = NULL;
	createStack();
	while(!y) {
		cout << "\n=== Sistem Keamanan Bandara ===" << endl;
		cout << "1. [PTB] Check-In Bagasi (Input Data)" << endl;
		cout << "2. [PTB] Lihat Database Bagasi (Cetak PTB)" << endl;
		cout << "3. [PTB -> Queue] Pindahkan Semua ke Konveyor (Hapus PTB)" << endl;
		cout << "4. [Queue] Lihat Antrian Konveyor (Cetak Queue)" << endl;
		cout << "5. [Queue -> Stack] Proses Scanning X-Ray" << endl;
		cout << "6. [Stack] Lihat Tumpukan Overweight (Cetak Stack)" << endl;
		cout << "7. [Stack Process] Pemeriksaan Manual (Pop Semua)" << endl;
		cout << "0. Keluar" << endl;
		cout << "Pilihan Anda: ";
			cin >> x;
		
		switch (x) {
			case 1:
				berhasil = true;
				akar = satu(akar);
				if (berhasil) {
					cout << "-> Data berhasil masuk ke Database PTB." << endl;
				}
				system("pause");
				break;
			
			case 2:
			cout << "--- Isi Database Bagasi (PTB Inorder)" << endl;
				if (akar == NULL) {
					cout << "(Database Kosong)" << endl;
				} else {
					dua(akar);
				} 
				system("pause");
				break;
			
			case 3:
				if (akar == NULL) {
					cout << "GAGAL: PTB Kosong! Input data dulu di Menu 1." << endl;
				} else {
					tiga(akar);
				}
				system("pause");
				break;
			
			case 4:
			cout << "--- Isi Antrian Konveyor (Queue) ---" << endl;
				empat();
				system("pause");
				break;
			
			case 5:
				cout << "--- Memulai Proses Scanning X-Ray ---" << endl;
				cout << "Aturan Filter: Berat > 9.3 kg = OVERWEIGHT (masuk stack)" << endl << endl;
				lima();
				system("pause");
				break;
			
			case 6:
				cout << "--- Isi Area Isolasi (Tumpukan Stack) ---" << endl;
				enem();
				system("pause");
				break;

			case 7:
				cout << "--- Pemeriksaan Manual (Pop Stack sampai habis) ---" << endl;
				pitu();
				system("pause");
				break;
			
			case 0:
				y = true;
				cout << "Keluar dari program..." << endl;
				cout << "Terimakasih!" << endl;
				break;
		
		default:
			cout << "Pilihan Tidak Ada" << endl;
			break;
		}
	}

}
