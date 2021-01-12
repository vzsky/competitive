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

struct A {
    int x, y;
};

bool cmpx (A a, A b){
    if (a.x != b.x) return a.x < b.x;
    return a.y > b.y;
}
// bool cmpy (A a, A b){
//     if (a.y != b.y) return a.y < b.y;
//     return a.x > b.x;
// }

vector <A> v;
vector <A> ans;
stack <A> s;

int main(){
    inp(n, int);
    For(i, 0, n-1){
        int a, b;
        scanf("%d %d", &a, &b);
        v.pb({a,b});
    }
    sort(v.begin(), v.end(), cmpx);
    For(i, 1, n-1){
        if (v[i].y > v[i-1].y) continue;
        s.push(v[i-1]); 
    }
    s.push(v[n-1]);
    int mx = -1;
    while(!s.empty()){
        auto a = s.top(); s.pop();
        //cout << a.x << ' ' << a.y << endl;
        if (a.y < mx) {
            continue;
        }
        mx = max(mx, a.y);
        ans.pb({a.x, a.y});
    }
    sort(ans.begin(), ans.end(), cmpx);
    for(auto a : ans) {
        printf("%d %d\n", a.x, a.y);
    }
    return 0;
}