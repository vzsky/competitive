#include<bits/stdc++.h>
using namespace std;

int main () {
  string s;
  cin >> s;
  int n = s.size();

  for (int i = 0; i < n; i++) {
    cout << (i % 3 == 2 ? "..*." : "..#.");
  } cout << ".\n";

  for (int i = 0; i < n; i++) {
    cout << (i % 3 == 2 ? ".*.*" : ".#.#");
  } cout << ".\n";

  for (int i = 0; i < n; i++) {
    if (i != 0 && i % 3 != 1) cout << "*." << s[i] << ".";
    else cout << "#." << s[i] << ".";
  }
  cout << (n % 3 == 0 ? "*" : "#") << "\n";

  for (int i = 0; i < n; i++) {
    cout << (i % 3 == 2 ? ".*.*" : ".#.#");
  } cout << ".\n";

  for (int i = 0; i < n; i++) {
    cout << (i % 3 == 2 ? "..*." : "..#.");
  } cout << ".\n";

  return 0;
}
