#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

char in[200005];
set<pair<int,int>> g[200005];
set<int> s[200005];
ordered_set<pair<int,int>> treap;
int n, k, root = -1;
queue<long long> dq;
long long sum = 0, ans = 0;

void getans (int u, int p) {
  for (auto [x, d] : g[u]) if (x != p) {
    dq.push(d); sum += d;
    while (!dq.empty() and sum > k) {
      sum -= dq.front(); dq.pop();
    }
    ans += dq.size();
    getans(x, u);
  }
}

void dfs (int u, int p, int ind, int dis = 0) {
  if (dis > k) return;
  s[ind].insert(dis);
  for (auto [x, d] : g[u]) if (x != p) {
    dfs(x, u, ind, dis+d);
  }
}

// use treap -> RTE, use pbds -> AC
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i < n; i++) {
    int a, b, c; cin >> a >> b >> c;
    g[a].insert({b, c});
    g[b].insert({a, c});
    if (++in[a] > 2) root = a;
    if (++in[b] > 2) root = b;
  }

  if (root != -1) {
    int ind = 0, un = 0;
    for (auto [x, d] : g[root]) {
      dfs(x, root, ind, 0);
      while (!dq.empty()) dq.pop();
      dq.push(d); sum = d;
      if (sum > k) { sum -= dq.front(); dq.pop(); }
      ans += dq.size();
      getans(x, root);
      ind++;
    }
    ind = 0;
    for (auto [x, d] : g[root]) {
      for (auto a : s[ind]) ans += treap.order_of_key({k-a-d, un++});
      for (auto a : s[ind]) if (a+d < k) treap.insert({a+d, un++});
      ind++;
    }
    cout << ans;
  }
  else {
    for (int i = 1; i <= n; i++) if (in[i] == 1) {
      getans(1, 1); cout << ans;
      return 0;
    }
  }
  return 0;
}