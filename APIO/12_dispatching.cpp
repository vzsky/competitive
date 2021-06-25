#include<bits/stdc++.h>
using namespace std;

long long c[100100], l[100100], h[100100], cost[100100];
vector<int> g[100100];
priority_queue<long long> heap[100100];
int n, m, root;

long long dfs (int u, int p) {
  long long ans = 0, big = 0;
  for (auto x : g[u]) {
    ans = max(ans, dfs(x, u));
    if (heap[h[x]].size() > heap[h[big]].size()) big = x;
  }
  h[u] = big==0?u:h[big];
  heap[h[u]].push(c[u]); cost[h[u]] += c[u];
  for (auto x : g[u]) if (x != big) while(!heap[h[x]].empty()) {
    auto ele = heap[h[x]].top(); heap[h[x]].pop();
    heap[h[u]].push(ele); cost[h[u]] += ele;
  }
  while (cost[h[u]] > m) cost[h[u]] -= heap[h[u]].top(); heap[h[u]].pop();
  ans = max(ans, (long long)heap[h[u]].size() * l[u]);
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    int b; cin >> b >> c[i] >> l[i];
    if (b == 0) root = i;
    g[b].push_back(i);
  }
  cout << dfs(root, 0);
  return 0;
}