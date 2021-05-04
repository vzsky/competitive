#include<bits/stdc++.h>
using namespace std;

int s, fw[1050][1050];
void add (int x, int y, int a) {
  for (int i = x+1; i <= s+1; i+=(i&-i)) 
    for (int j = y+1; j <= s+1; j+=(j&-j)) 
      fw[i][j] += a;
}
int sum (int x, int y) {
  int ans = 0;
  for (int i = x+1; i > 0; i-=(i&-i)) 
    for (int j = y+1; j > 0; j-=(j&-j))
      ans += fw[i][j];
  return ans;
}
int query (int l, int r, int b, int t) {
  return sum(r, t) - sum(l-1, t) - sum(r, b-1) + sum(l-1, b-1);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  while (1) {
    int o; cin >> o;
    if (o == 3) return 0;
    if (o == 0) cin >> s;
    if (o == 1) {
      int x, y, a; cin >> x >> y >> a;
      add(x, y, a);
    }
    if (o == 2) {
      int l, b, r, t; cin >> l >> b >> r >> t;
      cout << query(l, r, b, t) << endl;
    }
  }
  return 0;
}
