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

int cnt [3];

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int n;
        memset(cnt, 0, sizeof cnt);
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            int a;
            scanf("%d", &a);
            cnt[a%3]++;
        }
        int ans = cnt[0];
        if (cnt[1] > cnt[2]) ans += cnt[2]+(cnt[1]-cnt[2])/3;
        else ans += cnt[1]+(cnt[2]-cnt[1])/3;
        printf("%d\n", ans);
    }
    return 0;
}