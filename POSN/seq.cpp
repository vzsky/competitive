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

lli power (int a, int b){
    if (b == 1) return a;

    lli ans = power(a, b/2)*power(a, b/2);
    ans %= md;
    if (b&1) ans *= a;
    ans %= md;
    return ans;
}

int main(){
    int n, p, k;
    scanf("%d %d %d", &n, &p, &k);
    lli ans = power((p/k),n);
    for(int i = 2*k; i <= p; i+=k){
        cerr << i << endl;
        ans -= power((p/i), n);
        if(ans < 0) ans+=md;
    }
    printf("%lld", ans);
    return 0;
}