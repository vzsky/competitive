#include<bits/stdc++.h>
using namespace std;
#define inp(a, b) b a; cin >> a;
#define x first
#define y second
#define pb push_back
#define For(i, start, en) for(auto i = start; i <= en; i++)
#define logarr(start, en) cerr << #start << " : "; For(it, start, en) cerr << *it << ' '; cerr << endl;
#define logvec(v) cerr << #v << " : "; for(auto x : v) cerr << x << ' '; cerr << endl;
#define logmat(a, m, n) For(i, 0, m) { For(j, 0, n) cerr << a[i][j] << ' '; cerr << endl; }
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;

lli lev[55];

int mxlvl;

int level (lli a){
    return lower_bound(lev, lev+mxlvl+1, a)-lev;
}

int main(){
    lli n;
    int k, q;
    scanf("%lld %d %d", &n, &k, &q);

    lev[0] = 1;
    for(int i = 1; i <= 50; i++){
        lev[i] = lev[i-1]*k;
        if (lev[i] > n) {mxlvl = i; break;}
    }
    for(int i = 1; i <= 50; i++){
        lev[i] += lev[i-1];
    }

    while(q--){

        lli a, b;
        scanf("%lld %lld", &a, &b);

        if (k == 1) {
            printf("%lld\n", abs(a-b));
            continue;
        }

        int dis = 0;

        while (level(a) > level(b)){
            dis++;
            a+=(k-2);
            a/=k;
        }
        while (level(a) < level(b)){
            dis++;
            b+=(k-2);
            b/=k;
        }
        while (a!=b){
            dis+=2;
            a+=(k-2);
            a/=k;
            b+=(k-2);
            b/=k;
        }
        printf("%d\n", dis);
    }
    return 0;
}