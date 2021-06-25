#include "reach.h"
#include <bits/stdc++.h>
using namespace std;

struct node {
  int u, v, mn, pri, sz;
  node *l, *r;
  node (int U, int V) {
    u=U; v=V; mn=U; pri=rand(); sz=1;
  }
} * t;

int sz (node *t) { return t?t->sz:0; }
int mn (node *t) { return t?t->mn:1e9; }

void upd(node *&t) {
  if (!t) return;
  t->sz = sz(t->l) + sz(t->r) + 1;
  t->mn = min(t->u, min(mn(t->l), mn(t->r)));
}

void merge (node *&t, node *l, node * r) {
  if (!l or !r) return void(t=l?l:r);
  if (l->pri > r->pri) merge(l->r, l->r, r), t=l;
  else merge(r->l, l, r->l), t=r;
  upd(t);
}

void split (node *t, node *&l, node *&r, int val) {
  if (!t) return void(l=r=NULL);
  if (t->v <= val) split(t->r, t->r, r, val), l=t;
  else split(t->l, l, t->l, val), r=t;
  upd(t);
}

int search (node *t, int u) {
  if (!t) return 1e9;
  if (mn(t->l) < u) return search (t->l, u);
  if (t->u < u) return t->v;
  return search (t->r, u);
}

void initialize(int N) { srand(100); }

void add_arc(int u, int v) {
  node *l, *r;
  split(t, l, r, v);
  merge(l, l, new node(u, v));
  merge(t, l, r);
}

bool is_reachable(int u, int v, int des) {
  if (u <= des and des <= v) return false;
  if (des < u) return true;

  node *l, *r;
  split(t, l, r, v);
  int res = search(r, u);
  merge(t, l, r);

  return res <= des;
}