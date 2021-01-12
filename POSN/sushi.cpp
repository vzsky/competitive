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

#define md 1000000007

lli dp[20][100100];
lli arr[100100];
lli seg[400400];

void build (int l, int r, int now) {
    if (l == r) {
        seg[now] = arr[l]; return;
    }
    int mid = (l+r)>>1;
    build(l, mid, 2*now);
    build(mid+1, r, 2*now+1);
    seg[now] = seg[now*2]*seg[now*2+1];
    seg[now]%=md;
}

lli query (int l, int r, int a, int b, int now) {
    if (l > b || r < a) return 1;
    if (l >= a && r <= b) return seg[now];
    int mid = (l+r)>>1;
    lli save = query(l, mid, a, b, now*2) * query(mid+1, r, a, b, now*2+1);
    save %= md;
    return save;
}

int main(){
    lli ans = 0;
    memset(dp, -1, sizeof(dp));
    int n;
    scanf("%d", &n);
    For(i, 1, n){
        scanf("%lld", &arr[i]);
        dp[1][i] = max(dp[1][i-1], arr[i]);
        ans = max(dp[1][i], ans);
    }

    build(1, n, 1);

    for(int i = 2; i <= 16; i++){
        for(int j = (1<<i)-1; j <= n; j++){
            lli now = query(1,n,j-(1<<(i-1))+1, j, 1);
            //cerr << "qry ret " << now << endl;
            now += dp[i-1][j-(1<<(i-1))];
            //cerr << i << ' ' << j << ' ' << now << endl;
            dp[i][j] = max(now, dp[i][j-1]);
        }
        ans = max(ans, dp[i][n]);
    }
    
    printf("%lld", ans);

    return 0;
}