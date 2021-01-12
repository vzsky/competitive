#include<bits/stdc++.h>
using namespace std;

int start, pub, c[500100], e[500100];
vector<int> g[500100], dag[500100], pubs;

int visited[500100], inst[500100], ind[500100], ll[500100];
int cnt = 1;
stack<int> s;
vector<vector<int>> scc;

void finddag (int u) {
    ind[u] = ll[u] = cnt++;
    s.push(u); inst[u] = 1;
    for (auto x : g[u]) {
        if (ind[x] == 0) {
            finddag(x);
            ll[u] = min(ll[u], ll[x]);
        }
        else if (inst[x]) ll[u] = min(ll[u], ind[x]);
    }
    // cerr << u << ' ' << ind[u] << ' ' << ll[u] << endl;
    if (ind[u] == ll[u]) {
        vector<int> c;
        while(!s.empty()) {
            auto a = s.top(); s.pop();
            c.push_back(a);
            inst[a] = 0;
            if (a == u) break;
        }
        scc.push_back(c);
    }
}

int compof[500100], dagcomps, dagcost[500100], in[500100], maxin[500100];
void builddag () {
    dagcomps = scc.size();
    // for (int i = 0; i < scc.size(); i++) { for (auto node : scc[i]) cerr << node << ' '; cerr << endl; }
    for (int i = 0; i < scc.size(); i++) {
        for (auto node : scc[i]) {
            compof[node] = i+1;
            dagcost[i+1] += c[node];
        }
    }
    for (int i = 0; i < scc.size(); i++) {
        for (auto node : scc[i]) {
            for (auto v : g[node]) {
                if (compof[v] == i+1) continue;
                dag[i+1].push_back(compof[v]);
                in[compof[v]]++;
            }
        }
    }
}

int main(){
    int n, m; scanf("%d %d", &n, &m);
    for (int i = 0; i < m; i++) {
        int u, v; scanf("%d %d", &u, &v);
        g[u].push_back(v);
    }
    for (int i = 1; i <= n; i++) scanf("%d", &c[i]);
    scanf("%d %d", &start, &pub);
    for (int i = 0; i < pub; i++) { int a; scanf("%d", &a); pubs.push_back(a); }
    for (int i = 1; i <= n; i++) if (ind[i] == 0) finddag(i);
    builddag();

    queue<pair<int,int>> q;
    start = compof[start];
    // for (int i = 1; i <= dagcomps; i++) if (in[i] == 0) cerr << "head is " << i << endl;
    for (int i = 1; i <= dagcomps; i++) if (in[i] == 0 and i != start) q.push({i, 0});
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        // cerr << t.first << ' ' << t.second << endl;
        for (auto x : dag[t.first]) {
            in[x]--;
            if (in[x] == 0 and x != start) q.push({x, 0});
        }
    }

    for (auto p : pubs) e[compof[p]] = 1;

    // cerr << "then " << dagcomps << ' ' << start << endl;
    int ans = 0;
    // for (int i = 1; i <= dagcomps; i++) if (in[i] == 0) cerr << "head is " << i << endl;
    q.push({start, dagcost[start]});
    while (!q.empty()) {
        auto t = q.front(); q.pop();
        // cerr << t.first << ' ' << t.second << endl;
        if (e[t.first]) ans = max(ans, t.second);
        for (auto x : dag[t.first]) {
            in[x]--; maxin[x] = max(maxin[x], t.second);
            if (in[x] == 0 and x != start) q.push({x, maxin[x]+dagcost[x]});
        }
    }
    
    printf("%d", ans);
    return 0;
} 