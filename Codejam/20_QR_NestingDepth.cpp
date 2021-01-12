#include<bits/stdc++.h>
using namespace std;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        string s;
        cout << "Case #" << t << ':' << ' ';
        cin >> s;
        int n = s.size();
        int last = 0;
        for (int i = 0; i < n; i++) {
            int now = s[i]-'0';
            int p = (now-last);
            for (int pp = 0; pp < p; pp++) {
                cout << '(';
            }
            for (int pp = 0; pp > p; pp--) {
                cout << ')';
            }
            cout << s[i];
            last = now;
        }
        for (int pp = 0; pp > (-last); pp--) {
            cout << ')';
        }
        cout << endl;
    }
    return 0;
}