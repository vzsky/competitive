#include<bits/stdc++.h>
using namespace std;

struct node {
  int val, pri, sz, rev;
  node *l, *r;
  node (int v) {val=v; pri=rand(); l=r=NULL; sz=1; rev=0;}
};

int val (node* a) { return a?a->val:0; }
int sz (node* a) { return a?a->sz:0; }
void upd (node* a) { if (a) a->sz = 1+sz(a->l)+sz(a->r); } 

void push(node* a) {
  if (!a or !a->rev) return;
  if (a->l) a->l->rev ^= 1;
  if (a->r) a->r->rev ^= 1;
  swap(a->l, a->r);
  a->rev = 0;
}

void merge (node* &t, node* l, node *r) {
  if (!l) return void (t=r);
  if (!r) return void (t=l);
  push(l); push(r);
  if (l->pri < r->pri) merge(l->r, l->r, r), t=l;
  else merge(r->l, l, r->l), t=r;
  upd(t);
}

void splitat (node* &l, node* &r, node* t, int k) { // 1..k to the l, rest to the r
  if (!t) return void (l=r=NULL);
  push(t);
  if (sz(t->l) < k) splitat(t->r, r, t->r, k-1-sz(t->l)), l=t;
  else splitat(l, t->l, t->l, k), r=t;
  upd(t);
}

void reverse (node* &t, int pos) {
  node *l, *r; splitat(l, r, t, pos);
  if (l) l->rev ^= 1;
  merge(t, l, r);
}

int first (node* &t) {
  node *l, *r; splitat(l, r, t, 1);
  merge(t, l, r);
  return val(l);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  srand(time(NULL));
  node * rt = NULL;
  int n, cnt=0; cin >> n;
  for (int i = 1; i <= n; i++) {
    int a; cin >> a;
    node* nw = new node(a);
    merge(rt, rt, nw);
  }
  for (int idx = first(rt); idx != 1; idx = first(rt)) reverse(rt, idx), cnt++;
  cout << cnt << endl;
  return 0;
}