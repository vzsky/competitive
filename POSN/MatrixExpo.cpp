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

lli n, md;

struct A {
    lli mat[6][6];
};

A mul (A a, A b){
    A tmp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tmp.mat[i][j] = 0;
            for(int k = 0; k < n; k++){
                tmp.mat[i][j] += a.mat[i][k]*b.mat[k][j];
                tmp.mat[i][j]%=md;
            }
        }
    }
    return tmp;
}

A m[65], ans;

int main(){
    lli p;
    scanf("%lld", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lld", &m[0].mat[i][j]);
        }
    }
    scanf("%lld %lld", &p, &md);

    for(int i = 1; i <= 60; i++){
        m[i] = mul(m[i-1], m[i-1]);
    }

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if (i == j) ans.mat[i][j] = 1;
            else ans.mat[i][j] = 0;
        }
    }

    for(int i = 0; i <= 60; i++){
        if (p&(1ll<<i)) ans = mul(ans, m[i]);
    }
    
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            printf("%lld ", ans.mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}