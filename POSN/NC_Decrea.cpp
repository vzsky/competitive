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

int a[100010];
lli mic[100010][2];

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        memset(mic, 0, sizeof mic);
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
        }
        for(int i = 2; i <= n; i++){
            mic[i][0] = max(mic[i-1][0]+abs(a[i]-a[i-1]), mic[i-1][1]+abs(a[i]-1));
            mic[i][1] = max(mic[i-1][0]+abs(a[i-1]-1), mic[i-1][1]);
        }
        printf("%lld\n", max(mic[n][0], mic[n][1]));
    }
    return 0;
}