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

int dp[205][205][205];
int plate[3][220];

#define max(a, b) a > b ? a : b;
#define min(a, b) a < b ? a : b;

lli play (int a, int b, int c, int turn) {
    if (!a && !b && !c) return dp[a][b][c] = 0;
    if (dp[a][b][c] != -1) return dp[a][b][c];
    if (!turn) {
        lli mx = 0;
        if (a) mx = max(mx, plate[0][a] + play(a-1, b, c, 1));
        if (b) mx = max(mx, plate[1][b] + play(a, b-1, c, 1));
        if (c) mx = max(mx, plate[2][c] + play(a, b, c-1, 1));
        return dp[a][b][c] = mx;
    }
    lli mn = 1e15;
    if (a) mn = min(mn,play(a-1, b, c, 0));
    if (b) mn = min(mn,play(a, b-1, c, 0));
    if (c) mn = min(mn,play(a, b, c-1, 0));
    return dp[a][b][c] = mn;
}

int main(){
    int n;
    scanf("%d", &n);
    lli sum = 0;
    memset(dp, -1, sizeof dp);
    for(int j = 0; j < 3; j++){
        for(int i = 1; i <= n; i++){
            scanf("%d", &plate[j][i]);
            sum+=plate[j][i];
        }
    }
    printf("%lld %lld", play(n, n, n, 0), sum-play(n, n, n, 0));
    return 0;
}