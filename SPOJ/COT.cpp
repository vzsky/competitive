#include<bits/stdc++.h>
using namespace std;

typedef int node;
const int N = 120000;

int n, q;
int w[N], root[N], dep[N], par[25][N], s[N];
unordered_map<int,int> m;
vector<node> g[N];

struct A {
    int val, l, r;
} seg[60*N]; // 2NlogN

int tot = 0;
int clone (int n) {seg[++tot] = seg[n]; return tot;}
int lv = 0;

int update(int ind, int amn, int now, int l = 1, int r = n) {
    if (l > ind or r < ind) return now;
    if (l == r) {
        int nn = clone(now);
        seg[nn].val += amn;
        return nn;
    }
    int mid = (l+r)/2;
    int nn = clone(now);
    seg[nn].l = update(ind, amn, seg[now].l, l, mid);
    seg[nn].r = update(ind, amn, seg[now].r, mid+1, r);
    seg[nn].val = seg[seg[nn].l].val + seg[seg[nn].r].val;
    return nn;
}

int query(int b, int now, int a = 1, int l = 1, int r = n) {
    if (l > b or r < a) return 0;
    if (l >= a and r <= b) return seg[now].val;
    int mid = (l+r)/2;
    return query(b, seg[now].l, a, l, mid) + query(b, seg[now].r, a, mid+1, r);
}

void dfs(node u = 1, node p = 0) {
    par[0][u] = p;
    dep[u] = dep[p]+1;

    root[u] = update(m[w[u]], 1, root[p]);

    for (node x : g[u]) {
        if (x == p) continue;
        dfs(x, u);
    }
}

node lca (node u, node v) {
    if (dep[u] < dep[v]) swap(u, v);
    assert(dep[u] >= dep[v]);
    for(int i = 19; i >= 0; i--) {
        if (dep[par[i][u]] >= dep[v]) u = par[i][u];
    }
    assert(dep[u] == dep[v]);
    if (u == v) return u;
    for(int i = 19; i >= 0; i--) {
        if (par[i][u] != par[i][v]) {
            u = par[i][u];
            v = par[i][v];
        }
    }
    assert(par[0][u] == par[0][v]);
    return par[0][u];
}

int main(){
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++) {
        scanf("%d", &w[i]);
        s[i] = w[i];
    }
    for(int i = 2; i <= n; i++) {
        node a, b;
        scanf("%d %d", &a, &b);
        g[a].push_back(b);
        g[b].push_back(a);
    }
    sort(s+1, s+n+1);
    for(int i = 1; i <= n; i++) {
        m[s[i]] = i;
    }

    dfs(); // dfs for lca and build pers seg tree

    for(int i = 1; i < 20; i++) {
        for(int j = 1; j <= n; j++) {
            par[i][j] = par[i-1][par[i-1][j]];
        }
    }

    while(q--) {
        node u, v; int k;
        scanf("%d %d %d", &u, &v, &k);
        int l = 1, r = n;
        int lc = lca(u, v);
        while(l < r) {
            int mid = (l+r)/2;
            int f = query(mid, root[u]) + query(mid, root[v]) - query(mid, root[lc]) - query(mid, root[par[0][lc]]); // how many less than mid
            if (f >= k) r = mid;
            else        l = mid+1;
        }
        printf("%d\n", s[l]);
    }

    return 0;
}