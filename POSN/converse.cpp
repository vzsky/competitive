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

int a[7], b[7];

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        memset(a, 0, sizeof a);
        memset(b, 0, sizeof b);
        int ans = 0;
        int n, c;
        scanf("%d", &n);
        for(int i = 0; i < n; i++) {
            scanf("%d", &c);
            a[c]++;
        }
        for(int i = 0; i < n; i++) {
            scanf("%d", &c);
            b[c]++;
        }

        for(int i = 1; i <= 5; i++){
            if ((a[i]+b[i])%2!=0) goto label;
            ans += abs(a[i]-b[i])/2;
        }

        printf("%d\n", (ans+1)/2);
        continue;

        label: printf("-1\n");
    }
    return 0;
}