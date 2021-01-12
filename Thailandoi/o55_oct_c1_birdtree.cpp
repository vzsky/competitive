#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    string s; cin >> s;
    int a = 0, b = 0, op = 0;
    bool first = true;
    for (int i = 0; i < s.size(); i++) {
      if (s[i] == '/') {first = false; continue;}
      if (first) a = a*10 + s[i] - '0';
      if (!first) b = b*10 + s[i] - '0';
    }
    char o[] = {'R', 'L'};
    while (a != 1 or b != 1) {
      op^=1;
      if (a < b) { b -= a; cout << o[op]; }
      else { a -= b; cout << o[op^1]; }
    }
    cout << endl;
  }
  return 0;
}