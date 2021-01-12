#include<bits/stdc++.h>
using namespace std;

struct A {
    int node, dis, k;
    bool operator < (const A & o) const {
        return dis > o.dis;
    }
};

vector <A> g[100100];
priority_queue<A> heap;
int visited[100100][10];

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        int u, v, h;
        scanf("%d %d %d", &u, &v, &h);
        int k = 0;
        if (h < -100) k = 1;
        if (h < 0) h = 0;
        g[u].push_back({v, h, k});
    }
    heap.push({1, 0});
    while(!heap.empty()){
        auto t = heap.top(); heap.pop();
        if (visited[t.node][t.k]) continue;
        visited[t.node][t.k] = 1;

        if (t.node == n) {
            printf("%d", t.dis);
            return 0;
        }

        for(auto x : g[t.node]){ 
            if (visited[x.node][t.k+x.k]) continue;
            if (t.k+x.k > k) continue;
            heap.push({x.node, x.dis+t.dis, t.k+x.k});
        }
    }
    printf("-1");
    return 0;
}