#include <iostream>
using namespace std;

/*
  __
<(o )___
 ( ._> /
  `---'
*/

int isi = 0;
string pasukan[] = {"Infantry", "Kavaleri", "Archer"};

struct six {
  int ID;
  string Nama_General;
  string Tipe_Pasukan;
  int Jumlah_Pasukan;
};

six batalyon[100];

char Z;

bool J (string nmInput) {
  for (int i = 0; i < isi; i++) {
    if (batalyon[i].Nama_General == nmInput) {
      return true;
    }
  }
  return false;
}

bool T (string pskan) {
  for (int i = 0; i < 3; i++) {
    if (pasukan[i] == pskan) {
      return false;
    }
  }
  return true;
}

void tambah () {
  string nm, typ;
  int X;

  do {
    do {
      cout << "Input General Name : ";
        getline(cin, nm);
      if (isi > 0) {
        if (J(nm)) {
          cout << "Udah ada, Ganti yang lain uy\n\n";
        } else break;
      } else break;
    } while (true);
  batalyon[isi].Nama_General = nm;
    do {
      cout << "Input Solder Type : ";
        getline(cin, typ);
          if (T(typ)) {
            cout << "Ga ada type itu, ulangi yang bener yu\n\n";
          } else break;
      } while (true);
  batalyon[isi].Tipe_Pasukan = typ;
    do {
      cout << "Input Solder Qty : ";
        cin >> X;
      if (X < 0) {
        cout << "Mana ada pasukan -, input yang bener\n\n";
      } else break;
    } while (true);
  batalyon[isi].Jumlah_Pasukan = X;
  batalyon[isi].ID = (isi + 1);
    isi++;
    cout << "\nApakah anda ingin kembali ke menu awal (Y/N) : ";
      cin >> Z;
    cout << endl;
    cin.ignore();
  } while (Z == 'n' || Z == 'N');
}

void tampil () {
  six *p = batalyon; // Pointerku di sini mas bin :D

  if (isi <= 0) {
    cout << "\nData belum ada\nIsi dulu aja bang datanya\n\n";
    return;
  }

  do {
    cout << "\n=== Daftar Seluruh Batalyon ===\n\n";
    for (int i = 0; i < isi; i++) {
      cout << "ID             : " << (p + i)->ID << endl;
      cout << "Nama General   : " << (p + i)->Nama_General << endl;
      cout << "Tipe Pasukan   : " << (p + i)->Tipe_Pasukan << endl;
      cout << "Jumlah Pasukan : " << (p + i)->Jumlah_Pasukan << endl;
      cout << endl;
    }
    cout << "Apakah anda ingin kembali ke menu awal (Y/N) : ";
      cin >> Z;
    cout << endl;
  } while (Z == 'n' || Z == 'N');
}

int main () {
    int menu;

    do {
    cout << "=== Daftar Menu ===" << endl;
    cout << "1. Tambah Batalyon" << endl;
    cout << "2. Tampilkan Semua Batalyon" << endl;
    cout << "3. Keluar" << endl;
    cout << "Pilih Menu : ";
      cin >> menu;
    cout << endl;
    cin.ignore();
    
    switch (menu) {
      case 1:
        tambah();
      break;
      case 2:
        tampil();
      break;
      case 3:
        cout << "Thank You\n";
      break;
      default:
        cout << "Pilihan Tidak Ada" << endl;
        cout << "Ulang!!" << endl;
      break;
    }
  } while (menu != 3);
}