#include<bits/stdc++.h>
using namespace std;

struct node {
    int val, pri, sz;
    node* l, *r;
    node(int v) { val = v; pri = rand(); sz = 1; }
    
};

int sz(node* t) { return t?t->sz:0; }
void upd(node* &t) { if (t) t->sz = sz(t->l) + sz(t->r) + 1; }

void inorder (node* &t) {
  if (!t) return;
  inorder(t->l);
  printf("%d ", t->val);
  inorder(t->r);
}

// concat two treaps
void merge (node* &t, node* a, node* b) {
  if (!a) return void(t = b);
  if (!b) return void(t = a);
  if (a->pri > b->pri) merge(a->r, a->r, b), t = a;
  else merge(b->l, b->l, a), t = b;
  upd(t);
}

// split a treap into 2 treaps based on values
void split(node* &l, node* &r, node* t, int val) { // <= val in l
  if (!t) return void(l = r = NULL);
  if (t->val <= val) split(t->r, r, t->r, val), l = t;
  else split(l, t->l, t->l, val), r = t;
  upd(t);
}

// merge two sorted set with overlapped values.
void mergeany (node *&t, node *l, node *r) {
  if (!l or !r) return void (t = l?l:r);
  node * a, * b;
  if (l->pri < r->pri) swap(l, r); 
  split(a, b, r, l->val);
  mergeany(l->l, l->l, a);
  mergeany(l->r, l->r, b);
  t=l;
  upd(t);
}

// split treap into 2 treaps based on number of elements
void splitat(node* &l, node* &r, node* t, int pos) { // first pos elements at l
  if (!t) return void(l = r = NULL);
  if (sz(t->l) < pos) splitat(t->r, r, t->r, pos-sz(t->l)-1), l = t;
  else splitat(l, t->l ,t->l, pos), r = t;
  upd(t);
}

// find kth value in a treap
int kth (node *&t, int k) {
  if (!t) return -1;
  if (sz(t->l) == k-1) return t->val;
  if (sz(t->l) < k-1) return kth(t->r, k-sz(t->l)-1);
  else return kth(t->l, k); 
}

// check if key is in treap
bool found;
void find (node *t, int key) {
  if (!t) return;
  if (t->val == key) found = true;
  if (t->val <= key) return sz(t->l)+1+find(t->r, key);
  else return find(t->l, key);
}

// insert new node
void insert (node *&t, node *n) {
  if (!t) return void(t = n);
  if (n->pri > t->pri) split(n->l, n->r, t, n->val), t=n;
  else if (t->val <= n->val) insert(t->r, n);
  else insert(t->l, n);
  upd(t);
}

// erase all nodes with value val
void erase (node *&t, int val) {
  if (!t) return;
  if (t->val == val) merge(t, t->l, t->r);
  else if (t->val <= val) erase(t->r, val);
  else erase(t->l, val);
  upd(t);
}

int main(){
  srand(time(NULL));
  node* treap = NULL;
  return 0;
}