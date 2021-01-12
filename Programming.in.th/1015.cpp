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

int tab[20][20];
int visited[20][20];
int onstack[20][20];
int di[] = {0,0,1,-1}; int dj[]={1,-1,0,0};

int n;

int play(int i, int j){
    visited[i][j] = 1;
    int ans = 0;
    for(int d = 0; d < 4; d++){
        int ni = di[d]+i;
        int nj = dj[d]+j;
        if (ni <= 0 || ni > n || nj <= 0 || nj > n) continue;
        if (visited[ni][nj] || onstack[ni][nj]) continue;
        if (tab[ni][nj] != tab[i][j]) continue;
        ans+= play(ni, nj)+1;
    }
    // cerr << i << j << ' ' << ans << endl;
    return ans;
}

int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &tab[i][j]);
        }
    }

    int ans = 0;
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            if (visited[i][j]) continue;
            if (play(i, j) == 2){
                // cerr << i << ' ' << j << endl;
                int ch1 = 0, ch2 = 0;
                for(int ii = 0; ii < 3; ii++){
                    if (tab[i][j] == tab[i][j+ii]) continue;
                    ch1 = 1;
                    break;
                }
                for(int ii = 0; ii < 3; ii++){
                    if (tab[i][j] == tab[i+ii][j]) continue;
                    ch2 = 1;
                    break;
                }
                if ((ch1^ch2) == 0) ans++;
            }
        }
    }
    printf("%d", ans);
    return 0;
}