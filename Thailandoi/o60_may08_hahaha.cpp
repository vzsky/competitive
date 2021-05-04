#include <bits/stdc++.h>
using namespace std;

struct node {
  long long sz, pri, val, cnt[5], inv;
  int twist, set;
  node * l, * r;
  node (int v) {
    for (int i = 0; i < 5; i++) cnt[i] = 0;
    cnt[v] = 1; pri = rand(); val = v; sz = 1; inv = 0; set = -1; twist = 0;
    l = r = NULL;
  }
};

long long sz (node * t) { return t?t->sz:0; }
long long cnt (node * t, int k) { return t?t->cnt[k]:0; }
long long inv (node * t) { return t?t->inv:0; }
long long choose2 (long long a) { return (a*(a-1))/2; }

void push (node * t) {
  if (!t) return;
  if (t->twist) {
    if (t->l) t->l->twist ^= 1;
    if (t->r) t->r->twist ^= 1;
    swap(t->l, t->r);
    t->inv = choose2(sz(t)) - t->inv;
    for (int i = 0; i < 5; i++) t->inv -= choose2(cnt(t, i));
    t->twist = 0;
  }
  if (t->set != -1) {
    if (t->l) t->l->set = t->set;
    if (t->r) t->r->set = t->set;
    for (int i = 0; i < 5; i++) t->cnt[i] = 0;
    t->cnt[t->set] = sz(t);
    t->inv = 0;
    t->val = t->set;
    t->set = -1;
  }
}

void upd (node * t) {
  if (!t) return;
  // make sure child is pushed (child's subtree's clean first!!!)
  push(t->l), push(t->r);
  t->sz = 1+sz(t->l)+sz(t->r);
  for (int i = 0; i < 5; i++) t->cnt[i] = cnt(t->l, i)+cnt(t->r, i);
  t->cnt[t->val]++;
  t->inv = inv(t->l)+inv(t->r);
  for (int i = 0; i < 5; i++) {
    if (t->val < i) t->inv += cnt(t->l, i);
    if (t->val > i) t->inv += cnt(t->r, i);
    for (int j = 0; j < i; j++) {
      t->inv += cnt(t->l, i) * cnt(t->r, j);
    }
  }
}

void split (node * t, node *&l, node *& r, int at) {
  push(t);
  if (!t) return void (l=r=NULL);
  if (sz(t->l) >= at) split(t->l, l, t->l, at), r=t;
  else split(t->r, t->r, r, at-1-sz(t->l)), l=t;
  upd(t);
}

void merge (node *& t, node * l, node * r) {
  push(l); push(r);
  if (!l or !r) return void (t=l?l:r);
  if (l->pri < r->pri) merge(l->r, l->r, r), t=l;
  else merge(r->l, l, r->l), t=r; 
  upd(t);
}

int main(){
  srand(time(NULL));
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  node * treap = NULL;
  int n, q; cin >> n >> q;
  string s; cin >> s;
  for (int i = 0; i < s.size(); i++) {
    merge(treap, treap, new node(s[i]-'0'));
  }
  while (q--) {
    int t, a, b; cin >> t >> a >> b;
    node *l, *m, *r;
    split(treap, l, r, b);
    split(l, l, m, a-1);
    if (t == 1) cin >> m->set;
    if (t == 2) m->twist ^= 1;
    if (t == 3) cout << inv(m) << '\n';
    merge(l, l, m);
    merge(treap, l, r);
  }
  return 0;
}