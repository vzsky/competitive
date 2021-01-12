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

int a[100100], b[100100];
int mark[100100];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for(int i = 1; i <= k; i++)
        scanf("%d", &b[i]);

    int l = 1, r = n+1;
    while(l < r) {
        memset(mark, 0, sizeof(mark));
        int mid = (l+r)>>1;

        int cnt=0, lef=0;
        for(int i = mid; i > 0; i--){
            if (a[i] != 0 && !mark[a[i]]){
                mark[a[i]] = 1;
                lef+=b[a[i]];
                cnt++;
            }
            else if (lef > 0) lef--;

        }
            if (cnt==k && lef == 0){
                r = mid;
            }
            else {
                l = mid+1;
            }
    }
    printf("%d", l==n+1?-1:l);
    return 0;
}