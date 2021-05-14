#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; cin >> s;
  int cnt = 0, mx = 0; char last = '0';
  for (int i = 0; i < s.size(); i++) {
    if (last == s[i]) cnt++;
    else cnt = 1;
    last = s[i];
    mx = max(mx, cnt);
  } cout << mx << endl;
  return 0;
}