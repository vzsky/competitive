#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        if (n == 1) {
            cout << -1 << endl;
            continue;
        }
        for (int i = 0; i < n-1; i++) cout << "3";
        cout << "4" << endl;
    }
    return 0;
}