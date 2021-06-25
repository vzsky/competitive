#include<bits/stdc++.h>
using namespace std;

int ans[5000010];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  int cnt = 0, cnt2 = 0, now = 0;
  for (int i = 0; i < n; i++) {
    char c; cin >> c;
    if (c == '(') cnt++;
    if (c == ')') cnt--;
    if (c == ']') cnt--;
    if (cnt < 0) {cout << 0; return 0;}
  }
  for (int i = 1; i <= m; i++) cout << 1 << '\n';
  cout << 1+cnt << endl;
  return 0;
}
