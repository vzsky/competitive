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

vi g[100100];
int dp[25][100100], lv[100100], in[100100];

void dfs(int node, int p, int state){
    dp[0][node] = p;
    lv[node] = state;
    for(auto x : g[node]){
        dfs(x, node, state+1);
    }
}

int lca(int a, int b){
    if (lv[a] < lv[b]) swap(a, b); // a is below b
    for(int i = 20; i >= 0; i--){
        if (lv[dp[i][a]] >= lv[b]) a = dp[i][a];
    }
    if (a==b) return a;

    for(int i = 20; i >= 0; i--){
        if (dp[i][a] != dp[i][b]) {
            a = dp[i][a]; b = dp[i][b];
        }
    }
    return dp[0][a];
}

int main(){
    int n, q, u, v;
    scanf("%d", &n);
    for(int i = 0; i < n-1; i++){
        scanf("%d %d", &u, &v);
        g[u].pb(v);
        in[v]++;
    }
    for(int i = 1; i <= n; i++){
        if(!in[i]) {
            dfs(i, 0, 1);
            break;
        }
    }
    dp[0][0] = 0;
    for(int i = 1; i <= 20; i++){
        for(int j = 1; j <= n; j++){
            dp[i][j] = dp[i-1][dp[i-1][j]];
        }
    }
    scanf("%d", &q);
    while(q--){
        scanf("%d %d", &u, &v);
        printf("%d\n", lca(u, v));
    }
    return 0;
}

/*
13 1 2 1 3 2 9 2 6 2 8 6 10 6 5 3 7 7 11 7 13 13 4 13 12 5 10 5 11 12 9 7 10 8 9 8
*/