#include <bits/stdc++.h>
using namespace std;

int num[50100];
vector<pair<int,int>> g[50100];

int visited[50100][35];

struct A {
    int node, dis, ord;
    bool operator < (const A & o) const {
        return dis > o.dis;
    }
};

priority_queue<A> heap;

int main(){
    int n, m, l, s, e;
    scanf("%d %d %d %d %d", &n, &m, &l, &s, &e);
    for(int i = 1; i <= n; i++){
        scanf("%d", &num[i]);
    }
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a].push_back({b, c});
    }

    heap.push({s, 0, 0});

    while(!heap.empty()){
        auto t = heap.top(); heap.pop();
        if (visited[t.node][t.ord]) continue;
        visited[t.node][t.ord] = 1;

        //cerr << "visited " << t.node << ' ' << t.ord << endl;

        if (t.node == e && t.ord == l) {
            printf("%d", t.dis);
            return 0;
        }

        for(auto x : g[t.node]) {
            if (num[x.first] == t.ord+1) {
                if (visited[x.first][t.ord+1]) continue;
                heap.push({x.first, t.dis+x.second, t.ord+1});
            }
            else {
                if (visited[x.first][t.ord]) continue;
                heap.push({x.first, t.dis+x.second, t.ord});
            }
        }
    }
    printf("-1");
    return 0;
}