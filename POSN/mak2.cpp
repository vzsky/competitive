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

int a[100100];
vector<int> g[100100];
int mic[100100];
int ans[100100];
int visited[100100];

int play(int n){
    if (mic[n]) return mic[n];
    int ans = 0;
    int ch = 0;
    visited[n] = 1;
    for(auto x : g[n]){
        if (visited[x]) continue;
        cerr << "call " << x << endl;
        ans ^= play(x);
        ch = 1;
    }
    if (!ch) { return mic[n] = a[n]; }
    cerr << n << " return " << ans << endl;
    return mic[n] = ans;
}

//! bug in play

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }

    cerr << "dfs" << endl;
    play(1); // select 1 as root node
    logarr(mic, mic+n);

    lli mx = -2e9;
    for(int i = 1; i <= n; i++){
        lli now = mic[1] ^ mic[i];
        for(auto x : g[i]){
            now += mic[x];
        }
        mx = max(mx, now);
    }

    printf("%lld", mx);


    return 0;
}