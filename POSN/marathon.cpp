#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
typedef long long int lli;
typedef pair<int,int> pii;

struct A {
    int v, d; lli l;
    bool operator < (const A & o) const {
        return l > o.l;
    }
};

vector <A> g[100100];

pii shoe[100100];
priority_queue <A> heap;

bool visited[100100];

int main(){
    int n, m, k, t;
    scanf("%d %d %d %d", &n, &m, &k, &t);
    for(int i = 0; i < m; i++){
        int u, v, d, l;
        scanf("%d %d %d %d", &u, &v, &d, &l);
        g[u].pb({v, d, l});
        g[v].pb({u, d, l});
    }
    for(int i = 0; i < k; i++){
        int p, s;
        scanf("%d %d", &p, &s);
        shoe[i] = {s, p};
    }

    int l = 1; int r = 1e5+1;

    while (l < r) {

        memset(visited, 0, sizeof visited);
        while(!heap.empty()) heap.pop();

        int mid = (l+r)>>1;

        int ch = 0;
        heap.push({1, 0, 0});

        while(!heap.empty()){
            auto tp = heap.top(); heap.pop();

            if (tp.v == n) {ch=1;break;}
            if (visited[tp.v]) continue;
            visited[tp.v] |= 1;

            for(auto x : g[tp.v]){
                if (visited[x.v] || x.d > mid || x.l+tp.l>t) continue;
                heap.push({x.v, 0, x.l+tp.l});
            }
        }
        if (ch) r = mid;
        else l = mid+1;
    
    }

    int pri = 2e9;

    for(int i = 0; i < k; i++){
        if (shoe[i].x >= l) {
            pri = pri < shoe[i].y?pri : shoe[i].y;
        }
    }

    if (pri == 2e9) {printf("-1"); return 0;}

    printf("%d", pri);
    
    return 0;
}