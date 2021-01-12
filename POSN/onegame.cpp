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

int dp[100010];

int main(){

    int ans = 0, ball = 0;
    int n, t;
    scanf("%d %d", &n, &t);
    for(int i = 2; i <= 100000; i++) dp[i] = 2e9;
    for(int i = 0; i < n; i++){
        int num;
        scanf("%d", &num);
        if (dp[num]!=2e9) ans+=dp[num], ball++;
        else {
            dp[num]=1;
            for(int j = 2*num; j <= 100000; j+=num){
                dp[j] = min(dp[j], dp[num]+dp[j/num]);
            }
        }
    }
    printf("%d", ball);
    if (t==2) printf(" %d", ans);
    return 0;
}