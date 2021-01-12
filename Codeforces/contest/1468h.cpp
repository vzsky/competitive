#include<bits/stdc++.h>
using namespace std;

int b[200100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, k, m;
    cin >> n >> k >> m;
    int h = k/2;

    for (int i = 0; i < m; i++) cin >> b[i];

    if ((n-m) % (k-1) != 0) {
      cout << "NO" << endl; 
      goto next;
    }

    for (int i = 0; i < m; i++) {
      if (i != 0 and b[i] <= b[i-1]) {
        cout << "NO" << endl;
        goto next;
      }
    }

    for (int i = 0; i < m; i++) {
      int left = b[i]-1-i;
      int right = n-b[i] - (m-i-1);
      // cout << left << ' h' << right << endl;
      if (left >= h and right >= h) {
        cout << "YES" << endl;
        goto next;
      }
    }
    cout << "NO" << endl;
    next : continue;
  }
  return 0;
}