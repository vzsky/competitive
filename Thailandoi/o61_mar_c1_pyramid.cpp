#include<bits/stdc++.h>
using namespace std;

struct A {
    int t, p, del, sum;
} py[100100];
int ans[100100];

auto inc = [](A&a, A&b) {return a.p < b.p;};
auto decr = [](A&a, A&b) {return a.p > b.p;}; 
auto byt = [](A&a, A&b) {return a.t < b.t;};

int fw[10100];
stack<int> h;

void add(int pos, int v = 1) {
    h.push(pos);
    for (int i = pos; i > 0; i-=(i&-i)) fw[i] += v;
}

int query (int pos, int v = 0) {
    for (int i = pos; i < 10000; i+=(i&-i)) v += fw[i];
    return v;
}

void clear () {
    while (!h.empty()) {
        add(h.top(), -1); h.pop(); h.pop();
    }
}

void CDQ1 (int l, int r) {
    if (l >= r) return;
    int m = (l+r)/2;
    CDQ1(l, m); CDQ1(m+1, r);
    clear();
    sort(py+l, py+m+1, decr); sort(py+m+1, py+r+1, decr);
    int i = l, j = m+1;
    // cerr << l << ' ' << r << endl;
    while (i <= m and j <= r) {
        if (py[i].p >= py[j].p) {
            // cerr << "add " << py[i].del << endl;
            add(py[i].del); i++;
        }
        else {
            // cerr << py[j].t << " query " << py[j].del << ' ' << query(py[j].del) << endl;
            ans[py[j].t] += query(py[j].del); j++;
        }
    }
    while (j <= r) { 
        // cerr << py[j].t << " query " << py[j].del << ' ' << query(py[j].del) << endl;
        ans[py[j].t] += query(py[j].del); j++; 
    }
}

void CDQ2 (int l, int r) {
    if (l >= r) return;
    int m = (l+r)/2;
    CDQ2(l, m); CDQ2(m+1, r);
    clear();
    sort(py+l, py+m+1, inc); sort(py+m+1, py+r+1, inc);
    int i = l, j = m+1;
    // cerr << l << ' ' << r << endl;
    while (i <= m and j <= r) {
        if (py[i].p < py[j].p) {
            // cerr << py[i].p << " add " << py[i].sum << endl;
            add(py[i].sum); i++;
        }
        else {
            // cerr << py[j].p << ' ' << py[j].t << " query " << py[j].sum << ' ' << query(py[j].sum) << endl;
            ans[py[j].t] += query(py[j].sum); j++;
        }
    }
    while (j <= r) { 
        // cerr << py[j].p << ' ' << py[j].t << " query " << py[j].sum << ' ' << query(py[j].sum) << endl;
        ans[py[j].t] += query(py[j].sum); j++;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        int p, h; cin >> p >> h;
        py[i] = {i, p+1, h-p+5005, h+p};
    }
    CDQ1(0, n-1);
    sort(py, py+n, byt);
    CDQ2(0, n-1);
    for (int i = 0; i < n; i++) {
        cout << ans[i] << '\n';
    }
    return 0;
}