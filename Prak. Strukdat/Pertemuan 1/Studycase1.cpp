#include <bits/stdc++.h>
using namespace std;

/*
  __
<(o )___
 ( ._> /
  `---'
*/

struct mok {
    string nama;
    int umur;
    float ipk;
};

int main () {
    int N;
    cout << "Masukkan N : ";
        cin >> N;
    cin.ignore();
    mok X[N];

    for (int i = 0; i < N; i++) {
    cout << "\nMasukkan Data ke-" << i + 1 << endl;
        cout << "Masukkan Nama : ";
            getline(cin, X[i].nama);
        cout << "Masukkan umur : ";
            cin >> X[i].umur;
        cout << "Masukkan IPK : ";
            cin >> X[i].ipk;
        cin.ignore();
    }

    for (int i = 0; i < N; i++) {
        cout << "\nData ke-" << i + 1 << endl;
            cout << "Nama : " << X[i].nama << endl;
            cout << "umur : " << X[i].umur << endl;
            cout << "IPK : " << X[i].ipk << endl;
    }
    
    //Array
    string nama[5];
    int umur[5];
    float IPK[5];

    for (int i = 0; i < N; i++) {
    cout << "\nMasukkan Data ke-" << i + 1 << endl;
        cout << "Masukkan Nama : ";
            getline(cin, nama[i]);
        cout << "Masukkan umur : ";
            cin >> umur[i];
        cout << "Masukkan IPK : ";
            cin >> IPK[i];
        cin.ignore();
    }

    for (int i = 0; i < N; i++) {
        cout << "\nData ke-" << i + 1 << endl;
            cout << "Nama : " << nama[i] << endl;
            cout << "umur : " << umur[i] << endl;
            cout << "IPK : " << IPK[i] << endl;
    }        
}