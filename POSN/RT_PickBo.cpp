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

int a[2020];
int dp[2020][2020];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);
    // dp[n][k] is book 1 - n of state k
    // dp[n][k] = dp[n-1][k], dp[n-1][k-1]+a[n], dp[n-1][k+2]-a[n];

    for(int i = 1; i <= n; i++){
        for(int  j = 0; j <= i; j++){
            if (j == 0) {
                dp[i][j] = max(dp[i-1][j] ,dp[i-1][j+2]-a[i]);
            }
            else {
                dp[i][j] = max(dp[i-1][j-1]+a[i], dp[i-1][j+2]-a[i]);
            }
            //cerr << i << ' ' << j << ' ' << 0 << ' ' << dp[i-1][j+2]-a[i] << ' ' << dp[i-1][j-1]+a[i] << ' ' << dp[i][j] << endl;
        }
    }
    int ans = -1;
    for(int i = 1; i <= n; i++){
        ans = max(ans, dp[i][0]);
    }
    printf("%d", ans);
    return 0;
}