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

int a[1010];

int main(){
    int n, A;
    scanf("%d %d", &n, &A);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    int sum = 0;
    int ans = 0;
    int mx = -2e9;
    for(int l = 1; l <= n; l++){
        ans = 0;
        sum = 0;
        for(int r = l; r <= n; r++){
            sum += a[r];
            ans++;
            if(sum > A) {
                sum -= a[r];
                ans--;
            }
        }
        //cerr << l << ' ' << ans << endl;
        mx = max(mx, ans);
    }
    printf("%d", mx);
    return 0;
}