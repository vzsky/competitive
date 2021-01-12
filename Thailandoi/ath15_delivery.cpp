#include<bits/stdc++.h>
using namespace std;

int w[100100], c[100100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> w[i] >> c[i]; 
    int l = 1, r = 5e8;
    while (l < r) {
      int mid = (l+r)/2;
      int cnt = 1;
      int sum = 0;
      set<int> s;
      for (int i = 0; i < n; i++) {
        if (w[i] > mid) { cnt = k+1; break; }
        if (s.find(c[i]) != s.end() or sum+w[i] > mid){
          cnt++;
          s.clear();
          s.insert(c[i]);
          sum = w[i];
        }
        else {
          s.insert(c[i]);
          sum += w[i];
        }
      }
      if (cnt <= k) r = mid;
      else l = mid+1;
    }
    cout << (l == 5e8? -1: l) << endl;
  }
  return 0;
}