#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define For(a,b) for(int a = 0; a < b; a++)
#define _cerrheader(a) cerr << #a << " : "
#define log(a) _cerrheader(a) << a
#define logarr(a, b) { _cerrheader(a); For(i, b) cerr << a[i] << ' ';}
#define logvec(v) { _cerrheader(a); for(auto i : v) cerr << v[i] << ' ';}
#define logmat(a,b,c) For(i,b) { For(j,c) cerr << a[i][j] << ' ';  cerr << endl;}
typedef pair<int,int> pii;
typedef long long lli;
typedef vector<int> vi;

vector<lli> v(80);
void three(lli n) {
    v.clear();
    while(n) {
        v.pb(n%3ll);
        n/=3ll;
    }
}

lli print(int id) {
    lli s = 1ll;
    lli ans = 0ll;
    for(auto it = v.begin(); it != v.end(); it++) {
        lli X = *it;
        X *= s;
        s *= 3ll;
        if (it-v.begin() < id) continue;
        ans += X;
    }
    return ans;
}

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        lli n;
        scanf("%lld", &n);
        three(n);
        lli tod = 0ll;
// for(auto x : v) {
//             cerr << x << endl;
//         }cerr << endl;
        vector<lli>::iterator last = v.begin();
        for(auto it = v.begin(); it != v.end(); it++) {
            *it+=tod, tod = 0ll;
            if (*it >= 2ll) { tod++; *it = 0ll; last = it; }
        }
        if (tod) {v.push_back(1);}
        // cerr << last-v.begin() << endl;
        // for(auto x : v) {
        //     cerr << x << endl;
        // }
        printf("%lld\n", print(last-v.begin()));
    }
    return 0;
}