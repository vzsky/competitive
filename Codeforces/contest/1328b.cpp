#include<bits/stdc++.h>
using namespace std;

int pos[5];
stack<char> s;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    long long t;
    cin >> t;

    while (t--) {
        long long n, k; cin >> n >> k;
        long long l = 1, r = 1e5;
        while (l < r) {
            long long mid = (l+r)/2;
            // cerr << l << ' ' << r << ' ' << mid*(mid+1) << endl;
            if (mid*(mid+1) >= 2*k) r = mid;
            else l = mid+1;
        }
        long long re = (l*(l+1))/2 - k;
        pos[0] = l;
        pos[1] = l-1-re;

        // cerr << l << ' ' << re << endl; 
        for (int i = 0; i < n; i++) {
            if (i == pos[0] or i == pos[1]) s.push('b');
            else s.push('a');
        }
        while (!s.empty()) {
            cout << s.top(); 
            s.pop();
        }
        cout << endl;
    }
    return 0;
}