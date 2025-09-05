#include <bits/stdc++.h>
using namespace std;

/*
  __
<(o )___
 ( ._> /
  `---'
*/

struct Mahasiswa {
  int nim;
  string nama;
  float ipk;
};

void aray() {
    // Array 1D
    int number[6] = {1, 2, 3, 4, 5, 6};
    string kata[6] = {"Ana", "Budi", "Jono", "Joki", "Sarhoni", "Uya Kuya"};

    cout << "\nIni Array 1D" << endl;
    cout << number[1] << endl << endl;

  // Array 2D
    int numberDua[2][3] = {{1, 2, 3},{4, 5, 6}}; //biru = baris 
  
    cout << "Ini Array 2D" << endl;
    cout << numberDua[0][2] << endl; // output 3

    cout << numberDua[1][1] << endl; // output 5
}

void struk() {
    Mahasiswa mhs1[3];
        // Mahasiswa mhs2;
        // Mahasiswa mhs3;

  //Input Struct
    // mhs1[0].nim = 53;
    // mhs1[0].nama = "khatama";
    // mhs1[0].ipk = 4.00;

    for (int i = 0; i < 3; i++) {
      cout << "\nMasukkan dara ke-" << i + 1 << endl;
      cout << "Masukkan nama : ";
        getline(cin, mhs1[i].nama);
      cout << "Masukkan NIM : ";
        cin >> mhs1[i].nim;
      cout << "Masukkan IPK : ";
        cin >> mhs1[i].ipk;
      cin.ignore();
    }

        // mhs2.nim = 53;
        // mhs2.nama = "khatama";
        // mhs2.ipk = 4.00;
    cout << endl;
        // mhs3.nim = 53;
        // mhs3.nama = "khatama";
        // mhs3.ipk = 4.00;

  //Akses Struct
  for (int i = 0; i < 3; i++) {
    cout << "\nData Ke-" << i + 1 << endl;
    cout << "Nama saya : " << mhs1[i].nama << endl;
    cout << "NIM saya : " << mhs1[i].nim << endl;
    cout << "IPK saya : " << mhs1[i].ipk << endl;
  }
}

int main () {
  aray();
  cout << "\n-------------------------------------------" << endl << endl;

  struk();
}