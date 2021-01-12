#include<bits/stdc++.h>
using namespace std;

vector<tuple<int,int,int>> e;
int p[1010];
vector<pair<int,int>> d[1010];
int toprint[1010];
int find(int u) { return u==p[u]?p[u]:p[u] = find(p[u]); }

int dis = 0;
int n, k;
void print(int i) {
    toprint[i] = dis;
    for(auto x : d[i]) {
        if (toprint[x.second] != -1) continue;
        dis += x.first;
        dis %= n;
        // cerr << dis << ' ' << x.second << endl;
        print(x.second);
    }
}

int main(){
    scanf("%d %d", &n, &k);
    iota(p, p+k+1, 0);
    for(int i = 0; i < k; i++) {
        for(int j = 0; j < k; j++){
            int a;
            scanf("%d", &a);
            e.push_back({a, i, j});
        }
    }
    sort(e.begin(), e.end());
    

    for(auto x : e) {
        int a, i, j;
        tie(a, i, j) = x;
        if (find(i) == find(j)) continue;
        else {
            p[find(i)] = find(j);
            d[i].push_back({a, j}); d[j].push_back({a, i});
        }
    }

    memset(toprint, -1, sizeof toprint);
    for(int i = 0; i < k; i++){
        if (d[i].size() == 1) { print(i); break; }
    }
    for(int i = 0; i < k; i++){
        printf("%d ", toprint[i]);
    }
    return 0;
}