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

int c[1010];

int ctl (int n){
    int sum = 0;
    if (c[n]) return c[n];
    for(int i = 1; i < n; i++){
        int a = c[i]==0? ctl(i):c[i];
        int b = c[n-i]==0? ctl(n-i):c[n-i];
        //cerr << n << a << ' ' << b << endl;
        sum += (a*b)%10001;
        sum %= 10001;
    }
    return c[n] = sum;
}

int main(){
    c[1] = c[2] = 1;
    int n;
    scanf("%d", &n);
    printf("%d", ctl(n+1));
    return 0;
}