#include<bits/stdc++.h>
using namespace std;

struct A {int u, v, w, i; 
    bool operator < (const A & o) const {return w < o.w;}
};
vector<A> edge;
int sum;
int p[6100][210];
int mst[6100], cnt[6100];

void clear() { for (int i = 1; i <= 205; i++) for (int j = 0; j <= 6010; j++) p[j][i] = i; }
int find(int u, int i) {return u==p[i][u]?u:p[i][u]=find(p[i][u], i);}
bool connect(int u, int v, int i) {
    u = find(u, i); v = find(v, i);
    if (u == v) return false;
    p[i][u] = v;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, q; cin >> n >> q;
    for (int i = 0; i < q; i++) {
        int u, v, w; cin >> u >> v >> w;
        edge.push_back({u, v, w, i});
    }
    sort(edge.begin(), edge.end());

    clear();
    for (auto e : edge) {
        for (int i = e.i; i < q; i++) {
            if (connect(e.u, e.v, i)) mst[i] += e.w, cnt[i]++;
        }
    }

    for (int i = 0; i < q; i++) cout << (cnt[i]==n-1?mst[i]:-1) << endl;

    return 0;
}