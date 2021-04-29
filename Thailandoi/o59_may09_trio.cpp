#include<bits/stdc++.h>
using namespace std;

void print(int a, int b, int c) { cout << a << ' ' << b << ' ' << c << '\n'; }

bool solve (int n) {
  if (n == 2) { print(2, 1, 1); return true; }
  if (n == 6) {
    for (int i = 2; i <= 6; i+=2) print(i, i-1, 1);
    for (int i = 0; i <= 1; i++) print(6-i, 1+i, 1);
    print(3, 1, 2); print(6, 4, 4);
    return true;
  }
  if (n == 9) {
    for (int i = 2; i <= 6; i++) print(i, i-1, i&1?3:1);
    for (int i = 5; i <= 9; i++) print(i, i&1?1:3, i&1?1:3);
    for (int i = 4; i <= 8; i++) print(i&1?7:9, i, i&1?3:1);
    return true;
  }
  if (n&1 and n%3 == 0) {
    if (solve(n-4)) {
      for (int i = 1; i <= 3; i++) print(n-i+1, i, 1);
      print(n-3, 5, 3); print(n-3, 1, 2); print(n, 4, 4);
      for (int i = 5; i < n-4; i+=3) { print(n, i, 1); print(n-2, i+1, 1); }
      for (int i = 7; i < n-4; i+=3) { print(n-1, i, 3); print(n-3, i+1, 3); }
      print(n, n-4, 1);
      for (int i = 1; i <= 3; i++) print(n-i+1, n-i, i&1?1:3);
      return true;
    }
    return false;
  }
  if (n % 2 == 0 and n % 3 == 0) {
    if (solve(n-3)) {
      for (int i = 1; i <= n; i+=2) print(n, i, 1);
      for (int i = 2; i < n; i+= 2) print(n-2, i, 3);
      return true;
    }
    return false;
  }
  if (n % 3 == 2) {
    if (solve(n-2)) {
      for (int i = 1; i <= n; i+=3) print(n, i, 1);
      for (int i = 3; i <= n; i+=3) print(n-1, i, 3);
      return true;
    }
    return false;
  }
  cout << "NO";
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  solve(n);
  return 0;
}