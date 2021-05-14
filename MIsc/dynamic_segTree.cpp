#include<bits/stdc++.h>
using namespace std;

const int n = 1e9; // boundary of key for segtree
const int iden = -1e9; // identity of max function is -inf

struct node {
  int val;
  node *l, *r;
  node (int v) { val = v; }
};
int val (node * t) { return t?t->val:iden; }

node * seg = NULL;

void update (int a, int v, int l = 1, int r = n, node *& now = seg) {
  if (a < l or r < a) return;
  if (l == r) return void (now = new node(v));
  int mid = (l+r)/2;
  if (!now) now = new node (0);
  update (a, v, l, mid, now->l);
  update (a, v, mid+1, r, now->r);
  now->val = max(val(now->l), val(now->r));
}

int query (int a, int b, int l = 1, int r = n, node * now = seg) {
  if (b < l or r < a or !now) return iden;
  if (a <= l and r <= b) return val(now);
  int mid = (l+r)/2;
  return max(query(a, b, l, mid, now->l), query(a, b, mid+1, r, now->r));
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int q; cin >> q;
  while (q--) {
    int t, a, b; cin >> t >> a >> b;
    if (t == 0) update(a, b);
    if (t == 1) cout << query(a, b) << endl;
  }
  // runtime O(qlogn)
  return 0;
}