#include<bits/stdc++.h>
using namespace std;

int n;
long long mx = 0;
vector<int> g[100100];
int subtree[100100], bottom[100100];

void dfs (int u, int p) {
  bottom[u] = 0;
  subtree[u] = 1;
  for (auto x : g[u]) {
    if (x == p) continue;
    dfs(x, u);
    bottom[u] += bottom[x];
    subtree[u] += subtree[x];
  }
  bottom[u] += subtree[u];
}

void top (int u, int p, int fromtop) {
  for (auto x : g[u]) {
    if (x == p) continue;
    long long ans = bottom[x] * (n-subtree[x]) + (fromtop + bottom[u] - bottom[x] - subtree[x] - 1) * subtree[x];
    mx = max(mx, ans);
    top(x, u, fromtop + bottom[u] - bottom[x] - subtree[x] - 1 + subtree[u] - subtree[x]);
  }
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n-1; i++) {
    int a, b; cin >> a >> b;
    g[a].push_back(b);
    g[b].push_back(a);
  }
  dfs(1, 1);
  top(1, 1, 0);
  cout << mx * 4 << endl;
  return 0;
}