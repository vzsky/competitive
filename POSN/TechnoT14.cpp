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


vi g[100100], gt[100100];
int acc[100100], in[100100], lv[100100], ans[100100], mlv[100100], dp[100100];
queue<int> q;
struct A {
    int i;
    bool operator < (const A & o) const{
        return dp[i] > dp[o.i];
    }
};
priority_queue<A> heap;

int main(){
    int n, k, T;
    scanf("%d %d %d", &n, &k, &T);
    for(int i = 1 ; i <= n; i++){
        int n;
        scanf("%d %d", &lv[i], &n);
        mlv[lv[i]]++;
        for(int j = 0; j < n; j++){
            int a;
            scanf("%d", &a);
            g[a].pb(i);
            in[i]++;
        }
    }
    for(int i = 1; i <= n; i++){
        if (in[i] == 0) {
            acc[i] = 1;
            q.push(i);
        }
    }
    while(!q.empty()){
        int t = q.front(); q.pop();
        for(int x : g[t]){
            in[x]--;
            if (in[x] == 0) {
                q.push(x);
                acc[x] = 1;
            }
        }
    }

    memset(in, 0, sizeof in);
    for(int i = 1; i <= n; i++){
        if (!acc[i]) continue;
        for(int x : g[i]){
            if (!acc[x]) continue;
            gt[x].pb(i);
            in[i]++;
        }
    }
    for(int i = 1; i <= n; i++){
        if (!acc[i]) continue;
        dp[i] = lv[i];
        //!? swap
        if (!in[i]) q.push(i);
    }
    while(!q.empty()){
        int t = q.front(); q.pop();
        for(int x : gt[t]) {
            if (!acc[x]) continue;
            dp[x] = min(dp[t], dp[x]);
            in[x]--;
            if (in[x] == 0) q.push(x);
        }
    }
    
    memset(in, 0, sizeof in);
    for(int i = 1; i <= n; i++){
        if (!acc[i])continue;
        for(int x : g[i]) in[x]++;
    }
    for(int i = 1; i <= n; i++){
        if (!acc[i]) continue;
        if (in[i] == 0) {
            heap.push({i});
        }
    }
    while(T-- && !heap.empty()){
        auto t = heap.top(); heap.pop();
        // cerr << t.i << endl;
        ans[lv[t.i]]++;
        for(int x : g[t.i]){
            if (!acc[x]) continue;
            in[x]--;
            if (in[x] == 0) heap.push({x});
        }
    }
    int Ans = k;
    for(int i = 1; i <= k; i++){
        if (ans[i] != mlv[i]) {
            Ans = i-1;
            break;
        }
    }
    printf("%d",Ans?Ans:-1);
    return 0;
}