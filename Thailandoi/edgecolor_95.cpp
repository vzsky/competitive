#include<bits/stdc++.h>
using namespace std;

struct Q {int u, v;};
struct S {int u, hu, su, v, hv, sv, c;};
struct DSU {
    int time, comps;
    bool cond = true;
    int p[300100], h[300100], sz[300100];
    bool ans[600100];
    vector<Q> que[2400100];
    stack<S> s;

    int find (int u) {return u==p[u]?u:find(p[u]);}
    void merge (int u, int v) {
        // cerr << "from " << u << ' ' << v << ' ';
        u = find(u); v = find(v);
        if (u == v) {
            s.push({u, h[u], sz[u], v, h[v], sz[v], cond});
            // cerr << "tryna merge " << u << ' ' << sz[u] << endl;
            if (sz[u] & 1) cond = false;
            return;
        }
        // cerr << "merged" << endl;
        if (h[u] > h[v]) swap(u, v); 
        s.push({u, h[u], sz[u], v, h[v], sz[v], cond});
        sz[v] += sz[u];
        p[u] = v;
        if (h[u] == h[v]) h[v]++;
    }
    void rollback() {
        auto x = s.top(); s.pop();
        p[x.u] = x.u; h[x.u] = x.hu; sz[x.u] = x.su;
        p[x.v] = x.v; h[x.v] = x.hv; sz[x.v] = x.sv;
        cond = x.c;
        // cerr << "rollbacked" << endl;
    }

    void build() { for(int i = 1; i <= comps; i++) p[i] = i, sz[i] = 1; }
    void add (int a, int b, Q q, int now, int l, int r) {
        if (r < a or b < l) return;
        if (a <= l and r <= b) return void(que[now].push_back(q));
        int mid = (l+r)/2;
        add(a, b, q, now*2, l, mid); add(a, b, q, now*2+1, mid+1, r);
    }
    void add (int l, int r, int u, int v) { add(l, r, {u, v}, 1, 1, time); }
    void solve (int now, int l, int r) {
        for (auto q : que[now]) merge(q.u, q.v);
        if (l == r) ans[l] = cond;
        else {
            int mid = (l+r)/2;
            solve(now*2, l, mid); solve(now*2+1, mid+1, r);
        }
        for (auto q : que[now]) rollback();
    }
    void solve () { solve(1, 1, time); }

} dsu;

set<pair<int,int>> keep;
map<pair<int,int>, vector<int>> s, e;
int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for (int i = 1; i <= m; i++) {
        int t, u, v;
        scanf("%d %d %d", &t, &u, &v);
        if (u < v) swap(u, v);
        keep.insert({u, v});
        if (t == 1) s[{u, v}].push_back(i);
        else e[{u, v}].push_back(i);
    }
    dsu.time = m;
    dsu.comps = n;
    dsu.build();
    for (auto x : keep) {
        e[x].push_back(m+1);
        for (int i = 0; i < s[x].size(); i++) {
            dsu.add(s[x][i], e[x][i]-1, x.first, x.second);
            // cerr << s[x][i] << ' ' << e[x][i]-1 << ' ' <<  x.first << ' ' <<  x.second << endl;
        }
    }
    dsu.solve();
    for (int i = 1; i <= m; i++) {
        printf(dsu.ans[i]?"yes\n":"no\n");
    }
    return 0;
}