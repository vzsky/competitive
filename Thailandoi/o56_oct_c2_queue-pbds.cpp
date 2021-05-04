#include<bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template<typename T> using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

int priOf[200100];
int rev[200100];

ordered_set<int> tr;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int cnt = 1, m; cin >> m;
  while (m--) {
    int c; cin >> c;
    if (c == 1) {
      int p; cin >> p;
      priOf[cnt] = p; rev[p] = cnt;
      tr.insert(p);
      cnt++;
    }
    if (c == 2) {
      auto lq = *tr.begin();
      cout << (lq?rev[lq]:0) << '\n';
      tr.erase(tr.begin());
    }
    if (c == 3) {
      int p; cin >> p;
      cout << tr.order_of_key(priOf[p]) << '\n';
    }
  }
  
  return 0;
}