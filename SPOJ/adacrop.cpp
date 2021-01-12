#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> pii;

struct node {
    int size, pri;
    pii key;
    node *l, *r;
    node (pii i) {key = i; pri = rand(); size = 1;}
};

int plant[200010];

int size(node * t) {return t?t->size:0;}
void upd(node * t) {
    if (!t) return;
    t->size = 1+size(t->l)+size(t->r);
}

void merge (node *&t, node *l, node *r) {
    if (!r || !l) return void(t=l?l:r);
    if (l->pri > r->pri) merge(l->r, l->r, r), t=l;
    else merge(r->l, l, r->l), t=r;
    upd(t);
}

void split (node *&l, node *&r, node *t, pii key) {
    if (!t) return void (l=r=NULL);
    if (t->key <= key) split(t->r, r, t->r, key), l=t;
    else split(l, t->l, t->l, key), r=t;
    upd(t);
}

void inorder (node *t) {
    if (!t) return;
    inorder(t->l);
    cerr << t->key.first << '/' << t->key.second << ' ';
    inorder(t->r);
}

void insert (node *&t, node *n) {
    node *l, *r;
    split(l, r, t, n->key);
    merge(t, l, n);
    merge(t, t, r);
}

void erase (node *&t, pii key) {
    node *l, *r, *m;
    split(l, r, t, key);
    split(l, m, l, {key.first, key.second-1});
    merge(t, l, r);
}

int query (node *&t, pii a, pii b) {
    node *l, *r, *m;
    split(l, r, t, a);
    split(m, r, r, b);
    int ans = size(m);
    merge(t, l, m);
    merge(t, t, r);
    return ans;
}

int main(){
    srand(time(NULL));
    node * t = NULL;
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        plant[i] = a;
        insert(t, new node ({a, i}));
    }
    while(q--) {
        int a, b;
        scanf("%d %d", &a, &b);
        erase(t, {plant[a], a});
        insert(t, new node ({b, a}));
        plant[a] = b;
        printf("%d\n", query(t, {b, -1}, {b, a-1}));
    }
    return 0;
}