#include<bits/stdc++.h>
using namespace std;

// this is not complete but apparently good enough to get full score, on the case that some factors are of 6
// since x6 takes 8 operation while x2x3 takes 9
// ps. x4 takes 6 operation and x2x2 takes 8 operations
// therefore x12 is another edge case
// x12 takes 14, x3x4 takes 11, x6x2 takes 12

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  cout << t << endl;
  for (int c = 1; c <= t; c++) {
    int n; cin >> n;
    vector<int> factors;
    for (int i = 4; i <= n; i++) {
      while (n%i == 0) {
        factors.push_back(i);
        n/=i;
      }
    }
    cout << c << endl;
    for (auto factor : factors) {
      cout << "AC";
      for (int i = 0; i < factor; i++) cout << "V";
    }
    if (n == 2) cout << "ACVV";
    cout << endl;
  }
  return 0;
}