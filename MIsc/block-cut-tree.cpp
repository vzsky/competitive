#include<bits/stdc++.h>
using namespace std;

int ind[100100], ll[100100], cut[100100];
stack<int> s;
vector<vector<int>> comps;
vector<pair<int,int>> bridge;

struct graph {
    int n = 0;
    int id[100100];
    vector<vector<int>> adj;
    graph() {n = 0; memset(id, 0, sizeof id); adj.push_back({});}
    void add_node (int u) { adj.push_back({}), id[u]=++n; }
    void add_edge (int u, int v) { adj[id[u]].push_back(id[v]); adj[id[v]].push_back(id[u]);}
    void auto_edge (int u, int v) { if (!id[u]) add_node(u); if (!id[v]) add_node(v); add_edge(u, v);}
    vector<int>& operator[](int u) { return adj[id[u]]; }
} g, bct, bt;

int cnt = 1;
void tarjan(int u, int p = -1) {
    ind[u] = ll[u] = cnt++; s.push(u);
    int child = 0;
    for (auto x : g[u]) {
        child++;
        if (x == p) continue;
        if (!ind[x]) {
            tarjan(x, u);
            ll[u] = min(ll[u], ll[x]);
            if ((ll[x] >= ind[u] and p != -1) or (p == -1 and child > 1)) cut[u] = 1;
            if (ll[x] > ind[u]) bridge.push_back({u, x});
            if (ll[x] >= ind[u]) {
                comps.push_back({}); comps.back().push_back(u);
                while(comps.back().back() != x) comps.back().push_back(s.top()), s.pop();
            }
        }
        else if (x != p) {
            ll[u] = min(ll[u], ind[x]);
        }
    }
}

int main(){
    int n, m;
    scanf("%d %d" , &n, &m);
    for (int i = 0; i < m; i++) { int a, b; scanf("%d %d", &a, &b); g.auto_edge(a, b); }
    tarjan(1);

    cerr << "comps" << endl;
    for (auto comp : comps ) {
        for (auto node : comp) cerr << node << ' '; cerr << endl;
    }
    cerr << "bridge" << endl;
    for (auto b : bridge) cerr << b.first << ' ' << b.second << endl;
    cerr << "cut" << endl;
    for (int i = 1; i <= n; i++) if (cut[i]) cerr << i << ' ';
    cerr << endl;

    // build bct
    for (int i = 1; i <= n; i++) if (cut[i]) bct.add_node(i);
    for (auto comp : comps) {
        for (auto ele : comp) {
            if (cut[ele]) continue;
            bct.add_node(0); break;
        }
        for (auto ele : comp) {
            if (!cut[ele]) bct.id[ele] = bct.id[0];
            else bct.add_edge(ele, 0);
        }
    }

    // build bt
    for (auto comp : comps) {
        bt.add_node(0);
        for (auto ele : comp) bt.id[ele] = bt.id[0];
    }
    for (auto edge : bridge) {
        bt.add_edge(edge.first, edge.second);
    }

    cerr << "bt size " << bt.n << endl;
    cerr << "bct size " << bct.n << endl;

    return 0;
}