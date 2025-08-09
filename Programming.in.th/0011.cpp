#include<bits/stdc++.h>
using namespace std;

bool check[50];
int main () {
  int ans = 0;
  for (int i = 0; i < 10; i++) {
    int x; cin >> x;
    if (! check[x % 42]) { ans++; check[x % 42] = 1; }
  }
  cout << ans;
  return 0;
}
