#include <bits/stdc++.h>
#include "messy.h"
using namespace std;

vector<int> p;
int n;
void solve (int l, int r, vector<int>& v) {

    if (l == r) { p[v[0]] = l; return; }

    // cerr << l << ' ' << r << " : ";
    // for (int x : v) cerr << x << ' ';
    // cerr << endl;

    string s(n, '1');
    vector<int> first, last;
    for (auto x : v) s[x] = '0';
    for (auto x : v) {
        s[x] = '1';
        // cerr << "checking " << s << ' ' << check_element(s) << endl;
        if (check_element(s)) first.push_back(x);
        else last.push_back(x);
        s[x] = '0';
    }
    int mid = (l+r)/2;
    solve(l, mid, first);
    solve(mid+1, r, last);
}

void add (int l, int r) {
    string s(n, '1');
    for (int i = l; i <= r; i++) s[i] = '0';
    for (int i = l; i <= (r+l)/2; i++) {
        s[i] = '1';
        // cerr << s << endl;
        add_element(s);
        s[i] = '0';
    } 
}
void add_all (int l, int r) {
    if (l == r) return;
    add(l, r);
    int mid = (l+r)/2;
    add_all(l, mid);
    add_all(mid+1, r);
}

vector<int> restore_permutation(int N, int w, int r) {
    n = N;
    p.resize(n);
    add_all(0, n-1);
    vector<int> v;
    // cerr << "added" << endl;
    for (int i = 0; i < n; i++) v.push_back(i);
    compile_set();
    solve(0, n-1, v);
    return p;
}
