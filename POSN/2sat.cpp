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

int nega[200100];
pii cons[100100];
stack <int> s;
vi g[100100];

// tarjan
int ind[100100];
int ll[100100];
int instack[100100];
int scc[100100];
int cnt = 1, cntscc = 1;

void dfs(int n){
    // not ness to return if visited since won't be call anyhow if visited
    ind[n] = ll[n] = cnt++; 
    instack[n] = 1;
    s.push(n);

    for(auto x : g[n]){
        if (!ind[x]) {
            dfs(x);
            ll[n] = min(ll[n], ll[x]);
        }
        else if (instack[x]) {
            ll[n] = min(ll[n], ind[x]);
        }
    }
    if (ind[n] == ll[n]) {
        while(!s.empty()) {
            auto a = s.top(); s.pop();
            scc[a] = cntscc;
            instack[a] = 0;
            if (a == n) break;
        }
        cntscc++;
    }
}

int n, m, a, b;
int i, abc;

int main(){
    abc = 5;
    while(abc--){
        scanf("%d %d", &n, &m);
        for(i = 0; i < n; i++){
            scanf("%d %d", &cons[i].x, &cons[i].y);
        }
        for(i = 0; i < m/2; i++){
            scanf("%d %d", &a, &b);
            nega[a] = b;
            nega[b] = a;
        }

        memset(ll, 0, sizeof ll); // should not be ness
        memset(ind, 0, sizeof ind);
        memset(scc, 0, sizeof scc); // should not be ness
        memset(instack, 0, sizeof instack);
        for(i = 1; i <= m; i++){
            g[i].clear();
        }
        cnt = cntscc = 1;
        while(!s.empty()){
            s.pop();
        }

        for(i = 0; i < n; i++){
            g[cons[i].x].pb(nega[cons[i].y]);
            g[cons[i].y].pb(nega[cons[i].x]);
        }
        for(i = 1; i <= m; i++){
            if (!ind[i]) dfs(i);
        }

        //logarr(scc, scc+m);
        for(i = 1; i <= m; i++){
            if (scc[i] == scc[nega[i]]){
                printf("N");
                goto endloop;
            }
        }
        printf("Y");
        endloop : continue;
    }
    return 0;
}
/*
4 6 2 3 6 5 3 4 1 2 1 3 2 5 4 6
3 4 1 2 2 3 4 3 1 3 2 4
4 8 1 2 3 4 5 6 7 8 1 3 2 4 5 7 6 8
3 4 1 2 2 3 3 4 2 3 1 4 
5 4 1 2 2 3 4 3 1 3 4 2 1 4 2 3

*/