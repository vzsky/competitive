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
        return dis < o.dis;
    }
};
vector <A> g[2550];
priority_queue <A> heap;
int visited[2550];

int main(){
    int n, m;
    int u, v, w;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &u, &v, &w);
        g[u].pb({v, w});
        g[v].pb({u, w});
    }
    scanf("%d %d %d", &u, &v, &w);

    heap.push({u, 2000000000});
    while(!heap.empty()){
        auto t = heap.top(); heap.pop();

        if (visited[t.node]) continue;
        visited[t.node] = 1;

        if (t.node == v) { 
            int d = t.dis-1;
            printf("%d\n", (int)ceil((double)w/d));
            break;
        }
        for(auto x : g[t.node]){
            if (!visited[x.node])
            heap.push({x.node, min(t.dis, x.dis)});
        }
    }
    return 0;
}