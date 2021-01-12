#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> e;
vector<int> mst[10100];
int p[10100];
int find (int u) {return (u == p[u])? u:p[u]=find(p[u]);}

int main(){
    int n, t;
    scanf("%d %d", &n, &t);
    for(int i = 1; i <= n; i++){
        p[i] = i;
        for(int j = 1; j <= n; j++){
            int a;
            scanf("%d", &a);
            e.push_back({a, i, j});
        }
    }
    sort(e.begin(), e.end());
    // cerr << "c" << endl;
    for(auto x : e) {
        int w, a, b;
        tie(w, a, b) = x;
        if (find(a) != find(b)) {
            p[find(a)] = find(b);
            mst[a].push_back(b);
            mst[b].push_back(a);
        }
    }
    // cerr << "c" << endl;
    int cnt;
    for(int i = 1; i <= n; i++) {
        // cerr << mst[i].size() << endl;
        if (mst[i].size() >= 3) {
            printf("%d\n", i);
            if (t==2) printf("%d\n", (int)mst[i].size());
            return 0;
        }
    }

    return 0;
}