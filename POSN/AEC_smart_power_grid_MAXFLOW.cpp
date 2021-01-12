#include<bits/stdc++.h>
using namespace std;

int g[110][110], p[110];
int mx, n, m, s, t, flow;

bool path () {
    queue<int> bfs;
    bfs.push(s);
    memset(p, 0, sizeof p);
    while(!bfs.empty()) {
        auto now = bfs.front(); bfs.pop();
        if (now == t) return true;
        for (int i = 1; i <= n; i++) if (g[now][i] > 0 and p[i] == 0) bfs.push(i), p[i] = now;
    }
    return false;
}

int relax (int u, int flow) {
    if (u == s) return flow;
    flow = relax(p[u], min(flow, g[p[u]][u]));
    g[p[u]][u] -= flow;
    g[u][p[u]] += flow;
    return flow;
}

int main(){
    scanf("%d %d %d %d", &n, &m, &s, &t);
    for (int i = 0; i < m; i++) {
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u][v] = w;
    }
    while(path())  flow += relax(t, 1e9);  
    printf("%d", flow);
    return 0;
}