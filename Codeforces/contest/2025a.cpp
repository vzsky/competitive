#include<bits/stdc++.h>
using namespace std;

#define max(x, y) x>y?x:y
#define min(x, y) x<y?x:y

string s, t;

int main () {
  int q; cin >> q;
  while (q--) {
    cin >> s >> t;
    int n = max(s.size(), t.size());
    int ans = s.size() + t.size();
    int a = ans;
    for (int i = 0; i < n; i++) {
      if (s[i] == t[i]) ans--;
      else break;
    }
    cout << ((ans+1)<a?ans+1:a) << endl;
  }
  return 0;
}
