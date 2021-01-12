#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        long long a, b; cin >> a >> b;
        if (a % b == 0) { cout << 0 << endl; continue; }
        long long l = 0, r = 1e9;
        while (l < r) {
            long long mid = (l+r)/2;
            if (mid*b > a) r = mid;
            else l = mid+1;
        }
        cout << b*l - a << endl;
    }
    return 0;
}