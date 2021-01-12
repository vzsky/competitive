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

map<vector<pii>, int> m;

int main(){
    int t, q;
    scanf("%d %d", &t, &q);
    for(int i = 0; i < t ; i++){
        int n;
        scanf("%d", &n);
        vector<pii> v;
        for(int i = 0; i < n-1; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            if (a < b) swap(a, b);
            v.pb({a, b});
        }
        sort(v.begin(), v.end());
        m[v]++;
    }
    for(int i = 0; i < q ; i++){
        int n;
        scanf("%d", &n);
        vector<pii> v;
        for(int i = 0; i < n-1; i++){
            int a, b;
            scanf("%d %d", &a, &b);
            if (a < b) swap(a, b);
            v.pb({a, b});
        }
        sort(v.begin(), v.end());
        printf("%d\n", m[v]);
    }
    return 0;
}