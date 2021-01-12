#include<bits/stdc++.h>
using namespace std;

struct A{
    long long node, dis, state;
    bool operator < (const A & o) const {
        return dis > o.dis;
    }
};

priority_queue<A> heap;

vector<pair<int,int>> g[50100];
long long sun[50100];
long long dis[2][50100];

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    for(int i = 1; i <= n; i++){
        dis[1][i] =  __LONG_LONG_MAX__;
        dis[0][i] =  __LONG_LONG_MAX__;
    }

    for(int i = 0; i < k; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        sun[a] = b;
    }

    heap.push({n, 0, 0});
    while(!heap.empty()){
        auto t = heap.top(); heap.pop();
        for(auto x : g[t.node]) {
            if (dis[t.state][x.first] < t.dis+x.second) continue;
            dis[t.state][x.first] = t.dis+x.second;
            heap.push({x.first, t.dis+x.second, t.state});
            if (sun[x.first] and t.state==0) {
                if (dis[1][x.first] < t.dis+x.second-sun[x.first]) continue;
                dis[1][x.first] = t.dis+x.second-sun[x.first];
                heap.push({x.first, t.dis+x.second-sun[x.first], 1});
            }
        }
    }

    for(int i = 1; i < n; i++){
        printf("%d\n",(dis[1][i]-dis[0][i] > 0)?0:1);
    }

    return 0;
}