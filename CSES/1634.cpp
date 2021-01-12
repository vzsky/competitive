#include<bits/stdc++.h>
using namespace std;

int n;
int c[110];
int a[1000100];
int solve (int x) {
  if (x < 0) return 1e9;
  if (x == 0) return 0;
  if (a[x]) return a[x];
  int mn = 1e9;
  for (int i = 0; i < n; i++) {
    mn = min(mn, solve(x-c[i]));
  }
  return a[x] = mn+1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int x;
  cin >> n >> x;
  for (int i = 0; i < n; i++) {
    cin >> c[i];
  }

  int ans = solve(x);
  cout << (ans > 1e9? -1:ans);
  return 0;
}