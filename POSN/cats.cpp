#include<bits/stdc++.h>
using namespace std;
#define inp(a, b) b a; cin >> a;
#define x first
#define y second
#define pb push_back
#define For(i, start, en) for(auto i = start; i <= en; i++)
#define log(x) cerr << #x << " is " << x << endl;
#define logarr(start, en) cerr << #start << " : "; For(it, start, en) cerr << *it << ' '; cerr << endl;
#define logvec(v) cerr << #v << " : "; for(auto x : v) cerr << x << ' '; cerr << endl;
#define logmat(a, m, n) For(i, 0, m) { For(j, 0, n) cerr << a[i][j] << ' '; cerr << endl; }
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;

struct A {
    int node, dis;
    bool operator < (const A & o) const {
        if (dis != o.dis) return dis > o.dis;
        return node > o.node;
    }
};


vector <A> g[100100];
priority_queue <A> heap;
int visited[100100];
int dis[100100];

int main(){
    int n, m, s, e, mon;
    scanf("%d %d %d %d %d", &n, &m, &s, &e, &mon);
    for(int i = 0; i < m; i++){
        int u, v, w;
        scanf("%d %d %d", &u, &v, &w);
        g[u].pb({v,w});
        g[v].pb({u,w});
    }
    heap.push({e, 0});
    while(!heap.empty()){
        auto t = heap.top(); heap.pop();
        if (dis[t.node]) continue;
        dis[t.node] = t.dis;

        if (t.node == s && t.dis <= mon){
            printf("%d %d %d", e, t.dis, 0);
            return 0;
        }

        for(auto x : g[t.node]){
            if (!dis[x.node]) heap.push({x.node, dis[t.node]+x.dis});
        }
    }

    int dist = 2e9, node, distance = 2e9;


    heap.push({s, 0});
    while(!heap.empty()){
        auto t = heap.top(); heap.pop();
        if (visited[t.node]) continue;
        visited[t.node] = 1;

        if (dis[t.node] < dist){
            dist = dis[t.node];
            node = t.node;
            distance = t.dis;
        }
        if (t.node < node && dis[t.node] == dist){
            node = t.node;
            distance = t.dis;
        }

        for(auto x : g[t.node]){
            if (!visited[x.node] && mon >= t.dis+x.dis) heap.push({x.node, t.dis+x.dis});
        }
    }
    printf("%d %d %d", node, distance, dist);
    return 0;
}