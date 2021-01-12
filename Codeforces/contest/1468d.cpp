#include<bits/stdc++.h>
using namespace std;

priority_queue<int> h;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {

    while(!h.empty()) h.pop();

    int n, m, a, b; cin >> n >> m >> a >> b;
    int tim;
    int deploytime = abs(b-a)-1;
    if (a < b) tim = b-1;
    else tim = n-b;

    bool haveone = false;

    for (int i = 1; i <= m; i++) {
      int f; cin >> f;
      h.push(f);
      if (f == 1) haveone = true;
    }

    int ans = 0;
    for (int i = 1; i <= deploytime;) {
      if (h.empty()) break;
      auto t = h.top(); h.pop();
      if (t+i <= tim) {
        ans++;
        i++;
      }
    }
    // if (haveone && !h.empty() && h.top() >= 1) ans++;
    cout << ans << endl;
  }

  return 0;
}