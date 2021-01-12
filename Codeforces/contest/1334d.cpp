#include<bits/stdc++.h>
using namespace std;

long long n, l, r;

long long size (long long i) {
    i--;
    return i*(2*n - (i+1));
}

long long p;

void out(int x) {
    if (l <= p and p <= r) {
        cout << x << ' ';
    }
}

void print (int s, int e) {
    for (int c = s; c <= e; c++) {
        for (int i = c+1; i <= n; i++) {
            out(c); p++;
            out(i); p++;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        cin >> n >> l >> r;

        // cerr << size(n) << endl;

        long long i;
        for (i = 1; i < n; i++) {
            // ith cluster = 2*(n-i)
            if (l <= size(i)) break;
        } // l < cluster i l is in i-1
        i--;
        long long j;
        for (j = 1; j < n; j++) {
            if (r <= size(j)) break;
        }
        j--;
        p = size(i)+1;
        print(i, j);
        // cerr << size(n)+1 << endl;
        if (r == size(n)+1) cout << 1;
        cout << '\n';
    }
    return 0;
}