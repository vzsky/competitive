#include<bits/stdc++.h>
using namespace std;

long long a[100100], s[100100], o[100100];

int main () {
  int t; cin >> t;
  while (t--) {
    long long n; cin >> n;
    for (int i = 1; i <= n; i++) {
      o[i] = 0;
    }
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      if (a[i] & 1) o[i]++;
      o[i] += o[i-1];
      s[i] = a[i] + s[i-1];
    }

    cout << s[1] << ' ';

    for (int i = 2; i <= n; i++) {
      long long m = ((o[i]-1) / 3) + ((o[i] % 3)!=2);
      if (o[i] == 0) m = 0;
      // cout << o[i] << ' ' << m << endl;

      cout << s[i] - m << ' ';

    } cout << '\n';
    
  }
  return 0;
}
