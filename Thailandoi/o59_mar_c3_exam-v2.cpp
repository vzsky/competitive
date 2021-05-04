#include<bits/stdc++.h>
using namespace std;

int n, a[50100], ls[50100], root[50100];
map<int,int> m;

struct node {
  int l, r, val;
} seg[800100];

int tot = 1;
int newnode () { 
  ++tot;
  seg[tot] = {0, 0, 0};
  return tot;
}

int update (int now, int ind, int l = 1, int r = n) {
  if (ind < l or ind > r) return now;
  if (l == r) {
    int nw = newnode();
    seg[nw].val = 1;
    return nw;
  }
  int nw = newnode();
  int mid = (l+r)/2;
  seg[nw].l = update(seg[now].l, ind, l, mid);
  seg[nw].r = update(seg[now].r, ind, mid+1, r);
  seg[nw].val = seg[seg[nw].l].val + seg[seg[nw].r].val;
  return nw;
}

int query (int now, int a, int b = n, int l = 1, int r = n) {
  if (r < a or b < l) return 0;
  if (a <= l and r <= b) return seg[now].val;
  int mid = (l+r)/2;
  return query(seg[now].l, a, b, l, mid) + query(seg[now].r, a, b, mid+1, r);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> a[i]; 
    ls[i] = m[a[i]];
    m[a[i]] = i;
  }
  root[0] = 1;
  for (int v = 1; v <= n; v++) {
    root[v] = update(root[v-1], ls[v]);
  }
  int q; cin >> q;
  while (q--) {
    int l, r; cin >> l >> r; l++; r++;
    cout << query(root[r], l) - query(root[l-1], l) << '\n';
  }
  return 0;
}