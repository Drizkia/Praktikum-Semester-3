#include <bits/stdc++.h>
using namespace std;

/*
  __
<(o )___
 ( ._> /
  `---'
*/

void point() {
    int a = 10;
    int *pb = &a;

    cout << "Nilai a : " << a << endl;
    cout << "Nilai &a : " << &a << endl << endl;
    cout << "Nilai pb : " << pb << endl;
    cout << "Nilai &pb : " << &pb << endl;
    cout << "Nilai *pb : " << *pb << endl;

}

void perban() {
    int a = 100, b = 200, *pa, *pb;

    pa = &a;
    pb = &b;

    if(pa < pb) {
      cout << "pa Merujuk pada memori rendah PB" << endl;
    }
}

void arr_point() {
    int nilai[3], *penunjuk;

    nilai[0] = 125;
    nilai[1] = 345;
    nilai[2] = 750;

    penunjuk = &nilai[0];

    cout << "Nilai " << *penunjuk << " ada di alamat memori " << penunjuk << endl;
    cout << "Nilai " << *(penunjuk + 1) << " ada di alamat memori " << penunjuk + 1 << endl;
    cout << "Nilai " << *(penunjuk + 2) << " ada di alamat memori " << penunjuk + 2 << endl;
    cout << "Nilai " << *penunjuk + 3 << " ada di alamat memori " << penunjuk + 2 << endl; // untuk nambahin isi value
}

void p_Array () {
    char tokoh[] = "Roronoa Zoro";
    const char *ptokoh = "Roronoa Zoro"; //supaya ga error
    cout << "Tokoh = " << tokoh << endl;
    cout << "pTokoh = " << ptokoh << endl;
    
    // ptokoh++;
    cout << endl;
    cout << "Tokoh = " << tokoh << endl;
    cout << "pTokoh = " << ptokoh << endl;
    cout << "pTokoh = " << *ptokoh << endl; // Output R
    cout << "pTokoh = " << *(ptokoh + 1) << endl; // Output O
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    

}