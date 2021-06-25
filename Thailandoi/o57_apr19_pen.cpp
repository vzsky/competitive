#include<bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()

struct A {
  int x1, x2, y, i;
  bool operator < (const A & o) const { return y < o.y; }
};
vector<A> q;

vector<double> cod;
int sz;
int get (double x) { return lower_bound(all(cod), x)-cod.begin()+1; }
int ans[100100];

int seg[1200100], laz[1200100];
void push (int now, int l, int r) {
  if (!laz[now]) return;
  seg[now] = laz[now];
  if (l != r) {
    laz[now*2] = laz[now];
    laz[now*2+1] = laz[now];
  }
  laz[now] = 0;
}

void update (int a, int b, int v, int l = 1, int r = sz, int now = 1) {
  push(now, l, r);
  if (b < l or r < a) return;
  if (a <= l and r <= b) {
    laz[now] = v; push(now, l, r);
    return;
  }
  int mid = l+r>>1;
  update(a, b, v, l, mid, now*2); update(a, b, v, mid+1, r, now*2+1);
}

int query (int a, int l = 1, int r = sz, int now = 1) {
  // cerr << l << ' ' << r << endl;
  push(now, l, r);
  if (a < l or r < a) return -1;
  if (l == r) {
    // cerr << l << ' ' << r << ' ' << seg[now] << endl;
    return seg[now];
  }
  int mid = l+r>>1;
  return max(query(a, l, mid, now*2), query(a, mid+1, r, now*2+1));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int x1, x2, y; cin >> x1 >> x2 >> y;
    cod.push_back(x1); cod.push_back(x2-1); cod.push_back(x2-0.5);
    q.push_back({x1, x2, y, i});
  }
  sort(all(cod)); cod.resize(unique(all(cod))-cod.begin());
  sz = cod.size();
  sort(all(q));
  for (auto [x1, x2, y, i] : q) {
    // cerr << "querying " <<  get(x2-0.5) << endl;
    ans[i] = query(get(x2-0.5)) + 1;
    update(get(x1), get(x2-1), ans[i]);
  }
  for (int i = 1; i <= n; i++) cout << ans[i] << '\n';
  return 0;
}
/* POSSIBLE BUGS
edges
*/
/* TESTCASE
3
10 20 30
5 15 20
15 30 10
*/