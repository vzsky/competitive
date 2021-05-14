#include<bits/stdc++.h>
using namespace std;

struct node {
  int pri, val, laz;
  node * l, * r; 
  node (int v) { val = v; pri = rand(); laz = 0; }
};

void push (node * t) {
  if (!t) return;
  t->val += t->laz;
  if (t->l) t->l->laz += t->laz;
  if (t->r) t->r->laz += t->laz;
  t->laz = 0;
}

void merge (node *& t, node * l, node * r) {
  push(l); push(r);
  if (!l or !r) return void (t=l?l:r);
  if (l->pri < r->pri) merge(l->r, l->r, r), t=l;
  else merge(r->l, l, r->l), t=r;
}

void split (node * t, node *& l, node *&r, int val) {
  push(t);
  if (!t) return void(l=r=NULL);
  if (t->val <= val) split(t->r, t->r, r, val), l=t;
  else split(t->l, l, t->l, val), r=t;
}

bool find (node * t, int val) {
  bool ret = 0;
  node *l, *m, *r;
  split(t, l, r, val);
  split(l, l, m, val-1);
  if (m) ret = 1;
  merge(l, l, m);
  merge(t, l, r);
  return ret;
}

int main(){
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  node * treap = NULL;
  int n, q; cin >> n >> q;
  for (int i = 0; i < n; i++) {
    int a; cin >> a;
    merge(treap, treap, new node(a));
  }
  for (int i = 0; i < q; i++) {
    int t, x, b, c; cin >> t;
    if (t == 1) {
      cin >> x;
      cout << find(treap, x) << '\n';
    }
    if (t == 2) {
      cin >> x >> b >> c;
      if (!find(treap, x)) continue;
      node *l, *r;
      split(treap, l, r, x-1);
      if (l) l->laz += b;
      if (r) r->laz += c;
      merge(treap, r, l);
    }
  }
  return 0;
}