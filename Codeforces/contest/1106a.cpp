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
#if !DEBUG
#undef log
#undef logarr
#undef logvec
#undef logmat
#define cout //
#endif

#define DEBUG 1

char mat[510][510];
int ans = 0;

int main(){
    inp(n,int);
    For(i, 0, n-1){
        For(j, 0, n-1){
            cin >> mat[i][j];
        }
    }
    For(i, 0, n-1){
        For(j, 0, n-1){
            if (mat[i][j] == 'X'){
                if (mat[i-1][j-1] == 'X' && mat[i-1][j+1] == 'X' && mat[i+1][j-1] == 'X' && mat[i+1][j+1] == 'X'){
                    ans++;
                }
            }
        }
    }
    printf("%d", ans);
return 0;
}