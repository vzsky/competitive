#include <bits/stdc++.h>
using namespace std;

int main() {
  int r; cin >> r;
  for (int i = 0; i < r; i++) {
    for (int j = 0; j < r - !(r&1); j++) {
      if (i + j == (r-1)/2 or i + j == (3*r-3)/2 or j - i == (r-1)/2 or i - j == r/2) cout << '*';
      else cout << '-';
    } cout << endl;
  }
  return 0;
}