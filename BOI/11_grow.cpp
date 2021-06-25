// join is way faster than merge (Merge got TLE even on small cases)
// or did I mess sth up with merge???
#include<bits/stdc++.h>
using namespace std;

struct node {
  int h, sz, pri, laz;
  node *l, *r; 
  node (int v) {h=v; sz=1; pri=rand();}
};
node * t = NULL;

int sz (node *t) { return t?t->sz:0; }
void upd (node *t) { if (t) t->sz = sz(t->l)+sz(t->r)+1; }
void push (node *t) {
  if (!t or t->laz == 0) return;
  if (t->l) t->l->laz += t->laz;
  if (t->r) t->r->laz += t->laz;
  t->h += t->laz;
  t->laz = 0;
}

void splitat (node *t, node *&l, node *&r, int at) {
  push(t);
  if (!t) return void(l=r=NULL);
  if (sz(t->l) >= at) splitat(t->l, l, t->l, at), r=t;
  else splitat(t->r, t->r, r, at-sz(t->l)-1), l=t;
  upd(t);
}

void split (node *t, node *&l, node *&r, int val) {
  push(t);
  if (!t) return void (l=r=NULL);
  if (t->h <= val) split(t->r, t->r, r, val), l=t;
  else split(t->l, l, t->l, val), r=t;
  upd(t);
}

int mx (node *t) {
  push(t);
  if (!t) return 0;
  if (!t->r) return t->h;
  return mx(t->r);
}

int mn (node *t) {
  push(t);
  if (!t) return 0;
  if (!t->l) return t->h;
  return mn(t->l);
}

void join (node *& t, node *l, node *r) {
  push(l);push(r);
  if (!l or !r) return void (t=l?l:r);
  if (l->pri < r->pri) join(r->l, l, r->l), t=r;
  else join(l->r, l->r, r), t=l;
  upd(t);
}

int a[100100];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(NULL));
  int n, m; cin >> n >> m;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; i++) join(t, t, new node(a[i]));
  while(m--) {
    char o; int x, y; cin >> o >> x >> y;
    node *l, *m, *r;
    if (o == 'F') {
      split(t, l, r, y-1);
      splitat(r, m, r, x);
      if (m) m->laz++;
      push(m);
      node *a, *b; 
      if (mx(m) > mn(r)) {
        split(m, a, m, mx(m)-1);
        split(r, b, r, mn(r));
        join(a, a, b);
        join(m, a, m);
      }
      join(m, m, r);
      join(t, l, m);
    }
    if (o == 'C') {
      split(t, l, r, x-1);
      split(r, m, r, y);
      cout << sz(m) << '\n';
      join(t, l, m);
      join(t, t, r);
    }
  }
  return 0;
}
/* POSSIBLE BUGS

*/
/* TESTCASE

*/