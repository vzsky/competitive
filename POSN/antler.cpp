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

#define MAX 2000000

lli cnt[2000200];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a;
        scanf("%d", &a);
        cnt[a]++;
    }

    lli sum;
    lli ans = 0;
    for(int k = 1; k <= MAX; k++){
        sum = 0;
        for(int i = k; i <= MAX; i+=k){
            sum+=cnt[i];
        }
        if (sum >= 2) ans = max(ans, sum*k); 
    }
    printf("%lld", ans);

    return 0;
}