#include<bits/stdc++.h>
using namespace std;

struct A {
    int u, v, w;
    bool operator < (const A & o) const {
        return w < o.w;
    }
};

int dp[17][20100], mx[17][20100], lev[20100];

vector<A> e, mst, nmst, g[20100];

void dfs(int root = 0, int p = 0, int wei = 0, int l = 1){
    dp[0][root] = p;
    mx[0][root] = wei;
    lev[root] = l;
    for(auto x : g[root]) {
        if (x.u == p) continue;
        dfs(x.u, root, x.w, l+1);
    }
}

int lca (int u, int v) {
    int ans = -2e9;
    if (lev[v] > lev[u]) swap(u, v);
    for(int i = 15; i >= 0; i--){
        if (lev[dp[i][u]] >= lev[v]) {
            ans = max(ans, mx[i][u]);
            u = dp[i][u];
        }
    }
    assert(lev[u] == lev[v]);
    if (v == u) return ans;
    for(int i = 15; i >= 0; i--){
        if (dp[i][u] != dp[i][v]) {
            ans = max(ans, max(mx[i][u], mx[i][v]));
            u = dp[i][u];
            v = dp[i][v];
        }
    }
    ans = max(ans, max(mx[0][u], mx[0][v]));
    return ans;
}

int p[20100];
int f(int u) {
    return (u==p[u])?u:p[u] = f(p[u]);
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        e.push_back({a, b, c});
    }
    sort(e.begin(), e.end());

    for(int i = 0; i <= n; i++) p[i] = i;
    for(auto x : e){
        if (f(x.u) != f(x.v)) {
            mst.push_back(x);
            p[f(x.u)] = p[f(x.v)];
            g[x.u].push_back({x.v, 0, x.w});
            g[x.v].push_back({x.u, 0, x.w});
        }
        else {
            nmst.push_back(x);
        }
    }
    dfs();
    for(int i = 1; i < 16; i++){
        for(int j = 0; j < n; j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
            mx[i][j] = max(mx[i-1][j], mx[i-1][dp[i-1][j]]);
        }
    }

    int ans = 2e9;
    for(auto x : nmst){
        ans = min(x.w-lca(x.u, x.v), ans);
    }
    printf("%d", ans+1);

    return 0;
}