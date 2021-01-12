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

int mn[4100];

int main(){
    int n , m, q;
    scanf("%d %d %d", &n, &m, &q);
    for(int i = 0; i <= n; i++) mn[i] = 2e9;
    for(int i = 0; i < m; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        mn[a] = min(mn[a], c);
        mn[b] = min(mn[b], c);
    }
    for(int i = 0; i < q; i++){
        int k;
        int cnt = 0;
        int ch = 1;
        scanf("%d", &k);
        for(int j = 1; j <= n; j++){
            if (mn[j] > k) cnt++;
            if (mn[j] <= k) ch = 0;
        }
        if (!ch) cnt++;
        printf("%d\n", cnt);
    }
    
    return 0;
}