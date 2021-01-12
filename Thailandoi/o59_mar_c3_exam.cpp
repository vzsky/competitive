#include<bits/stdc++.h>
using namespace std;

struct A {
  int l, r, val;
};

A seg[1000100];

int tot = 0;
int clone (int n) {
  seg[++tot] = seg[n];
  return tot;
}

int update (int now, int a, int l = 0, int r = 50000) {
  if (l > a or a > r) return now;
  if (l == r) {
    // cerr << "add " << a << endl;
    int nw = clone(now);
    seg[nw].val += 1;
    return nw;
  }
  int nw = clone(now);
  int mid = (l+r)/2;
  seg[nw].l = update(seg[now].l, a, l, mid);
  seg[nw].r = update(seg[now].r, a, mid+1, r);
  seg[nw].val = seg[seg[nw].l].val + seg[seg[nw].r].val;
  return nw;
}

int query (int now, int a, int b = 50000, int l = 0, int r = 50000) { // sum e >= a
  if (l > b or r < a) return 0;
  if (a <= l and r <= b) return seg[now].val;
  int mid = (l+r)/2;
  return query(seg[now].l, a, b, l, mid) + query(seg[now].r, a, b, mid+1, r);
}

int a[50100];
map<int,int> last;
int s[50100];
int root[50100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  root[0] = 0;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    s[i] = last[a[i]];
    last[a[i]] = i;
    root[i] = update(root[i-1], s[i]);
  }
  int q;
  cin >> q;
  while (q--) {
    int u, v;
    cin >> u >> v;
    u++; v++;
    // cerr << "u" << u << "v" << v << endl;
    // cerr << "q " << query(root[u-1], u) << ' ' << query(root[v], u) << endl;
    cout << query(root[v], u) - query(root[u-1], u) << '\n';
  }
  return 0;
}