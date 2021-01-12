#include<bits/stdc++.h>
using namespace std;

struct A {
    int u, v, w;
} ans;
vector<A> edge, mst;

struct B {
    int u, w;
    bool operator < (const B & o) const {
        return w > o.w;
    }
};
priority_queue<B> heap;
vector<B> graph[3010];

int p[3010];
int find(int u) {return p[u]==u? u:p[u]=find(p[u]);}
int g[3010][3010];
int f[3010][3010];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if (i == j) continue;
            scanf("%d", &f[i][j]);
            if (i < j) edge.push_back({i, j, f[i][j]});
        }
    }
    for(int i = 1; i <= n; i++) for(int j = 1; j <= n; j++) g[i][j] = -1;
    sort(edge.begin(), edge.end(), [](const A & a, const A & b){return a.w < b.w;});
    iota(p, p+n+1, 0);
    for(auto x : edge) {
        if (find(x.u) == find(x.v)) continue;
        p[find(x.u)] = find(x.v);
        mst.push_back(x);
        graph[x.u].push_back({x.v, x.w});
        graph[x.v].push_back({x.u, x.w});
        // g[x.u][x.v] = g[x.v][x.u] = x.w;
    }



    for(int i = 1; i <= n; i++) {
        heap.push({i, 0});
        while(!heap.empty()) {
            auto t = heap.top(); heap.pop();
            if (g[i][t.u] != -1) continue;
            g[i][t.u] = t.w;
            for (auto x : graph[t.u]) {
                if (g[i][x.u] != -1) continue;
                heap.push({x.u, t.w+x.w});
            }
        }
    }
        

    ans = {-1, -1, (int)1e9};
    for(int i = 1; i <= n; i++) {
        for(int  j = 1; j <= n; j++) {
            if (f[i][j] != g[i][j]) {
                assert(g[i][j] > f[i][j]);
                if (ans.w > f[i][j]) ans = {i, j, f[i][j]};
            }
        }
    }

    mst.push_back(ans);
    for(auto x : mst) if (x.u > x.v) swap(x.u, x.v);
    sort(mst.begin(), mst.end(), [](const A & a, const A & b) {if (a.u==b.u) return a.v < b.v; return a.u < b.u;});
    for(auto x : mst) printf("%d %d %d\n", x.u, x.v, x.w);
    return 0;
}