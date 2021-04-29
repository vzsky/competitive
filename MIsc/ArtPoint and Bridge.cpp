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

#define MAXN 1000

int ind[MAXN], inst[MAXN], ll[MAXN];
int cnt = 1;
stack <int> s;
vi g[MAXN], AP, B;

void tarjan (int node, int par){
    ind[node] = ll[node] = cnt++;
    s.push(node);
    int child = 0;
    for(auto x : g[node]){
        if (!ind[x]) {
            child++;
            tarjan(x, node);
            ll[node] = min(ll[node], ll[x]);
            if ((ll[x] >= ind[node] && par != 0) || (par == 0 && child > 1)){
                // x can't reach node ( no backward edge from x to node )
                // and x can't reach any anc. of node
                // cutting node splits children of x and anc. of node
                // par != 0 to prevent case 1 -> 2 -> 3
                // par == 0 && child > 1 to prevent case 1 -> 2, 1-> 3
                AP.push_back(node);
            }
            if (ll[x] > ind[node]) {
                B.push_back(node);
            }
        }
        else if (inst[x]) {
            ll[node] = min(ll[node], ind[x]);
        }
    }
}

int main(){
    
    return 0;
}