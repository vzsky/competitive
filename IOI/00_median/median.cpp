// need ternary search insertion sorting and optimization ;-; 
#include<bits/stdc++.h>
#include "device.h"
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n = GetN();
  int first = Med3(1, 2, 3);
  vector<int> a;
  a.push_back(((first+1) % 3) + 1);
  a.push_back(first);
  a.push_back(1^2^3^first^((first+1) % 3) + 1);

  for (int i = 4; i <= n; i++) {
    int l = 0, r = a.size()-1;
    while (l < r) {
      int mid = (l+r)/2;
      int res = Med3(a.back(), i, a[mid]);
      // cerr << a.back() << ' ' <<  i << ' ' << a[mid] << ' ' << res << endl;
      if (res == a.back()) {
        a.push_back(i);
        goto next;
      }
      if (res == i) l = mid+1;
      else r = mid;
    }
    // l is the index that will be push back
    a.insert(a.begin()+l, i);
    next:
    // cerr << "now a "; for (auto x : a) cerr << x << ' '; cerr << endl;
    continue;
  }
  Answer(a[(n/2)]);
  return 0;
}