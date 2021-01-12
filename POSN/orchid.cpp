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

int lis[1000100], a[1000100];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d",&a[i]);
        lis[i] = 2e9;
    }
    int mx = 0;
    for(int i = 0; i < n; i++){
        int f = upper_bound(lis, lis+n, a[i])-lis;
        if (lis[f] == a[i])f++;
        //cerr << f << endl;
        lis[f] = a[i];
        mx = max(mx, f);
    }
    printf("%d", n-mx-1);
    return 0;
}