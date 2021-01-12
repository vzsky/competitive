#include<bits/stdc++.h>
using namespace std;

int deg[100100];
int w[100100];
priority_queue<int> h;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    while (!h.empty()) { h.pop(); }
    int n; cin >> n;
    // cerr << "ee" << endl;
    long long sum = 0;
    for (int i = 1; i <= n; i++) { cin >> w[i]; deg[i] = 0; sum += w[i];}
    // cerr << "yy" << endl;
    for (int i = 0; i < n-1; i++) {
      int u, v; cin >> u >> v;
      deg[u]++; deg[v]++;
    }
    // cerr << "yay" << endl;
    for (int i = 1; i <= n; i++) {
      if (deg[i] > 1) {
        for (int j = 0; j < deg[i]-1; j++) {
          h.push(w[i]);
        }
      }
    }
    // cerr << "y" << endl;
    for (int i = 1; i < n; i++) {
      cout << sum << ' ';
      if (!h.empty()) {
        sum += h.top();
        h.pop();
      }
    }
    cout << endl;
  }
  return 0;
}