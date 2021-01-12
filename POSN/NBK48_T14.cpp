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

int a[100100];

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        a[i]+=a[i-1];
    }
    //logarr(a, a+n);
    for(int i = n-1; i > 0; i--){
        a[i] = min(a[i], a[i+1]);
    }
    a[n+1] = 2e9;
    logarr(a, a+n+1);
    while(q--){
        int qu;
        scanf("%d", &qu);
        int ind = upper_bound(a+1, a+n+1, qu)-a;
        //cerr << a[ind] << endl;
        printf("%d\n", ind-1);
    }

    return 0;
}