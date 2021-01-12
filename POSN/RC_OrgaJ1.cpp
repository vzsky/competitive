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

vi g[200200];
int vis[200200];
queue<pii>q;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        int a;
        scanf("%d", &a);
        for(int j = 0; j < a; j++){
            int u;
            scanf("%d", &u);
            g[i+n+1].pb(u);
            g[u].pb(i+n+1);
        }
    }
    int quest;
    scanf("%d", &quest);
    while(quest--){
        int a, b;
        int ans = 0;
        scanf("%d %d", &a, &b);
        q.push({a,0});
        memset(vis, 0, sizeof vis);
        vis[a] = 1;
        while(!q.empty()){
            auto t = q.front(); q.pop();
            //cerr << t.x << endl;
            if (t.x == b) { ans = t.y; break; }

            for(auto x : g[t.x]) {
                //cerr << t.x << ' ' << x << endl;
                if (!vis[x]) {q.push({x, t.y+1}); vis[x] = 1;}
            }
        }
        while(!q.empty()) q.pop();
        printf("%d\n", ans/2);

    }

    return 0;
}