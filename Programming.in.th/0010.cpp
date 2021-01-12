#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  string s;
  cin >> s;
  int st = 1;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] == 'A' and st != 3) { st ^= 3; }
    if (s[i] == 'B' and st != 1) { st ^= 1; }
    if (s[i] == 'C' and st != 2) { st ^= 2; }
  }
  cout << st;
  return 0;
}