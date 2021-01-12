// parallel bsearch second mst

#include<bits/stdc++.h>
using namespace std;

const int N = 2e5+5;

struct E {
    int u, v, w;
    bool operator < (const E & o) const {
        return w < o.w;
    }
};
vector<E> e, mst, nmst;
int par[N], l[N], r[N];
vector<int> q[N];

int find(int u) {return par[u] == u ? par[u] : par[u] = find(par[u]); }
void init() {
    for(int i = 0; i < N; i++){
        par[i] = i;
    }
}



int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i < 2*n; i++){
        int a;
        int x = i/2;
        if (i&1) {
            for(int j = 1; j < m; j++){
                scanf("%d", &a);
                e.push_back({x*m+j, x*m+j+1, a});
            }
        }
        else {
            for(int j = 1; j <= m; j++){
                scanf("%d", &a);
                e.push_back({x*m+j, x*m+j-m, a}); //! check this shit
            }
        }
    }
    sort(e.begin(), e.end());
    init();
    for(auto x : e){
        if (find(x.u) == find(x.v)) nmst.push_back(x);
        else {
            par[find(x.u)] = find(x.v);
            mst.push_back(x);
        }
    }

    for(int i = 0; i < nmst.size(); i++){
        l[i] = 1;
        r[i] = (int)mst.size();
    }

    bool s = true;
    while(s) {
        s = false;
        for(int i = 0; i < nmst.size(); i++){
            if (l[i] < r[i]) {
                s = true;
                int m = (l[i]+r[i])/2;
                q[m].push_back(i);
            }
        }
        init();
        for(int i = 0; i < mst.size(); i++){
            par[find(mst[i].u)] = find(mst[i].v);
            for(auto x : q[i]) {
                if (find(nmst[x].u) == find(nmst[x].v)) r[x] = i;
                else l[x] = i+1; 
            }
            q[i].clear();
        }
    }

    int mn = 2e9;
    for(int i = 0; i < nmst.size(); i++){
        mn = min(mn, nmst[i].w - mst[l[i]].w);
    }
    printf("%d", mn);

    return 0;
}