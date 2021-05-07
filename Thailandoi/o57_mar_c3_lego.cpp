#include<bits/stdc++.h>
using namespace std;

int a[100100];

struct node {
  int a, pri, sz;
  node * l, * r;
  node (int v) {
    a = v; pri = rand(); sz = 1;
  }
};
int sz (node * t) { return t?t->sz:0; }
void upd (node * t) { 
  if (t) t->sz = 1+sz(t->l)+sz(t->r);
}

void merge (node *& t, node * l, node * r) {
  if (!l or !r) return void (t=l?l:r);
  if (l->pri < r->pri) merge(l->r, l->r, r), t=l;
  else merge (r->l, l, r->l), t=r;
  upd(t);
}

void split (node * t, node *&l, node *& r, int at) {
  if (!t) return void(l=r=NULL);
  if (sz(t->l) >= at) split(t->l, l, t->l, at), r=t;
  else split(t->r, t->r, r, at-sz(t->l)-1), l=t;
  upd(t);
}

int main(){
  srand(1);
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  node * t = NULL;
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    cin >> a[i];
    merge(t, t, new node(a[i]));
  }
  while (m--) {
    int o; cin >> o;
    if (o == 1) {
      int x, len, bb; cin >> x >> len >> bb;
      node *l, *m, *r, *b;
      if (bb > x+len-1) {
        split(t, l, b, bb-1);
        split(l, l, r, x-1);
        split(r, m, r, len);
        merge(t, m, b);
        merge(t, r, t);
        merge(t, l, t);
      }
      else {
        assert(bb < x);
        split(t, l, r, x-1);
        split(r, m, r, len);
        split(l, l, b, bb-1);
        merge(t, l, m);
        merge(t, t, b);
        merge(t, t, r);
      }
    }
    if (o == 2) {
      int x; cin >> x;
      node * l, * m, * r;
      split(t, l, r, x);
      split(l, l, m, x-1);
      assert(sz(m) == 1 and sz(m)+sz(l) == x);
      cout << m->a << '\n';
      merge(t, l, m);
      merge(t, t, r);
    }
  }
  return 0;
}