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

int fw[500100];

int main(){
    int n, m;
    scanf("%d %d", &n ,&m);
    char cmd[10];
    for(int i = 0; i < m; i++){
        cin >> cmd;
        if (cmd[0] == 'Y'){
            int v, a, b;
            scanf("%d %d %d", &v, &a, &b);
            if (a > b) swap(a, b);
            for(int i = a; i <= n; i+=(i&-i)){
                fw[i] += v;
            }
            for(int i = b+1; i <= n; i+=(i&-i)){
                fw[i] -= v;
            }
        } 
        else {
            int a;
            int ans = 0;
            scanf("%d", &a);
            for(int i = a; i > 0; i-=(i&-i)){
                ans += fw[i];
            }
            printf("%d\n", ans);
        }
    }
    return 0;
}