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

vi pfs;

int pf (int n){
    int rt = sqrt(n);
    int sum = 0;
    int ch = 0; // prime
    for(int i = 2; i <= rt; i++){
        if (n%i==0){
            sum+=i;
            pfs.pb(i);
            ch = 1;
        }
        while (n%i==0){
            n/=i;
        }
        if (n == 1) break;
    }
    //cerr << sum << endl;
    if (!ch) { pfs.pb(n); return n;}
    if (n!=1) sum+=pf(n);
    return sum;
}

int dp[500100];

int main(){
    int t, n;

    dp[1] = dp[2] = 2;
    dp[0] = 1;

    for(int i = 3; i < 5000001; i++){

        pfs.clear();

        int sum = pf(i);
        //cerr << i << ' ' << sum << endl;
        for(auto a : pfs){
            //cerr << "dp " << dp[sum-a]  << endl;
            if (dp[sum-a] == 2){
                dp[i] = 1; goto endloop;
            }
        }
        dp[i] = 2;
        endloop: continue;
    }

    // logarr(dp, dp+10);

    scanf("%d", &t);
    for(int i = 0; i < t; i++){
        scanf("%d", &n);
        printf("%d\n", dp[n]);
    }
    return 0;
}