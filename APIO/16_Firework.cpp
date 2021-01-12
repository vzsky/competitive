#include<bits/stdc++.h>
using namespace std;
 
struct slope {
  priority_queue<long long> cp;
  long long initslope;
  long long inity;
  slope () {
    cp = priority_queue<long long>();
    initslope = 0;
    inity = 0;
  }
};
 
void merge (slope &a, slope &b) {
  if (a.cp.size() < b.cp.size()) swap(a, b);
  a.initslope += b.initslope;
  a.inity += b.inity;
  while (!b.cp.empty()) {
    a.cp.push(b.cp.top());
    b.cp.pop();
  }
}
 
vector<int> g[300100];
long long weight[300100];
 
slope dfs (int u) { // rightmost slope always 1
  slope now;
  if (g[u].size() == 0) {
    now.inity = weight[u];
    now.initslope = -1;
    now.cp.push(weight[u]);
    now.cp.push(weight[u]);
    return now;
  }
  for (auto x : g[u]) {
    slope child = dfs(x);
    merge(now, child);
  }
  // rightmost slope of now is g[u].size()
  for (int i = 1; i < g[u].size(); i++) now.cp.pop();
  // right most slope is now 1
  // shift graph with weight[u]
  now.inity += weight[u];
  auto a = now.cp.top(); now.cp.pop();
  auto b = now.cp.top(); now.cp.pop();
  now.cp.push(a+weight[u]);
  now.cp.push(b+weight[u]);
  return now;
}
 
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
 
  int n, m; cin >> n >> m;
  for (int i = 2; i <= n+m; i++) {
    int a, b; cin >> a >> b;
    g[a].push_back(i);
    weight[i] = b;
  }
 
  slope res = dfs(1);
  long long ans = res.inity;
  res.cp.pop();
  long long last = res.cp.top();
  res.cp.pop();
  int i = 1;
  while (!res.cp.empty()) {
    ans -= i*(last - res.cp.top());
    last = res.cp.top();
    res.cp.pop();
    i++;
  }
  ans -= i*last;
 
  cout << ans << endl;
  return 0;
}