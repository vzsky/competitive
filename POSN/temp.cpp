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

#define MOD 1000000007

int fib (int n){
    if (n == 0) return 14;
    if (n == 1) return 15;
    if (n == 2) return 63;
    return (6*fib(n-3)+5*fib(n-2)-2*fib(n-1))%MOD;
}

int main(){
    int a;
    scanf("%d", &a);
    for(int i = 0; i < a; i++){
        printf("%d\n", fib(i));
    }
    return 0;
}