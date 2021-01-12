#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

vector<pair<int,int>> v;
set<pair<int,int>> s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    int x, y; cin >> x >> y;
    v.push_back({x, y});
  }
  sort(v.begin(), v.end());
  long long d2 = 1e18;
  int j = 0;
  for (int i = 0; i < n; i++){
    int d = sqrt(d2);
    while (v[i].x - v[j].x >= d) {
      s.erase({v[j].y, v[j].x});
      j++;
    }

    // make d^2 search area
    auto it1 = s.lower_bound({v[i].y - d, v[i].x});
    auto it2 = s.upper_bound({v[i].y + d, v[i].x});
    
    for (auto it = it1; it != it2; ++it) {
        // swap when insert.
        int dx = (v[i].x - it->y);
        int dy = (v[i].y - it->x);
        d2 = min(d2, 1ll * dx * dx + 1ll * dy * dy);      
    } 

    s.insert({v[i].y, v[i].x});
  }
  cout << d2 << endl;
  return 0;
}