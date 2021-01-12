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

int n, m;
int ans = 0;

vi g[10];
int visited[10];

void play(int i, int cnt){
    if (cnt == n) ans++;
    for(int x : g[i]){
        if (visited[x]) continue;
        visited[x] = 1;
        play(x, cnt+1);
        visited[x] = 0;
    }
}

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b);
        g[b].pb(a);
    }
    visited[1] = 1;
    play(1, 1);
    printf("%d", ans); 
    return 0;
}