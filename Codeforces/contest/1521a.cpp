#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  while (n--) {
    long long a, b; cin >> a >> b;
    if (b == 1) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    if (b <= 2) {
      cout << a << ' ' << a*3<< ' ' << a*4 << endl;
      continue;
    }
    cout << a << ' ' << a*(b-1) << ' ' << a*b << endl;
  }
  return 0;
}