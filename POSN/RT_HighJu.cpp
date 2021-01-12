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

int w[605][605];
int dp[605][605];

int play(int l, int r) {
    if (dp[l][r]) return dp[l][r];
    //cerr << l << r << endl;
    int mn = 2e9;
    for(int i = l+1; i < r; i++){
        mn = min(mn, min(play(l, i), w[i][l])+min(play(i, r), w[r][i]));
    }
    //cerr << l << ' ' << r << ' ' << mn << endl;
    return dp[l][r] = mn;
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= 2*n; i++){
        for(int j = 1; j <= 2*n; j++){
            scanf("%d", &w[i][j]);
        }
    }
    //logmat()
    printf("%d", play(2, 2*n));
    return 0;
}