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

map<lli, int> pos;

#define MOD 99877

lli qs[100100];
lli sum[100100];

int main(){
    int n, t, q;
    scanf("%d %d %d", &n, &t, &q);
    for(int i = 1; i <= n; i++){
        lli a;
        scanf("%lld", &a);
        pos[a] = i;
    }
    for(int i = 1; i <= t; i++){
        lli a, b; int c;
        scanf("%lld %lld %d", &a, &b, &c);
        // for(int j = pos[a]; j <= pos[b]; j++){
        //     qs[j]+=c;
        //     qs[j]%=MOD;
        // }
        qs[pos[a]]+=c;
        qs[pos[b]+1]-=c;
    }
    for(int i = 1; i <= n; i++){
        qs[i] += qs[i-1];
    }
    for(int j = 1; j <= n; j++){
        sum[j] = sum[j-1]+qs[j];
    }
    for(int i = 1; i <= q; i++){
        lli a, b;
        scanf("%lld %lld", &a, &b);
        //sum = qs[pos[b]]-qs[pos[a]-1];
        printf("%lld\n", (sum[pos[b]]-sum[pos[a]-1])%MOD);
    }
    return 0;
}