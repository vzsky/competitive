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

int sum[5][1010][1010];
int sl[5][1010][1010];
int dp[5][1010][1010];

deque<pii> dq;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);

    for(int m = 1; m <= 3; m++){
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                scanf("%d", &sum[m][i][j]);
                sum[m][i][j]+=sum[m][i][j-1]+sum[m][i-1][j]-sum[m][i-1][j-1];
            }
        }
    }

    for(int m = 1; m <= 3; m++){
        for(int i = k; i <= n; i++){
            while(!dq.empty()) dq.pop_back();
            for(int j = n; j >= k; j--){
                int nw = sum[m][i][j]-sum[m][i-k][j]-sum[m][i][j-k]+sum[m][i-k][j-k];
                //cerr << i << ' ' << j << endl;
                while(!dq.empty() && dq.back().y <= nw) dq.pop_back();
                //cerr << "back" << endl;
                while(!dq.empty() && dq.front().x >= j+k) dq.pop_front();
                //cerr << "front" << endl;
                dq.push_back({j, nw});
                sl[m][i][j] = dq.front().y;
            }
        }
    }

    // logmat(sl[1], 3, 3);
    // logmat(sl[2], 3, 3);
    // logmat(sl[3], 3, 3);

    for(int m = 1; m <= 3; m++){
        for(int j = n; j >= k; j--){
            while(!dq.empty()) dq.pop_back();
            for(int i = n; i >= k; i--){
                int nw = sl[m][i][j];
                while(!dq.empty() && dq.back().y <= nw) dq.pop_back();
                while(!dq.empty() && dq.front().x >= i+k) dq.pop_front();
                dq.push_back({i, nw});
                dp[m][i][j] = dq.front().y;
            }
        }
    }

    // logmat(dp[1], 3, 3);
    // logmat(dp[2], 3, 3);
    // logmat(dp[3], 3, 3);

    int mx = -2e9;
    for(int i = k; i <= n; i++){
        for(int j = k; j <= n; j++){
            mx = max(mx, dp[1][i][j]+dp[2][i][j]+dp[3][i][j]);
        }
    }
    printf("%d", mx);

    return 0;
}