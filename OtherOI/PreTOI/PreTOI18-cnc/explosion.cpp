#include<bits/stdc++.h>
using namespace std;

const long long N = 500050;
long long a[500100], fw[500100];

void add (long long ind, long long val) {
  for (long long i = ind; i <= N; i += (i&-i)) fw[i] += val;
}
long long query (long long ind) {
  long long ans = 0;
  for (long long i = ind; i > 0; i -= (i&-i)) ans += fw[i];
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, m, x, y; cin >> n >> m >> x >> y;
  for (int i = 1; i <= n; i++) cin >> a[i];
  long long l = 0, r = 1e9;
  while (l != r) {
    long long mid = (l+r)/2;
    for (int i = 1; i <= n; i++) {
      fw[i] = 0; add(i, a[i]-(mid*x)); add(i+1, -(a[i]-(mid*x)));
    }
    long long counter = mid;
    for (int i = 1; i <= n; i++) {
      if (counter < 0) break;
      if (query(i) > 0) {
        long long used = (query(i)+(y-x-1))/(y-x);
        counter -= used;
        add(i, -(used*(y-x)));
        add(i+m*2+1, (used*(y-x)));
      }
    }
    if (counter < 0) l = mid+1; // can not 
    else             r = mid;
  }
  cout << l << endl;
  return 0;
}
/* POSSIBLE BUGS

*/
/* TESTCASE

*/