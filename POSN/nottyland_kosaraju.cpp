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
stack<int> nodes, s;
int visited[100100];
int scc[100100];

void dfs (int node) {
    if (visited[node]) return;
    visited[node] = 1;
    for(auto x : g[node]){
        if (!visited[x]) dfs(x);
    }
    nodes.push(node);
    //cerr << node << endl;
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 1; i <= n; i++){
        int d;
        scanf("%d", &d);
        for(int j = 0; j < d; j++){
            int u;
            scanf("%d", &u);
            g[i].pb(u);
            gt[u].pb(i);
        }
    }

    for(int i = 1; i <= n; i++){
        if (!visited[i]) dfs(i);
    }

    memset(visited, 0, sizeof visited);
    int cnt = 0;

    while(!nodes.empty()){
        auto t = nodes.top(); nodes.pop();
        //cerr << t << endl;
        if (visited[t]) continue;

        s.push(t);

        while(!s.empty()){
            auto tp = s.top(); s.pop();

            if (visited[tp]) continue;
            visited[tp] = 1;

            scc[tp] = cnt;

            for(auto x : gt[tp]){
                if (!visited[x]) s.push(x);
            }
        }
        cnt++;
    }


    for(int i = 0; i < k; i++){
        int u, v;
        scanf("%d %d", &u, &v);
        if (scc[u] == scc[v]) {
            printf("yes\n");
        }
        else printf("no\n");
    }
    return 0;
}