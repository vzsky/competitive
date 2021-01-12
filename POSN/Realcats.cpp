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

int a[2000200];
vi v;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    lli l = 0, r = 1e12;
    while(l < r) {
        int mid = (l+r)>>1;
        int CHECK = 1;
        //cerr << l << ' ' << mid << ' ' << r <<endl;
        v.clear();
        for(int i = 0; i < n; i++){
            if(a[i] <= mid) continue;
            //cerr << a[i] << ' '; 
            v.pb(a[i]);
        }
        //logvec(v);
        for(int i = 0; i < v.size(); i+=2){
            if (v[i] == v[i+1]) continue;
            //cerr << i << ' ' << i+1 << ' ' << v[i] << ' ' << v[i+1] <<  endl;
            CHECK = 0;
        }
       // cerr << CHECK << endl;
        if (CHECK)  r=mid;
        else         l=mid+1;
    }
    printf("%lld", l);
    return 0;
}