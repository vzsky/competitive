#include<bits/stdc++.h>
using namespace std;

string s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> s;
  bool B = false, S = false;
  for (int i = 0; i < s.size(); i++) {
    if (s[i] >= 'A' and s[i] <= 'Z') B = true;
    if (s[i] >= 'a' and s[i] <= 'z') S = true;
  }
  if (B&S) cout << "Mix";
  else if (B) cout << "All Capital Letter";
  else if (S) cout << "All Small Letter";
  else cout << "DUMB";
  return 0;
}