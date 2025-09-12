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
  int id = 0;
  string jendral;
  string soldierType;
  int soldierQty;
};

six batalyon[100];

void satu() {
  string type, jend;
  bool X = true;

  char yon;
do {
  batalyon[100].id + 1;
  cout << batalyon[100].id << endl;
  do {
    cout << "Input Jendral : ";
      getline(cin, jend);
      
      if (jend == batalyon[100].jendral) {
        X == true;
        cout << "Jendral Udah Ada, Ulangi" << endl;
      } else {
        jend = batalyon[100].jendral;
        X == false;
      }
  } while (X = true);

  do {
      cout << "Input Type : ";
        cin.ignore();
          getline(cin, type);
    if (type != pasukan[3]) {
      X == true;
      type == batalyon[100].soldierType;
    } else {
      X == false;
    }
    } while (X == false);

  cout << "Input Qty : ";
    cin >> batalyon[100].soldierQty;
    cout << "Apakah anda ingin kembali ke loh out?(Y/N) ";
      cin >> yon;
  } while (yon == 'N' || yon == 'n');
}

void dua() {
  cout << "=== Daftar Seluruh Batalyon ===" << endl;
  
  for (int i = 0; i < batalyon[100].id; i++) {
    cout << "ID             : " << batalyon[i].id << endl;
    cout << "Nama Jendral   : " << batalyon[i].jendral << endl;
    cout << "Tipe Pasukan   : " << batalyon[i].soldierType << endl;
    cout << "Jumlah Pasukan : " << batalyon[i].soldierQty << endl << endl;
  }
  
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int menu;

    do {
    cout << "=== Daftar Menu ===" << endl;
    cout << "=== 1. Tambah Batalyon ===" << endl;
    cout << "=== 2. Tampilkan Semua Batalyon ===" << endl;
    cout << "=== 3. Keluar ===" << endl;
    cout << "=== Pilih Menu : ";
      cin >> menu;
    
    switch (menu) {
      case 1:
      satu();
      break;
      
      case 2:
      dua();
      break;
      
      default:
      cout << "Pilihan Tidak Ada" << endl;
      cout << "Ulang!!" << endl;
      break;
    }
  cin.ignore();
  } while (menu == 3);
}