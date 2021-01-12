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

#define md 6427

struct A {
    lli a[2][2];
};

A mul (A a, A b){
    A tmp;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            tmp.a[i][j] = 0;
            for(int k = 0; k < 2; k++){
                tmp.a[i][j] += a.a[i][k]*b.a[k][j];
                tmp.a[i][j] %= md;
            }
        }
    }
    return tmp;
}

A m[45], ans;

int main(){
    lli n;
    cin >> n;
    n++;

    m[0] = {1, 1, 1, 0};
    for(int i = 1; i <= 42; i++){
        m[i] = mul(m[i-1], m[i-1]);
    }

    ans = {1, 0, 0, 1};
    for(int i = 0; i <= 42; i++){
        if (n & (1ll<<i)) ans = mul(ans, m[i]);
    }

    printf("%lld", ans.a[1][0]);

    return 0;
}