#include<bits/stdc++.h>
using namespace std;

struct Edge {
    int u, v;
} edge[100100];

int order[100100];

int p[100100];
vector<pair<int,int>> g[100100];
int find (int u) {return u==p[u]?p[u]:p[u]=find(p[u]);}
stack<long long> s;
int qx[100100];
map<int,int> at[100100];

void dfs (int u, int p) {
    for (auto x : g[u]) {
        if (x.first == p) continue;
        qx[x.first] = qx[u]^x.second;
        dfs(x.first, u);
    }
}

int main(){
    int n;
    scanf("%d", &n);
    iota(p, p+n+1, 0);
    for(int i = 1; i < n; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].push_back({v, w});
        g[v].push_back({u, w});
        edge[i] = {u, v};
    }
    dfs(1, 0);
    for(int i = 1; i < n; i++) scanf("%d", &order[i]);

    s.push(0);
    long long ans = 0;

    for (int i = 1; i <= n; i++) at[i][qx[i]]=1;

    for (int i = n-1; i > 0; i--) {
        // auto [u, v] = edge[order[i]];
        int u = edge[order[i]].u;
        int v = edge[order[i]].v;
        u = find(u); v = find(v);
        if (at[u].size() > at[v].size()) swap(u, v);
        
        // cerr << u << ' ' << v << endl;
        for (auto x : at[u]) {
            // cerr << x.first << ' ' << x.second << ' ' << at[v][x.first] << endl;
            ans += x.second * at[v][x.first];
            at[v][x.first] += x.second;
        }
        p[u] = v;

        s.push(ans);

    }

    while(!s.empty()) printf("%lld\n", s.top()), s.pop();
    return 0;
}