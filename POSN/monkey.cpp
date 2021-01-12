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

int a[5050];
int dp[5050][5050];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }

    // ith to jth

    for(int j = 1; j <= n; j++){
        int mx = 0;
        for(int i = j-k; i <= j; i++){
            mx = max(mx, a[i]);
            dp[i][j] = max(dp[i-1][j], mx + dp[j-i][j-i]);
        }
    }

    logmat(dp, 8, 8);
    
    return 0;
}