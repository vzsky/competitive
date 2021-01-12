#include<bits/stdc++.h>
using namespace std;


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int a = 0, b = 0;
        bool flag = true;
        for (int i = 0; i < n; i++) {
            int p, c; cin >> p >> c;
            if (c-b > p-a) {flag = false;}
            if (c > b && p <= a) {flag = false; }
            if (p < a) {flag = false; }
            if (c < b) {flag = false; }
            a = p; b = c;
        }   
        cout << (flag?"YES":"NO") << '\n';
    }
    return 0;
}