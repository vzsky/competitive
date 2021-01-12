#include<bits/stdc++.h>
using namespace std;

map<pair<int,int>, vector<int>> s, e;

struct Q { int u, v, merged; };
struct SDSU { int u, v, hu, hv; };
struct DSU {
    int time; 
    int comps;
    vector<Q> que[4*300100];
    int p[300100], ans[300100], h[300100];
    stack<SDSU> s;
    int find (int u) { return u==p[u]?u:find(p[u]); }
    void build () { for (int i = 1; i <= comps; i++) p[i] = i; }
    bool merge (int u, int v) {
        u = find(u); v = find(v);
        if (u == v) return false;
        if (h[u] < h[v]) swap(u, v); // h[u] >= h[v]
        comps--;
        // cerr << "merge " << u << ' ' << v << ' ' << comps << endl;
        s.push({u, v, h[u], h[v]});
        p[v] = u;
        if (h[v] == h[u]) h[u]++;
        return true;
    }
    void rollback() {
        assert(!s.empty());
        auto x = s.top(); 
        s.pop();
        comps++;
        p[x.u] = x.u;
        p[x.v] = x.v;
        h[x.u] = x.hu;
        h[x.v] = x.hv;
        // cerr << "rollback " << comps << endl;
    }
    void add (int a, int b, Q query, int now, int l, int r) {
        if (r < a or b < l) return;
        if (a <= l and r <= b) return void(que[now].push_back(query));
        int mid = (l+r)/2;
        add(a, b, query, now*2, l, mid); add(a, b, query, now*2+1, mid+1, r);
    }
    void add (int a, int b, int u, int v) { add(a, b, {u, v, 0}, 1, 1, time); }
    void solve (int now, int l, int r) {
        for (auto &q : que[now]) q.merged = merge(q.u, q.v); 
        if (l == r) ans[l] = comps;
        if (l != r) {
            int mid = (l+r)/2;
            solve(now*2, l, mid); solve(now*2+1, mid+1, r);
        }
        for (auto q : que[now]) if(q.merged) rollback();
    }
    void solve () { solve(1,1,time); }
} dsu;

vector<pair<int,int>> keep;

int main(){

    freopen("connect.in", "r", stdin);
    freopen("connect.out", "w", stdout);

    int n, k;
    scanf("%d %d", &n, &k);
    dsu.time = 1;
    dsu.comps = n;
    dsu.build();
    for (int i = 0; i < k; i++) {
        char op; scanf(" %c", &op);
        if (op == '?') { dsu.time++; continue; }
        int u, v;
        scanf("%d %d", &u, &v); 
        if (u < v) swap(u, v);
        keep.push_back({u, v});
        if (op == '+') s[{u, v}].push_back(dsu.time);
        else e[{u, v}].push_back(dsu.time);
    }
    for (auto x : keep) {
        e[x].push_back(dsu.time+1);
        for (int i = 0; i < s[x].size(); i++) {
            // cerr << s[x][i] << ' ' << e[x][i]-1 << ' ' << x.first << ' ' << x.second << endl;
            dsu.add(s[x][i], e[x][i]-1, x.first, x.second);
        }
    }
    // cerr << "added " << dsu.time << endl;
    dsu.solve();
    for (int i = 1; i < dsu.time; i++) {
        printf("%d\n", dsu.ans[i]);
    }
}