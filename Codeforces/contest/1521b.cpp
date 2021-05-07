#include<bits/stdc++.h>
using namespace std;

int p = 1e9+7;
int a[200100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  while (n--) {
    int k; cin >> k;
    cout << k/2 << endl;
    for (int i = 1; i <= k; i++) {
      cin >> a[i];
      if (i%2==0) {
        cout << 1 << ' ' << i << ' ' << min(a[1], a[i]) << ' ' << p << endl;
        a[1] = min(a[1], a[i]);
      }
    }
  }
  return 0;
}