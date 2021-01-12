#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

const int N = 10010;

vector<pair<int,int>> g[N];

int dis[20][N];
int par[20][N], dep[N];

void dfs(int u, int p) {
    dep[u] = dep[p]+1;
    par[0][u] = p;
    for(auto v : g[u]) {
        if (v.x == p) {
            dis[0][u] = v.y;
            continue;
        }
        dfs(v.x, u);
    }
}

pair<int,int> lca(int a, int b) {
    int d = 0;
    if (dep[a] < dep[b]) swap(a, b);
    for(int i = 15; i >= 0; i--) {
        if (dep[par[i][a]] >= dep[b]) {
            d += dis[i][a];
            a = par[i][a];
        }
    }
    assert(dep[a] == dep[b]);
    // cerr << "dis at same dep " << d << endl;
    if (a == b) return {d, a};
    for(int i = 15; i >= 0; i--) {
        if (par[i][a] != par[i][b]) {
            d += (dis[i][a]+dis[i][b]);
            a = par[i][a];
            b = par[i][b];
        }
    }
    // cerr << "dis at before merge " << d << endl;
    return {d + dis[0][a] + dis[0][b], par[0][a]};
}

int kth (int a, int b, int k) {
    int l = lca(a, b).y;
    if (dep[a] - dep[l] >= k) {
        // find kth parent of a;
        int p = a;
        for(int i = 0; i <= 15; i++) if ((1<<i)&k) p = par[i][p];
        return p;
    }
    k -= dep[a]-dep[l];
    if (dep[b] - dep[l] >= k) {
        k = dep[b]-dep[l]-k;
        int p = b;
        for(int i = 0; i <= 15; i++) if ((1<<i)&k) p = par[i][p];
        return p;
    }
    return -1;
}

int main(){
    int t;
    char s[10];
    scanf("%d", &t);
    while(t--) {

        int n;
        scanf("%d", &n);
        for(int i = 1; i < n; i++) {
            int a, b, w;
            scanf("%d %d %d", &a, &b, &w);
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }
        dfs(1, 0);

        // for(int i = 1; i <= n; i++)cerr << dis[0][i] << ' ';cerr << endl;
        // for(int i = 1; i <= n; i++)cerr << par[0][i] << ' ';cerr << endl;

        for(int i = 1; i <= 15; i++) {
            for(int j = 1; j <= n; j++) {
                par[i][j] = par[i-1][par[i-1][j]];
                dis[i][j] = dis[i-1][j] + dis[i-1][par[i-1][j]];
            }
        }

        while(1) {
            scanf(" %s", s);
            if (s[1] == 'O') break;
            if (s[1] == 'I') {
                int a, b;
                scanf("%d %d", &a, &b);
                // cerr << "lca " << lca(a, b).y << endl;
                printf("%d\n", lca(a, b).x);
            }
            if (s[1] == 'T') {
                int a, b, k;
                scanf("%d %d %d", &a, &b, &k);
                printf("%d\n", kth(a, b, k-1));
            }
        }

        printf("\n");

        for(int i = 0; i <= n; i++) g[i].clear();
    }


    return 0;
}