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

struct edge {
    long long node, dis;
    bool operator < (const edge & o) const {
        return dis > o.dis;
    }
};

long long dis[2][10100];
priority_queue <edge> heap;
vector <edge> g[10100];

int main(){
    int v, e, s, t;
    scanf("%d %d %d %d", &v, &e, &s, &t);
    for(int i = 0; i <= v; i++){
        dis[0][i] = dis[1][i] = 2e9;
    }
    dis[0][s] = 0;
    for(int i = 0; i < e; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[a].pb({b, c});
    }
    heap.push({s, 0});
    while(!heap.empty()){
        auto tp = heap.top();
        heap.pop();

        //if (tp.node == t) break;

        for (auto x : g[tp.node]){
            if (tp.dis + x.dis < dis[0][x.node]){
                dis[1][x.node] = dis[0][x.node];
                dis[0][x.node] = tp.dis + x.dis;
                heap.push({x.node, dis[0][x.node]});
            }
            else if (tp.dis + x.dis < dis[1][x.node]){
                dis[1][x.node] = tp.dis + x.dis;
                heap.push({x.node, dis[1][x.node]});
            }
        }
    }
    printf("%lld", dis[1][t]);
    return 0;
}