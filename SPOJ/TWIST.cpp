#include<bits/stdc++.h>
using namespace std;

struct node {
    int val, size, pri, rev;
    node *l, *r;
    node (int v) {val = v; size = 1; pri = rand(); rev = 0;}
};

int size (node * t) {return t?t->size:0;}
void update (node * t) {if (!t) return; t->size = size(t->l)+size(t->r)+1;}

void push (node * t) {
    if (!t || !t->rev) return;
    swap(t->l, t->r);
    t->rev = 0;
    if (t->l) t->l->rev ^= 1;
    if (t->r) t->r->rev ^= 1;
}

void merge (node * &t, node * l, node * r) {
    if (!l || !r) return void(t = l?l:r);
    push(l); push(r);
    if (l->pri > r->pri) t=l, merge(t->r, t->r, r);
    else t=r, merge(t->l, l, t->l);
    update(t);
}

void split (node * &l, node * &r, node * t, int pos) {
    if (!t) return void (l=r=NULL);
    push(t);
    if (size(t->l) < pos) l=t, split(l->r, r, l->r, pos-1-size(t->l)), l=t;
    else r=t, split(l, r->l, r->l, pos), r=t;
    update(t);
}

void inorder (node *& t) {
    if (!t) return;
    push(t);
    inorder(t->l);
    printf("%d ", t->val);
    inorder(t->r);
}

void reverse (node *&t, int a, int b) {
    node *l, *r, *m;
    split(l, r, t, a-1);
    split(m, r, r, b-a+1);
    m->rev ^= 1;
    merge(t, l, m);
    merge(t, t, r);
}

int main(){
    srand(time(NULL));
    node * t = NULL;
    int n, m, l, r;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) merge(t, t, new node(i));
    while(m--) {
        scanf("%d %d", &l, &r);
        reverse(t, l, r);
    }
    inorder(t);
    return 0;
}