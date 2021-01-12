#include<bits/stdc++.h>
using namespace std;

vector<int> g[1010];

// int dfs (int u, int p) {
//   int z = 1;
//   for (auto x : g[u]) {
//     if (x == p) continue;
//     z += dfs(x, u);
//   }
//   return z;
// }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;

    for (int i = 1; i <= n; i++) {
      g[i].clear();
    }

    for (int i = 0; i < n-1; i++) {
      int a, b;
      cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    if (g[x].size() <= 1) cout << "Ayush" << endl;
    else if (n & 1) cout << "Ashish" << endl;
    else cout << "Ayush" << endl;
  }
  return 0;
}