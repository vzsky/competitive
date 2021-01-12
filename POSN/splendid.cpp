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

#define md 10000019

struct A {
    lli a[2][2];
};

A mul (A a, A b){
    A ans;
    for(int i = 0; i < 2; i++){
        for(int j = 0; j < 2; j++){
            ans.a[i][j] = 0;
            for(int k = 0; k < 2; k++){
                ans.a[i][j] += a.a[i][k]*b.a[k][j];
                ans.a[i][j] %= md;
            }
        }
    }
    return ans;
}

/* Divide and conquer */

A fib1 = {1, 1, 1, 0};
A divide (int n){
    if (n == 1) return fib1;
    int m = n>>1;
    auto x = mul(divide(m),divide(m));
    if (n&1) return mul(x, divide(1));
    return x;
}

/* ------------------ */

A m[50], ans;

int main(){
    inp(q, int);

    /* Bin Matrix Exponentiation */

    // m[0] = {1,1,1,0};
    // for(int i = 1; i <= 42; i++){
    //    m[i] = mul(m[i-1], m[i-1]);
    // }

    // while(q--){
    //     inp(n, lli);
    //     ans = {1,0,0,1}; // Identity
    //     for(int i = 0; i <= 42; i++){
    //         if (n & 1ll << i) ans = mul(m[i], ans);
    //     }
    //     cout << ans.a[0][1] << endl;
    // }

    /* ---------- */

    /* More on Divide Conquer */
    
    // while(q--){
    //     inp(n, int);
    //     if (n == 0) { cout << 0 << endl; continue; }
    //     auto a = divide(n);
    //     cout << a.a[0][1] << endl;
    // }

    return 0;
}