#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    int pri, size;
    int mx;
    node *l ,*r;
    node (int h) {val = mx = h; pri = rand(); size = 1;}
};

int sz(node * t) {return t?t->size:0;}
int mx(node * t) {return t?t->mx:-1e9;}
void upd(node * t) {
    if (!t) return;
    t->size = 1+sz(t->l)+sz(t->r);
    t->mx = max(max(mx(t->l), mx(t->r)), t->val);
}


void merge(node *&t, node *l, node *r) {
    if (!l) return void (t = r);
    if (!r) return void (t = l); 
    if (l->pri > r->pri) merge(l->r, l->r, r), t = l;
    else merge(r->l, l, r->l), t = r;
    upd(t);
}

void splitat(node *&l ,node *&r, node *t, int pos) {
    if (!t) return void(l=r=NULL);
    if (sz(t->l) < pos) splitat(t->r, r, t->r, pos-sz(t->l)-1), l = t;
    else splitat(l, t->l, t->l, pos), r = t;
    upd(t);
}

void insert(node *&t, int h, int p) {
    node *l ,*r, *n = new node(h);
    splitat(l, r, t, p-1);
    merge(t, l, n);
    merge(t, t, r);
}

int query(node *&t, int a, int b) {
    node *l, *m, *r;
    splitat(l, r, t, a-1);
    splitat(m, r, r, b-a+1);
    int ans = m->mx;
    merge(t, l, m);
    merge(t, t, r);
    return ans;
}

int main(){
    srand(time(NULL));
    node * treap = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        char opr; int x, y;
        scanf(" %c %d %d", &opr, &x, &y);
        if (opr == 'A') insert(treap, x, y);
        else printf("%d\n",query(treap, x, y));
    }
    return 0;
}