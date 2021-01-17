#include<bits/stdc++.h>
using namespace std;

void tile (int t, int c, int x, int y) {
  cout << t << ' ' << c << ' ' << x << ' ' << y << '\n';
}

void solve (int n, int X, int Y, int x, int y) {
  if (n == 1) return tile((((Y-1)<<1)+(X-1))+1, (((x+y)/2)&1) + 2, 1+x, 1+y);

  int h = 1<<(n-1);
  int in = ((Y > h) << 1) + (X > h);

  if (in == 0)  solve(n-1, X, Y, x, y);
  else          solve(n-1, h, h, x, y);
  if (in == 1)  solve(n-1, X-h, Y, x+h, y);
  else          solve(n-1, 1, h, x+h, y);
  if (in == 2)  solve(n-1, X, Y-h, x, y+h);
  else          solve(n-1, h, 1, x, y+h);
  if (in == 3)  solve(n-1, X-h, Y-h, x+h, y+h);
  else          solve(n-1, 1, 1, x+h, y+h);

  tile(in+1, 1, h+x, h+y);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, x, y; cin >> n >> x >> y;
  solve(n, x, y, 0, 0);
  return 0;
}