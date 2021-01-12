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

vi g[400200];

// tarjan
int ll[400200];
int ind[400200];
int scc[400200];
int inst[400200];
int cnt, cntscc;
stack<int> s;

void tarjan (int n) {
    ll[n] = ind[n] = cnt++;
    inst[n] = 1;
    s.push(n);

    for (auto x : g[n]) {
        if (!ind[x]) {
            tarjan(x);
            ll[n] = min(ll[n], ll[x]);
        }
        else if (inst[x]){
            ll[n] = min(ll[n], ind[x]);
        }
    }
    if (ind[n] == ll[n]){
        while(!s.empty()){
            auto a = s.top(); s.pop();
            scc[a] = cntscc;
            inst[a] = 0;
            if (a == n) break;
        }
        cntscc++;
    }
}

int main(){
    for(int A = 0; A < 5; A++){

        int n, m;
        scanf("%d %d", &n, &m);

        memset(ind, 0, sizeof ind);
        memset(ll, 0, sizeof ll);
        memset(inst, 0, sizeof inst);
        memset(scc, 0, sizeof scc);
        while(!s.empty()) s.pop();
        cnt = 1; cntscc = 1;
        for(int i = 0; i <= 2*m+1; i++){
            g[i].clear();
        }

        for(int i = 0; i < n; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            g[2*u].pb(2*v+1);
            g[2*v].pb(2*u+1);
        }
        for(int i = 0; i < m/2; i++){
            int u, v;
            scanf("%d %d", &u, &v);
            g[2*u+1].pb(2*v);
            g[2*v+1].pb(2*u);
        }

        for(int i = 1; i <= m; i++){
            if (!ind[2*i]) tarjan(2*i);
            if (!ind[2*i+1]) tarjan(2*i+1);
        }

        for(int i = 1; i <= m; i++){
            if (scc[i*2] == scc[i*2+1]) {
                printf("N");
                goto endloop;
            }
        }
        printf("Y");
        endloop : ;
    }

    return 0;
}