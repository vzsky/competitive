#include<bits/stdc++.h>
using namespace std;

pair<int,int> a[100100];
int ans[100100];



priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> heap;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, m, x; cin >> n >> m >> x;
    for (int i = 1; i <= m; i++) {
      heap.push({0, i});
    }
    for (int i = 0; i < n; i++){
      cin >> a[i].first;
      a[i].second = i;
    } 
      
    sort(a, a+n, greater<pair<int,int>>());
    for (int i = 0; i < n; i++) {
      auto t = heap.top(); heap.pop();
      heap.push({t.first+a[i].first, t.second});
      ans[a[i].second] = t.second;
    }
    int mx = 0, mn = 1e9;
    while (!heap.empty()) {
      auto t = heap.top(); heap.pop();
      mx = max(mx, t.first);
      mn = min(mn, t.first);
    }
    // cerr << "mx"  << mx << ' ' <<mn <<endl;
    if (mx-mn <= x) {
      cout << "YES" << endl;
      for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
      }cout <<endl;
    }else {
      cout << "NO" << endl;
    }
  }
  return 0;
}