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
};

    int n;

vector<A> g[300300];
int dist[300300];

void dfs(int u, int dis){
    dist[u] = dis;
    for(auto x : g[u]){
        dfs(x.node, dis+x.dis);
    }
}

int count(int root = 1) {
    int c = 0;
    int ch = 0;
    for(auto x : g[root]){
        ch = 1;
        c += count(x.node);
    }
    if (!ch && dist[root] <= dist[n] && root != n) return 1;
    return c;
}

int dp[300100];

int dfs2(int node) {
    if (node == n) return dp[node] = -1;
    // cerr << node << endl;
    int ans = 0;
    int ch = 0, chn = 0;
    for(auto x : g[node]){
        ch = 1;
        int d = dfs2(x.node);
        if (d == -1) chn = 1;
        ans += d;
    }
    if (chn) return dp[node] = -1;
    if (!ch && dist[node] <= dist[n]) return dp[node] = 1;
    return dp[node] = ans;
}

int main(){
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        g[b].pb({a,c});
    }
    dfs(1,0);
    int mx = 0;

    // logarr(dist, dist+n);
    dfs2(1);
    for(int i = 1; i <= n; i++){
        // cerr << i << ' ' << dp[i] << endl;
        mx = max(mx, dp[i]);
    }
    // cerr << count() << endl;
    printf("%d", (count()-mx+1)<=0? 1:count()-mx+1);
    return 0;
}