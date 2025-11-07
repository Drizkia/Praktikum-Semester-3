#include <iostream>
using namespace std;

struct Node {
    int nilai;
    Node *kiri, *kanan;
};

Node *buatNode(int nilai) {
    Node *baru = new Node();
    baru->nilai = nilai;
    baru->kiri = baru->kanan = NULL;

    return baru;
}

Node *sisipNode(Node* akar, int nilai) {
    if (akar == NULL) {
        return buatNode(nilai);
    }
    
    if (nilai < akar->nilai) {
        akar->kiri = sisipNode(akar->kiri, nilai);
    } else if (nilai > akar->nilai) {
        akar->kanan = sisipNode(akar->kanan, nilai);
    } else {
        cout << "Gagal memasukkan Node, Nilai sudah ada" << endl;
    }
    return akar;
}

bool cariNode(Node *akar, int nilai) {
    if (akar == NULL) {
        return false;
    }
    
    if (akar->nilai == nilai) {
        return true;
    } else if (nilai < akar->nilai) {
        return cariNode(akar->kiri, nilai);
    } else {
        return cariNode(akar->kanan, nilai);
    }
}

Node *nilaiMinimum(Node *akar) {
    while (akar && akar->kiri != NULL) {
        akar = akar->kiri;
    }
    return akar;
}

Node *hapusNode(Node *akar, int nilai) {
    if (akar == NULL) {
        return akar;
    }
    
    if (nilai < akar->nilai) {
        akar->kiri = hapusNode(akar->kiri, nilai);
    } else if (nilai > akar->nilai) {
        akar->kanan = hapusNode(akar->kanan, nilai);
    } else {
        if (akar->kiri == NULL) {
            Node* temp = akar->kanan;
            delete akar;
            return temp;
        } else if (akar->kanan == NULL) {
            Node* temp = akar->kiri;
            delete akar;
            return temp;
        }
        
        Node *temp = nilaiMinimum(akar->kanan);
        akar->nilai = temp->nilai;
        akar->kanan = hapusNode(akar->kanan, temp->nilai);
        
    }
    return akar;
}

void tampilkanPohon(Node *akar, int spasi = 0, int jarak = 5) {
    if (akar == NULL) {
        return;
    }
    spasi += jarak;
    tampilkanPohon(akar->kanan, spasi);
    cout << endl;
    for (int i = jarak; i < spasi; i++) {
        cout << " ";
    }
    cout << akar->nilai << endl;
    tampilkanPohon(akar->kiri, spasi);
}

//! Dari kiri
void postorder(Node *akar) {
    if (akar != NULL) {
        postorder(akar->kiri);
        postorder(akar->kanan);
        cout << akar->nilai << " ";
    }
}

//! Besar ke kecil
void preorder(Node *akar) {
    if (akar != NULL) {
        cout << akar->nilai << " ";
        preorder(akar->kiri);
        preorder(akar->kanan);
    }
}

//! Kecil ke besar
void inorder(Node *akar) {
    if (akar != NULL) {
        inorder(akar->kiri);
        cout << akar->nilai << " ";
        inorder(akar->kanan);
    }
}

int main() {
    Node* akar = NULL;
    akar = sisipNode(akar, 6);
    akar = sisipNode(akar, 8);
    akar = sisipNode(akar, 4);
    akar = sisipNode(akar, 10);
    akar = sisipNode(akar, 5);

    tampilkanPohon(akar);
    
    akar = hapusNode(akar, 8);
    cout << "\n\nSesudah Dihapus\n";
    tampilkanPohon(akar);

    cout << "\nInorder: "; inorder(akar);
    cout << "\nPreorder: "; preorder(akar);
    cout << "\nPostorder: "; postorder(akar);
}