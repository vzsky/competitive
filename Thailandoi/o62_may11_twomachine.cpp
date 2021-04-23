#include<bits/stdc++.h>
using namespace std;

struct node {
  long long a, b, pri, sum, bes;
  node *l, *r;
  node (long long A, long long B) {
    a = A; b = B; pri = rand(); sum = a; bes = a+b;
  }
};

long long sum (node * &t) { return t ? t->sum : 0; }
long long bes (node * &t) { return t ? t->bes : 0; }
void upd (node * &t) {
  if (t) t->sum = sum(t->l) + sum(t->r) + t->a;
  if (t) t->bes = max(max(bes(t->l), sum(t->l)+t->a+bes(t->r)), sum(t->l)+t->a+t->b);
}

void merge (node * &t, node * l, node * r) {
  if (!l) return void(t=r);
  if (!r) return void(t=l);
  if (l->pri < r->pri) merge(l->r, l->r, r), t=l;
  else merge(r->l, l, r->l), t=r;
  upd(t);
}

void split (node * &l, node * &r, node * t, long long val) { // spilt + sort by b
  if (!t) return void(l=r=NULL);
  if (t->b >= val) split(t->r, r, t->r, val), l=t, upd(l);
  else split(l, t->l, t->l, val), r=t, upd(r);
}

long long insert (node *& t, long long a, long long b) {
  node * l, * r;
  split(l, r, t, b);
  node * nw = new node(a, b);
  merge(t, l, nw);
  merge(t, t, r);
  return bes(t);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  srand(time(NULL));
  node * treap = NULL;
  long long n, t, m1, m2, s = 0;
  cin >> n >> t >> m1 >> m2;
  long long sumall = 0;
  long long minb = 1e15;
  for (int i = 0; i < n; i++) {
    long long a, b, x, y;
    cin >> x >> y;
    if (t == 1) a = x, b = y;
    if (t == 2) a = x+(s%m1), b = y+(s%m2);

    s = insert(treap, a, b);

    cout << s << '\n';
  }
  return 0;
}