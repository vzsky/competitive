#include<bits/stdc++.h>
using namespace std;

struct A {
  long long x, y, i;
  bool operator < (const A & o) const {
    return (x+y == o.x+o.y)? i < o.i : x+y < o.x+o.y;
  }
};

vector<A> v;
long long ans[100100];

bool in (A a, A b) {
  // return if a in b
  if ((a.y >= b.y) and (abs(a.x-b.x) < a.y - b.y)) return true;
  if ((a.i > b.i) and (a.y >= b.y) and (abs(a.x-b.x) <= a.y - b.y)) return true;
  return false;
}

long long isect (A a, A b) {
  // intersection of a and b (where b cover a)
  if (in(b, a)) return -1;
  long long xtime2 = (b.y + b.x + a.x - a.y);
  if (xtime2&1) {
    if (a.i < b.i) return xtime2/2+1;
    if (b.i < a.i) return xtime2/2+1;
  }
  if (a.i < b.i) return xtime2/2+1;
  if (b.i < a.i) return xtime2/2;
  return -1;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  long long n, l; cin >> n >> l;
  for (int i = 0; i < n; i++) {
    long long x, y; cin >> x >> y;
    v.push_back({x, y+i, i});
  }
  sort(v.begin(), v.end());
  ans[v[0].i] += v[0].x+1;
  A last = v[0];
  long long first = v[0].x+1;

  for (int i = 1; i < n; i++) {
    if (in(v[i], last)) continue;
    long long is = isect(last, v[i]);
    // cerr << is << endl;
    ans[last.i] += is-first;
    ans[v[i].i] += v[i].x-is+1;
    first = v[i].x+1;
    last = v[i];
  }

  ans[last.i] += l-first+1;

  long long sum = 0;
  for (int i = 0; i < n; i++) {
    cout << ans[i] << endl;
    sum += ans[i];
  }
  assert(sum == l+1);
  return 0;
}