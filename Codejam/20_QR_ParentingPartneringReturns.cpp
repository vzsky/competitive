#include<bits/stdc++.h>
using namespace std;

struct A {
    int s, e, i;
    bool operator < (const A & o) const {
        return s < o.s;
    }
};

A e[1010];
char ans[1010];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int T; cin >> T;
    for (int t = 1; t <= T; t++) {
        cout << "Case #" << t << ':' << ' ';
        int n; cin >> n;
        for (int i = 0; i < n; i++) {
            cin >> e[i].s >> e[i].e;
            e[i].i = i;
        }
        sort(e, e+n);
        bool flag = true;
        int c = 0, j = 0;
        for (int i = 0; i < n; i++) {
            if (e[i].s >= c) {
                ans[e[i].i] = 'C';
                c = e[i].e;
            }
            else if (e[i].s >= j) {
                ans[e[i].i] = 'J';
                j = e[i].e;
            }
            else {
                flag = false;
                break;
            }
        }
        if (flag) {
            for (int i = 0; i < n; i++) cout << ans[i];
            cout << '\n';
        }
        else {
            cout << "IMPOSSIBLE\n";
        }
    }
    return 0;
}