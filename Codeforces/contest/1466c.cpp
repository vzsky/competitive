#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    cin >> s;
    int ans = 0;
    if (s[0] == s[1]) { ans++; s[1] = 'A'; }
    for (int i = 2; i < s.size(); i++) {
      if (s[i-2] == s[i]) { ans++; s[i] = s[i-1] =='A'? 'B':'A';}
      if (s[i-1] == s[i]) { ans++; s[i] = s[i-1] =='A'? 'B':'A';}
    }
    cout << ans << endl;
  }
  return 0;
}