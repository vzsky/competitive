#include<bits/stdc++.h>
using namespace std;

vector<int> pcess[100100];
bool taken[100100];
bool happy[100100];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t; cin >> t;
    while (t--) {
        int  n; cin >> n;
        for (int i = 1; i <= n;i ++) {
            pcess[i].clear();
        }
        for (int i = 1; i <= n; i++) {
            int k; cin >> k; 
            for (int j = 0; j < k; j++) {
                int a; cin >> a;
                pcess[i].push_back(a);
            }
        }
        for (int i = 0; i <= n; i++) {
            taken[i] = happy[i] = 0;
        }
        for (int i = 1; i <= n; i++) {
            for (int p : pcess[i]) {
                if (taken[p]) continue;
                happy[i] = 1;
                taken[p] = 1;
                break;
            }
        }
        int unhap = -1, ava = -1;
        for (int i = 1; i <= n; i++) {
            if (!happy[i]) {
                unhap = i;
                break;
            }    
        }
        for (int i = 1; i <= n; i++) {
            if (!taken[i]) {
                ava = i;
                break;
            }    
        }
        if (unhap == -1 or ava == -1) cout << "OPTIMAL" << endl;
        else cout << "IMPROVE" << endl << unhap << ' ' << ava << endl;
    }
    return 0;
}