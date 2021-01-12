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

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        lli a;
        lli ans = 0;
        scanf("%lld", &a);
        while (a%2==0) { a/=2; ans++; }
        while (a%3==0) { a/=3; ans+=2; }
        while (a%5==0) { a/=5; ans+=3; }
        printf("%lld\n", a==1?ans:-1);
    }
    return 0;
}