#include <bits/stdc++.h>
using namespace std;

/*
  __
<(o )___
 ( ._> /
  `---'
*/

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a = 10;
    int *pb = &a;

    cout << "Nilai a : " << a << endl;
    cout << "Nilai &a : " << &a << endl << endl;
    cout << "Nilai pb : " << pb << endl;
    cout << "Nilai &pb : " << &pb << endl;
    cout << "Nilai *pb : " << *pb << endl;
}