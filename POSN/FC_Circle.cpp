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

map<int,int> m;
int cnt = 1;

pii cir[300100];
int p[600100];
vi s;

int find (int i) {
    if (i == p[i]) return p[i];
    return p[i] = find(p[i]);
}

int main(){
    int n;
    scanf("%d", &n);
    int ans = 1+n;
    for(int i = 0; i < n; i++){
        int x, r;
        scanf("%d %d", &x, &r);
        s.pb(x+r);
        s.pb(x-r);
        cir[i].x = x-r;
        cir[i].y = x+r;
    }
    sort(s.begin(), s.end());
    for(auto x : s) m[x] = cnt++;
    for(int i = 0; i <= cnt; i++) p[i] = i;

    for(int i = 0; i < n; i++){
        if (find(m[cir[i].x]) == find(m[cir[i].y])) {
            ans++;
            //cerr << cir[i].x << ' ' << cir[i].y << ' ' << find(m[cir[i].x]) << endl;
        }
        p[find(m[cir[i].x])] = p[find(m[cir[i].y])];
    }
    printf("%d", ans);
    return 0;
}