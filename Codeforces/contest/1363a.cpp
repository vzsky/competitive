#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int odd = 0, eve = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (a & 1) odd++;
      else eve++;
    }
    bool flag = false;
    for (int i = 0; i <= x; i++) {
        if (i & 1 and i <= odd and x-i <= eve) flag = true;
    }
    cout << (flag?"Yes":"No") << endl;
  }
  return 0;
}