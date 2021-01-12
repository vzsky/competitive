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

int mod = 500000003;
void Euclid (int a, int b, int *x, int *y){
    if (b == 0) {*x = 1; *y = 0; return;}
    int u, v;
    Euclid(b, a%b, &u, &v);
    *x = v;
    *y = u-v*(a/b);
}
int inv (int a, int field){
    int x, y;
    Euclid(a, field, &x, &y);
    return x%field;
}

int main(){
    int q;
    scanf("%d", &q);
    lli ans = 1;
    while(q--){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        if (a > c || b > d) {
            printf("0\n"); continue;
        }
        int n = d + c - b - a;
        int r = d - b;
        if (n - r > r) r = n-r;
        ans = 1;
        for(int i = r+1; i <= n; i++){
            ans *= i; ans %= mod;
        }
        //cerr << "a " << ans << endl;
        for(int i = 2; i <= n-r; i++){
            int iv;
            iv = inv(i, mod);
            if (iv < 0) iv+=mod;
            ans*=iv;
            ans%=mod;
        }
        printf("%lld\n", ans);

    }
    return 0;
}