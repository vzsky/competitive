#include<bits/stdc++.h>
using namespace std;

// int a = 12253, b = 1231221, cnt = 0;
// int grade(int x, int y){ cnt++; return ((x^a) > (y^b))?1:((x^a) == (y^b))?0:-1; }
// void ans (int x, int y) { assert(y == b and x == a); cout << "OK " << cnt << endl; }

int grade(int x, int y) {
    cout << "? " << x << ' ' << y << endl;
    int r; cin >> r; return r;
}

void ans (int x, int y) {
    cout << "! " << x << ' ' << y << endl;
}

void solve(){
    int res = grade(0, 0);
    int c = 0, d = 0;
    int r, s;
    for (int i = 29; i >= 0; i--) {
        r = grade(c^(1<<i),d);
        s = grade(c,d^(1<<i));
        if (r == s) {
            if (res == 1) c ^= (1<<i);
            if (res == -1) d ^= (1<<i);
            res = r;
        }
        if (r != s) {
            if (s == 1) c ^= (1<<i), d ^= (1<<i);
        }
    }
    ans(c, d);
}

int main () {
    solve();
    return 0;
}