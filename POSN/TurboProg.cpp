#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define For(a,b) for(int a = 0; a < b; a++)
#define _cerrheader(a) cerr << #a << " : "
#define log(a) _cerrheader(a) << a
#define logarr(a, b) { _cerrheader(a); For(i, b) cerr << a[i];}
#define logvec(v) { _cerrheader(a); for(auto i : v) cerr << v[i];}
#define logmat(a,b,c) For(i,b) { For(j,c) cerr << a[i][j] << ' '; } cerr << endl
typedef pair<int,int> pii;
typedef long long lli;
typedef vector<int> vi;

struct A { 
    int x, y;
    bool operator < (const A & o) const {
        return y > o.y;
    }
};

vector<A> g[1010];
priority_queue <A> heap;
int dist[1010];

int main(){

    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i < m; i++){
        int s, e, w;
        scanf("%d %d %d", &s, &e, &w);
        g[s].pb({e, w});
    }

    for(int i = 0; i <= n; i++){
        dist[i] = 2e9;
    }
    dist[1] = 0;

    heap.push({1, 0});
    while(!heap.empty()){ 
            auto t = heap.top();
            heap.pop();
            dist[t.x] = min(dist[t.x],t.y);
            for(auto n : g[t.x]) {
                if (dist[n.x] == 2e9) heap.push({n.x, n.y+dist[t.x]});
            }
        }

    while(q--){
        int node;
        scanf("%d", &node);
        printf("%d\n", dist[node]==2e9?-1:dist[node]);
    }
    return 0;
}