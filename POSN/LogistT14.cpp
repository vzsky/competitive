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
    lli node, cost, fuel, free;
    bool operator < (const A & o) const{
        return cost > o.cost;
    }
};

priority_queue <A> heap;

lli p[110];
vector <A> g[110];
int visited[110][110][3];
//lli dis[110][110][3];
lli mn = 1e18;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%lld", &p[i]);
    }
    int s, d, f, m;
    scanf("%d %d %d %d", &s, &d, &f, &m);
    for(int i = 0; i < m; i++){
        lli a, b, c;
        scanf("%lld %lld %lld", &a, &b, &c);
        g[a].pb({b, 0, c, 0});
        g[b].pb({a, 0, c, 0});
    }

    heap.push({s, 0, 0, 1});
    while(!heap.empty()){
        auto t = heap.top(); heap.pop();

        if (visited[t.node][t.fuel][t.free]) continue;
        visited[t.node][t.fuel][t.free] = 1;
        
        if (t.node == d) {
            if (t.free) mn = min(mn, t.cost);
            //int ans = t.cost + p[t.node]*(f-t.fuel);
            mn = min(mn, t.cost + p[t.node]*(f-t.fuel));
        }

        //cerr << "T " << t.node << ' ' << t.fuel << ' ' << t.cost << endl;

        for(auto x : g[t.node]) {
            if (t.free == 1){
                if (visited[x.node][f][0]) continue;
                heap.push({x.node, t.cost, f-x.fuel, 0});
                //cerr << "push " << x.node << ' ' << t.cost << ' ' << f-x.fuel << endl;
            }
            // car has t.fuel needs x.fuel
            for(int newfuel = 1; newfuel <= f; newfuel ++){
                if (newfuel < t.fuel || newfuel < x.fuel) continue;
                if (visited[x.node][newfuel-x.fuel][t.free]) continue;
                int fuelcost = (newfuel-t.fuel)*p[t.node];
                heap.push({x.node, t.cost+fuelcost, newfuel-x.fuel, t.free});
                //cerr << "push " << x.node << ' ' << t.cost+fuelcost << ' ' << newfuel-x.fuel << endl;
            }
        }
    }
    printf("%lld", mn);
    return 0;
}

/*
4 7 1 8 10 1 4 100 5
1 2 60
1 3 50
1 4 90
2 4 30
3 4 20
*/