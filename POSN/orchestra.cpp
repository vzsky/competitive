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

lli b[110];
lli dp[110][510];

lli split (lli n, int k) {
    k++;
    return ((k*(n/k)*((n/k)+1))/2) + (n%k)*((n/k)+1);
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        b[a]++;
    }

    for(int j = 0; j <= k; j++){
        dp[1][j] = split(b[1], j);
    }

    for(int i = 2; i <= m; i++){
        for(int j = 0; j <= k; j++){
            dp[i][j] = 1e18;
            for(int u = 0; u <= j; u++){
                dp[i][j] = min(dp[i][j], dp[i-1][j-u] + split(b[i], u));
            }
        }
    }

    printf("%lld", dp[m][k]);

    return 0;
}