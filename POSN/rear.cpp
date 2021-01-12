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

int a[10100];
int dp[10100];

int main(){
    int q;
    scanf("%d", &q);
    while(q--){

        int n, m;
        scanf("%d %d", &n, &m);

        for(int i = 0; i < m; i++){
            scanf("%d", &a[i]);
        }
        sort(a, a+m);

        memset(dp, 0, sizeof dp);
        dp[0] = 1;
        
        for(int i = 0; i < m-1; i++){
            if (a[i] > n) break;
            for(int j = n-a[i]; j >= 0; j--){
                if (!dp[j]) continue;
                dp[j+a[i]] = 1;
            }
        }

        for(int i = n-1; i >= 0; i--){
            if (dp[i]) {
                n -=i;
                break;
            } 
        }

        n-=a[m-1];
        printf("%d\n", n);
    }
    return 0;
}