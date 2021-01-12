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

int p[25];
int st[5];
int cnt[25];

int main(){
    int k, n, s;
    scanf("%d", &k);
    for(int i = 1; i <= k; i++){
        scanf("%d", &p[i]);
    }
    scanf("%d", &s);
    for(int i = 0; i < 4; i++){
        scanf("%d", &st[i]);
    }

    int ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int w;
        scanf("%d", &w);
        cnt[w]++;
        ans += p[w];
    }

    // ans store choose 0 sts;

    
    for(int i = 1; i < n; i++){ // buy i sts;
        int temp = s*i;
        for(int j = 0; j < 4; j++){
            cnt[st[j]]--;
        }
        for(int j = 1; j <= k ; j++){
            if (cnt[j] <= 0) continue;
            temp+=p[j]*cnt[j];
        }
        //cerr << temp <<endl;
        ans = min(ans, temp);
    }
    printf("%d", ans);
    return 0;
}