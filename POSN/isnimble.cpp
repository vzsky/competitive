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

lli mul[41][41][41][41];
int tab[41][41];
lli dp[41][41][41][41];

lli play(int i, int j, int k, int l) {
    if (dp[i][j][k][l] != -1) return dp[i][j][k][l];
    if (i == k && j == l) return 0;
    lli mn = 1e18;
    for(int x = i; x < k; x++) {
        mn = min(mn, play(i, j, x, l) + play(x+1, j, k, l) + mul[i][j][x][l] + mul[x+1][j][k][l]);
    }
    for(int x = j; x < l; x++){
        mn = min(mn, play(i, j, k, x) + play(i, x+1, k, l) + mul[i][j][k][x] + mul[i][x+1][k][l]);
    }
    return dp[i][j][k][l] = mn;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);

    memset(dp, -1, sizeof dp);

    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= m; j++){
            scanf("%d", &tab[i][j]);
        }
    }
    
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            for(int k = i; k <= n; k++){
                for(int l = j; l <= m; l++){
                    mul[i][j][k][l] = 1;
                    for(int r = i; r <= k; r++){
                        for(int s = j; s <= l; s++){
                            mul[i][j][k][l] *= tab[r][s]; 
                        }
                    }
                }
            }
        }
    }

    printf("%lld", play(1,1,n,m));
    return 0;
}