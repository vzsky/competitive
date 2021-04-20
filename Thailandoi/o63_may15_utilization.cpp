#include<bits/stdc++.h>
using namespace std;

struct A {
  long long slope, len;
  bool operator < (const A & o) const {
    return slope < o.slope;
  }
};
priority_queue<A> heap;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long m, n, k; cin >> m >> n >> k;
  for (int i = 0; i < n; i++) {
    int l; cin >> l;
    long long pm = k;
    long long last = 0;
    for (int j = 0; j < l; j++) {
      long long x, p; cin >> x >> p;
      heap.push({pm, x-last});
      pm -= p; last = x;
    }
  }
  long long ans = 0;
  while(m>=0 and !heap.empty()) {
    auto [slope, len] = heap.top(); heap.pop();
    if(len>=m){ ans+=slope*m; break; }
    ans+=slope*len;
    m-=len;
  }
  // cout << ((double)ans)/k; can't use cout or else WA.
  printf("%f", ((double)ans)/k);
  return 0;
}