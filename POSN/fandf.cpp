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

int tab[110][110];
int dp[110][110];

int di[] = {0,0,1,-1}; int dj[]={1,-1,0,0};

int play(int i, int j){
    if (dp[i][j]) return dp[i][j];
    dp[i][j] = 1;
    for(int d = 0; d < 4; d++){
        if (tab[i+di[d]][j+dj[d]] < tab[i][j]){
            dp[i][j] = max(dp[i][j], play(i+di[d], j+dj[d])+1);
        }
    }
    return dp[i][j];
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i <= max(n,m); i++){
        tab[0][i] = tab[i][0] = 2e9;
        tab[n+1][i] = tab[i][m+1] = 2e9;
    }
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            scanf("%d", &tab[i][j]);
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            //cerr << play(i, j) << endl;
            ans = max(ans, play(i, j));
        }
    }
    printf("%d", ans);

    return 0;
}