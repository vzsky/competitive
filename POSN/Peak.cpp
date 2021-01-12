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

int a[5000100];
vi ans;

int main(){
    int n, k;
    int ch = 1;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n; i++){
        if (a[i] > a[i-1] && a[i] > a[i+1]) {
            ans.pb(a[i]);
            ch = 0;
        }
    }

    if (ch) {
        printf("-1");
        return 0;
    }

    sort(ans.begin(), ans.end());
    

    for(int i = 1; i <= ans.size(); i++){
        if (ans[i] == ans[i-1]) ans[i-1] = 2e9;
    }
    sort(ans.begin(), ans.end());
    while(*--ans.end() == 2e9) ans.pop_back();
    

    logvec(ans);
    if (ans.size() >= k){
        for(int i = ans.size()-1, j = 0; j < k; i--, j++){
            printf("%d\n", ans[i]);
        }
    }
    else {
        for(int i = 0; i < ans.size(); i++){
            printf("%d\n",ans[i]);
        }
    }
    return 0;
}