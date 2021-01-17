#include<bits/stdc++.h>
using namespace std;

bool g = true;

string gcd (string a, string b) {
  // cerr << a << ' '  << b << endl;
  if (a.size() < b.size()) swap (a, b); // b < a
  if (b == "") return a;
  int l = b.size();
  for (int i = 0; i < l; i++) {
    if (a[i] != b[i]) {
      g = false;
      return "";
    }
  }
  string c = "";
  for (int i = l; i < a.size(); i++) {
    c.push_back(a[i]);
  }
  return gcd (c, b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    string a, b; cin >> a >> b;
    g = true;
    int s = gcd(a, b).size();
    if (!g) {
      cout << "-1" << endl; 
      continue;
    }
    int ll = (a.size() * b.size() / s);
    if (a.size() < b.size()) swap(a, b); // b < a
    for (int i = 0; i < (ll/b.size()); i++) {
      cout << b;
    }
    cout << endl;
  }
  return 0;
}