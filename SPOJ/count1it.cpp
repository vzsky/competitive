#include<bits/stdc++.h>
using namespace std;

struct node {
    int val;
    int size, pri;
    node *l ,*r; 
    node (int v) {val = v, size = 1, pri = rand();}
};

int size (node *t) {return t?t->size:0;}
void upd (node *t) { if (t) t->size = size(t->l)+size(t->r)+1;}

void merge (node *&t, node *l, node *r) {
    if (!l || !r) return void(t=l?l:r);
    if (l->pri > r->pri) merge(l->r, l->r, r), t=l;
    else merge(r->l, l, r->l), t=r;
    upd(t);
}

void split (node *&l, node *&r, node *t, int key) {
    if (!t) return void (l=r=NULL);
    if (t->val <= key) split(t->r, r, t->r, key), l=t;
    else split(l, t->l, t->l, key), r=t;
    upd(t);
}

void splitat (node *&l, node *&r, node *t, int pos) {
    if (!t) return void(l=r=NULL);
    if (size(t->l) < pos) splitat(t->r, r, t->r, pos-1-size(t->l)), l=t;
    else splitat(l, t->l, t->l, pos), r=t;
    upd(t);
}

void insert (node *&t, int val) {
    node *l, *r, *n = new node(val);
    split(l, r, t, val);
    merge(t, l, n);
    merge(t, t, r);
}

int query (node *t, int key) {
    node *l, *r;
    split(l, r, t, key);
    int ans = size(l);
    merge(t, l, r);
    return ans;
}

int kth (node *t, int k) {
    node *l = NULL, *r = NULL, *m = NULL;
    splitat(l, r, t, k-1);
    splitat(m, r, r, 1);
    int ans = m?m->val:-1e9;
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
        insert(t, a);
    }
    while(q--) {
        int a, o;
        scanf("%d %d", &o, &a);
        if (o == 1) {
            int x = query(t, a);
            insert(t, a+x);
        }
        else if (o == 2) {
            printf("%d\n", query(t, a));
        }
        else if (o == 3) {
            int p = kth(t, a);
            if (p!=-1e9) printf("%d\n", p);
            else printf("invalid\n"); 
        }
        else assert(false);
    }
    return 0;
}