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

#define MOD 1000000007

int dp[2000005][2];
// int d[2000005][2];

// lli play(lli n, int jump){
//     if (d[n][jump]) return d[n][jump];
//     lli a = (play(n-1, jump) + play(n-2, jump))%MOD;
//     if (jump == 1) a += play(2*n, 0);
//     a %= MOD;
//     return d[n][jump] = a;
// }

int main(){
    int q;
    scanf("%d", &q);
    // d[1][0] = 1; d[1][1] = 3;
    // d[2][0] = 2; d[2][1] = 9;
    dp[1][0] = 1; dp[1][1] = 3;
    dp[2][0] = 2; dp[2][1] = 9;

    for(int i = 3; i <= 2000000; i++){
        dp[i][0] = (dp[i-1][0] + dp[i-2][0])%MOD;
    }

    for(int i = 3; i <= 1000000; i++){
        dp[i][1] = ((dp[i-1][1] + dp[i-2][1])%MOD + dp[2*i][0])%MOD;
    }

    while(q--){
        int n;
        scanf("%d", &n);
        // cerr << play(n, 1) << ' ';
        printf("%d\n", dp[n][1]);
    }
    return 0;
}