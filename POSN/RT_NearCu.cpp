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

lli cnt[100100];
lli mic[100100];

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        memset(mic, 0, sizeof mic);
        memset(cnt, 0, sizeof cnt);
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            int a;
            scanf("%d", &a);
            cnt[a]++;
        }
        mic[1] = cnt[1];
        for(int i = 2; i <= 100005; i++){
            mic[i] = max(mic[i-2]+(cnt[i]*i), mic[i-1]);
        }
        printf("%lld\n", mic[100005]);
    }
    return 0;
}