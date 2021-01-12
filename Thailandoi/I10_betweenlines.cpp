#include<bits/stdc++.h>
using namespace std;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, w = 1, u = 1, m = 1, a = 0, b; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> b;
    u += (b == 10);
    m += (b == 13);
    w += (b == 10 and a == 13);
    a = b;
  }
  cout << w << ' ' << u << ' ' << m;
  return 0;
}