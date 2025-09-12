#include <bits/stdc++.h>
using namespace std;

/*
  __
<(o )___
 ( ._> /
  `---'
*/

int Q(int &p) {
    p += 10;
    return p;
}

int main () {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int a = 70;
    int *p = &a;

    Q(*p);
    cout << *p << endl;
}