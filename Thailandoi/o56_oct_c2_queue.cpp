#include<bits/stdc++.h>
using namespace std;

struct node {
  int q, pri, sz;
  node * l, * r;
  node (int qq) {q = qq; pri = rand(); sz = 1;}
};

int sz (node * t) { return t?t->sz:0; }
void upd (node *& t) {
  if (t) t->sz = 1+sz(t->l)+sz(t->r);
}

void merge (node *& t, node * l, node * r) {
  if (!l or !r) return void (t=l?l:r);
  if (l->pri < r->pri) merge(l->r, l->r, r), t=l;
  else merge(r->l, l, r->l), t=r;
  upd(t);
}

void split (node * t, node *&l, node *&r, int v) {
  if (!t) return void (l=r=NULL);
  if (t->q <= v) split(t->r, t->r, r, v), l=t;
  else split(t->l, l, t->l, v), r=t;
  upd(t);
}

void first (node * t, node *&l, node *& r, int v = 1) {
  if (!t) return void(l=r=NULL);
  if (sz(t->l) >= v) first(t->l, l, t->l, 1), r=t;
  else {
    r=t->r; l=t; l->r=NULL;
  }
  upd(l); upd(r);
}

void insert (node*&t, int v) {
  node *l, *r;
  split(t, l, r, v);
  merge(t, l, new node(v));
  merge(t, t, r);
}

int priOf[200100];
int rev[200100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(NULL));

  node * treap = NULL;

  int cnt = 1, m; cin >> m;
  while (m--) {
    int c; cin >> c;
    if (c == 1) {
      int p; cin >> p;
      priOf[cnt] = p; rev[p] = cnt;
      insert(treap, p);
      cnt++;
    }
    if (c == 2) {
      node *l;
      first(treap, l, treap);
      cout << (l?rev[l->q]:0) << '\n';
    }
    if (c == 3) {
      int p; cin >> p;
      node *l, *r;
      split(treap, l, r, priOf[p]);
      cout << sz(l)-1 << '\n';
      merge(treap, l, r);
    }
  }
  
  return 0;
}