#include<bits/stdc++.h>
using namespace std;

vector<pair<pair<double,int>,int>> v;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    double n, m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
      int ve, t; cin >> ve >> t;
      v.push_back({{m*1000/ve+t, -ve}, i});
    }
    sort(v.begin(), v.end());
    for (auto x : v) cout << x.second << endl;
    v.clear();
  }
  return 0;
}