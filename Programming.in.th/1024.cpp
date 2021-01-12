#include<bits/stdc++.h>
using namespace std;
#define inp(a, b) b a; cin >> a;
#define x first
#define y second
#define pb push_back
#define For(i, start, en) for(auto i = start; i <= en; i++)
#define log(x) cout << #x << " is " << x << endl;
#define logarr(start, en) cout << #start << " : "; For(it, start, en) cout << *it << ' '; cout << endl;
#define logvec(v) cout << #v << " : "; for(auto x : v) cout << x << ' '; cout << endl;
#define logmat(a, m, n) For(i, 0, m) { For(j, 0, n) cout << a[i][j] << ' '; cout << endl; }
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;

#define DEBUG 1

#if !DEBUG
#undef log
#undef logarr
#undef logvec
#undef logmat
#define cout //
#endif

vector <int> v, v2;

int main(){
    int n, m, q;
    scanf("%d %d %d", &n, &m, &q);
    int cnt = 0;
    
    while(m--){
        int a, b;
        scanf("%d %d", &a, &b);
        v.pb(a); v.pb(a+b);
        cnt+=2;
    }

    sort(v.begin(), v.end());
    for(int i = 0; i < cnt; i++){
        if (i+1 < cnt && v[i] == v[i+1]) {i++; continue;}
        v2.pb(v[i]);
    }

    if (!v2.empty() && v2.back() != n+1) v2.pb(n+1);
    if (!v2.empty() && v2.front() != 1) v2.pb(1);
    if (v2.empty()) {
        v2.pb(1), v2.pb(n+1);
    }

    //logvec(v2);

    sort(v2.begin(), v2.end());

    while(q--){
        int a;
        scanf("%d", &a);
        int i = upper_bound(v2.begin(), v2.end(), a)-v2.begin();
        printf("%d\n", v2[i]-v2[i-1]);
    }
    return 0;
}