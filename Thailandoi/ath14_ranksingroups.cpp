#include<bits/stdc++.h>
using namespace std;

// include the g++ stl for ordered_set datastructure
// This (randomized) can also be acheived using treap :/
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int dsu[100100], sz[100100];
ordered_set<int> p[100100]; // supports order of key
int find (int u) { return u==dsu[u]? u : dsu[u] = find(dsu[u]); }

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, l; cin >> n >> l;
    for (int i = 1; i <= n; i++) {
      p[i].clear(); p[i].insert(i);
      dsu[i] = i; sz[i] = 1;
    }
    for (int i = 0; i < l; i++) {
      int k; cin >> k;
      if (k == 1) {
        int x, y; cin >> x >> y; // merge 
        x = find(x); y = find(y);
        if (sz[x] > sz[y]) swap(x, y); // y > x
        sz[y] += sz[x]; dsu[x] = y;
        for (auto ele : p[x]) p[y].insert(ele);
      }
      if (k == 2) {
        int x; cin >> x; // rank of x in their group
        int ans = sz[find(x)] - p[find(x)].order_of_key(x);
        cout << ans << '\n';
      }
    }
  }
  return 0;
}