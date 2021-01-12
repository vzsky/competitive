#include<bits/stdc++.h>
using namespace std;

struct A { int t, u, tm; };
vector<A> g[300100];
int logans[300100];
int p[300100];
int n, m;

const int mod = 1e9+7;
int find (int u) { return u == p[u] ? u : p[u] = find(p[u]); }
long long pow (int n) {
  if (n == 1) return 2;
  if (n&1) return (2 * ((pow(n/2) * pow(n/2)) % mod)) % mod;
  return (pow(n/2) * pow(n/2)) % mod;
}

int visited[300100];
bool isBipartite (int v, int time, int col = 1) {
  if (visited[v] != 0) {
    return (col == visited[v]);
  }
  visited[v] = col;
  for (auto x : g[v]) {
    if (x.tm > time) continue;
    if (!isBipartite(x.u, time, x.t?-col:col)) return false;
  }
  return true;
}

bool valid (int time) {
  memset(visited, 0, sizeof visited);
  for (int i = 1; i <= n; i++) {
    if (!visited[i]) {
      if (!isBipartite(i, time)) return false;
    }
  }
  return true;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> m;
  int cm = n;
  iota(p, p+n+1, 0);
  for (int i = 0; i < m; i++) {
    int a, b, t;
    cin >> t >> a >> b;
    g[a].push_back({t ^ 1, b, i});
    g[b].push_back({t ^ 1, a, i});
    if (find(a) != find(b)) {
      p[find(a)] = find(b); cm--;
    }
    logans[i] = cm;
  }

  int l = 0, r = m;
  while (l < r) {
    int mid = (l+r)/2;
    if (valid(mid)) l = mid+1;
    else r = mid;
  }
  // cerr << "first that is invalid is " <<  l << endl;

  for (int i = 0; i < m; i++) 
    cout << ((i >= l)? 0 : pow(logans[i])) << '\n';
  return 0;
}