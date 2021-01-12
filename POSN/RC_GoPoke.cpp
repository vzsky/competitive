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

int a[110];
string s;

map<pii, string> m;

int main(){
    int n;
    scanf("%d", &n);
    int ans = 0;
    for(int i = 0; i < n; i++){
        cin >> s;
        int b, c;
        scanf(" %d %d", &b, &c);
        int t = 0;
        while(c >= b){
            int nt = c/b;
            c %= b;
            c += nt*2;
            t+=nt;
            //cerr << "NT " <<  nt << endl;
        }
        m[{-t, i}] = s;
        ans += t;
        // cerr << t << endl;
    }
    printf("%d\n", ans);
    for(auto x : m){
        cout << x.y;
        break;
    }
    return 0;
}