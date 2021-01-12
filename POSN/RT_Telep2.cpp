#include<bits/stdc++.h>
using namespace std;

#define pb push_back

struct A {
    int node, dis, used;
    bool operator < (const A & o) const{
        return dis>o.dis;
    }
};
vector<A> g[11000];
int dis[15][11000];
// int visited[15][11000];
priority_queue<A> heap;

int main(){
    int n, m, k, a;
    scanf("%d %d %d %d", &n, &m, &k, &a);
    for(int i = 1; i <= n+k; i++){
        for(int j = 0; j <= 10; j++) dis[j][i] = 2e9;
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a].pb({b, c, 0});
        g[b].pb({a, c, 0});
    }
    for(int i = 1; i <= k; i++){
        int a;
        scanf("%d", &a);
        while(a--){
            int b;
            scanf("%d", &b);
            g[i+n].pb({b, 0, 0});
            g[b].pb({i+n, 0, 1});
        }
    }
    heap.push({1, 0, 0});
    while(!heap.empty()){
        auto t = heap.top(); heap.pop();
        if (t.used > a) continue;
        if (dis[t.used][t.node] < t.dis) continue;
        dis[t.used][t.node] = t.dis;
        // if (visited[t.used][t.node]) continue;
        // visited[t.used][t.node] = 1;

        if (t.node == n) {
            printf("%d", t.dis);
            return 0;
        }

        for(auto x : g[t.node]){
            // if (visited[x.used+t.used][x.node]) continue;
            
            if (t.used+x.used > a) continue;
            if (dis[t.used+x.used][x.node] <= t.dis+x.dis) continue;
            dis[t.used+x.used][x.node] = t.dis+x.dis;
            heap.push({x.node, x.dis+t.dis, t.used+x.used});
        }
    }
    printf("-1");
    return 0;
}