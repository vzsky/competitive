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

int n, t;

int arr[260];

struct A {
    double mat[260][260];
};

A a;

A mul (A a, A b){
    A tmp;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            tmp.mat[i][j] = 0;
            for(int k = 0; k < n; k++){
                tmp.mat[i][j]+= (a.mat[i][k]*b.mat[k][j]);
            }
        }
    }
    return tmp;
}

A m[50];
A ans;

int main(){
    scanf("%d %d", &n, &t);
    for(int i = 0; i < n ;i ++){
        scanf("%d", &arr[i]);
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%lf", &a.mat[i][j]);
        }
    }
    //a.mat ^ t;
    m[0] = a;
    for(int i = 1; i <= 20; i++){
        m[i] = mul(m[i-1], m[i-1]);
    }
    ans = a;
    t--;
    for(int i = 0; i <= 20; i++){
        if (t&(1<<i)) ans = mul(ans, m[i]); //cout << "Y"; 
        //logmat(ans.mat, n-1, n-1);
    }

    for(int i = 0; i < n; i++){
        double abans = 0;
        for(int j = 0; j < n; j++){
            abans += arr[j]*ans.mat[j][i];
        }
        printf("%.2lf\n", abans);
    }
    return 0;
}