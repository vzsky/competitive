// Not optimal but pass full score
#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[80100];
int room[80100];

struct A {
    long long node, dis, speed, last;
    bool operator < (const A & o) const {
        if (dis == o.dis ) return speed < o.speed;
        return dis > o.dis;
    }
};

priority_queue<A> heap;
int visited[80100][15];
long long dis[80100][15];

int main(){
    int n, m, l, q;
    scanf("%d %d %d %d", &n, &m, &l, &q);
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a].push_back({b, c});
    }
    for(int i = 0; i < l; i++){
        int a;
        scanf("%d", &a);
        room[a] = 1;
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0 ; j <= q; j++){
            dis[i][j] = 1e18;
        }
    }

    heap.push({1, 0, 0, 0});
    dis[1][0] = 0;

    while(!heap.empty()){
        auto t = heap.top(); heap.pop();
        if (visited[t.node][t.speed]) continue;
        visited[t.node][t.speed] = 1;

        if (t.node == n) {
            printf("%lld", t.dis);
            return 0;
        }

        for(auto x : g[t.node]) {
            if (room[t.node] && t.speed+1 <= q && t.last != t.node) {
                long long newdis = t.dis + x.second/(1<<(t.speed+1));
                if (dis[x.first][t.speed+1] < newdis) continue;
                dis[x.first][t.speed+1] = newdis;
                heap.push({x.first, newdis, t.speed+1, t.node});
                //cerr << "push " << x.first << " potion" << endl;
            }
            long long newdis = t.dis + x.second/(1<<(t.speed));
            if (dis[x.first][t.speed] < newdis) continue;
            dis[x.first][t.speed] = newdis;
            heap.push({x.first, newdis, t.speed, t.last});
            //cerr << "push " << x.first << endl;
        }
    }
    return 0;
}