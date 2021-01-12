#include<bits/stdc++.h>
using namespace std;

const long long inf = 1e10;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n1, n2, n3; cin >> n1 >> n2 >> n3;
  long long m[4] = {inf, inf, inf, inf};
  long long s[4] = {0, 0, 0, 0}; 
  for (int i = 0; i < n1; i++) {
    long long a; cin >> a;
    m[1] = min(m[1], a);
    s[1] += a;
  }
  for (int i = 0; i < n2; i++) {
    long long a; cin >> a;
    m[2] = min(m[2], a);
    s[2] += a;
  }
  for (int i = 0; i < n3; i++) {
    long long a; cin >> a;
    m[3] = min(m[3], a);
    s[3] += a;
  }

  // cout << m[1] << ' ' << m[2] << ' ' << m[3] << ' ' << s[1] << ' ' << s[2] << ' ' << s[3] << endl;

  long long c1 = m[1]+m[2]+m[3] - max(max(m[1], m[2]), m[3]);
  long long c2 = min(s[1], min(s[2], s[3]));
  // cout << c1 << ' ' << c2 << endl;
  // cout << min(c1, c2) << endl;
  cout << s[1]+s[2]+s[3] - 2*min(c1, c2) << endl;
  return 0;
}