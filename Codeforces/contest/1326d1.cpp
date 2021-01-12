#include<bits/stdc++.h>
using namespace std;

string a, nw, smid, pmid;
int pre = 0, suf = 0;
int n;

bool palin (int l, int r) {
    while (1) {
        if (l >= r) return true;
        if (nw[l] == nw[r]) {
            l++; r--; continue;
        }
        return false;
    }
}

void print (string s, int l, int r) {
    for (int i = 0; i < l; i++) cout << a[i];
    cout << s;
    for (int i = r+1; i < n; i++) cout << a[i];
    cout << endl;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t; cin >> t;
    while (t--) {
        pre = suf = 0;
        a.clear();
        smid.clear();
        pmid.clear();
        nw.clear();
        cin >> a;
        n = a.size();
        
        int l = 0, r = n-1;
        while (1) {
            if (l < r and a[l] == a[r]) { l++, r--; continue; }
            break;
        }
        if (l >= r) { cout << a << endl; continue; }
        for (int i = l; i <= r; i++) {
            nw.push_back(a[i]);
        }
        // cerr << nw << endl;

        int m = nw.size();
        
        for (int i = m-1; i >= 0; i--) {
            if (palin(0, i)) {
                pre = i; break;
            } 
        }
        for (int i = 0; i < m; i++) {
            if (palin(i, m-1)) {
                suf = i; break;
            } 
        }

        for (int i = 0; i <= pre; i++) {
            pmid.push_back(nw[i]);
        }

        for (int i = suf; i < m; i++) {
            smid.push_back(nw[i]);
        }

        // cerr << pmid << ' ' << smid << endl;

        if (pmid.size() > smid.size()) {
            print(pmid, l, r);
        }
        else print(smid, l, r);

    }
    return 0;
}