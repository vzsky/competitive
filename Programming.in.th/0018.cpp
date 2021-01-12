#include<bits/stdc++.h>
using namespace std;

int m[1010];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k, cnt=0; cin >> n >> k;
  for (int i = 2; i <= n; i++) {
    if (m[i]) continue;
    for (int j = i; j <= n; j+=i) {
      if (m[j]) continue;
      m[j] = 1;
      if (++cnt == k) {
        cout << j << endl;
        return 0;
      }
    }
  }
  assert(false); return 0;
}