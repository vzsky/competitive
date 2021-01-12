#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t; cin >> t;
    while (t--) {
        long long n, k; cin >> n >> k;
        n -= (k)*(k);
        if ( n < 0 ) { cout << "NO" << endl; continue; }
        if (n % 2 == 0 ) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}