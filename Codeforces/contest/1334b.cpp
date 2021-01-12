#include<bits/stdc++.h>
using namespace std;

int a[100100];


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        long long n, k; cin >> n >> k;
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        sort (a, a+n);
        long long sum = 0;
        int j = 1;
        for (int i = n-1; i >= 0; i--, j++) {
            sum += a[i];
            cerr << sum << ' ' << j << endl;
            if ((sum/j) >= k) continue;
            else {break;}
        }
        cout << j-1 << '\n';
    }
    return 0;
}