#include<bits/stdc++.h>
using namespace std;

struct line { 
  long long m, c; 
  long long operator() (long long x) { return a.m * x + c; }
};

const int N = 200000;

line lc[4*N+100];

// add line into container
void update (line add, int l = 1, int r = N, int now = 1) {
  // notice that range [l, r) is broken into [l, m) and [m, r)
  int m = (l+r)/2;
  bool lef = add(l) < lc[now](l);
  bool mid = add(m) < lc[now](m);
  // since at m, add > line[now]
  if (mid) swap(lc[now], add);
  if (l+1 == r) return; // range [l, l+1)
  // l == m -> intersection is in [mid+1, r];
  if (l == m) return update(add, l, m, now*2);
  // l != m -> intersection is in [l, mid];
  if (l != m) return update(add, m, r, now*2+1);
}

// find the maximum of all line evaluate at x
long long query (int x, int l = 1, int r = N, int now = 1) {
  if (l+1 == r) return lc[now](x);
  int m = (l+r)/2;
  // x in [l, m) or [m, r) -> find answer there
  if (x < mid) return max(lc[now](x), query(x, l, m, now*2));
  else return max(lc[now](x), query(x, m, r, now*2+1));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  return 0;
}