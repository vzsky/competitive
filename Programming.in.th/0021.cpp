#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  string s; getline(cin,s);
  vector<char> a;
  for (int i = 0; i < s.size(); i++) {
    for (auto v : {'a', 'e', 'i', 'o', 'u'})
      if (i+2 < s.size() and s[i] == v and s[i+2] == v and s[i+1] == 'p') {a.push_back(s[i]); i += 2; goto next;}
    a.push_back(s[i]);
    next : continue;
  }
  for (auto x : a) cout << x;
  return 0;
}