#include<bits/stdc++.h>
using namespace std; 

int main () {

  int x, y; 
  cin >> x >> y;
  if (x > y) cout << 2;
  cout << (y + x - 1) / x << "\n";

  return 0;
}
