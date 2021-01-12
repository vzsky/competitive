#include<bits/stdc++.h>
using namespace std;

struct node {
    int val, size, pri;
    node *l, *r;
    node (int v) {val = v; size = 1; pri = rand();}
};

int size(node * t) {return t?t->size:0;}
void upd(node * t) {if (t) t->size=size(t->l)+size(t->r)+1;}

void merge (node *&t, node *l, node *r){
    if (!l || !r) return void(t=l?l:r);
    if (l->pri > r->pri) merge(l->r, l->r, r), t=l;
    else merge(r->l, l, r->l), t=r;
    upd(t);
}

void splitkey (node *&l, node *&r, node *t, int key) {
    if (!t) return void(l=r=NULL);
    if (t->val <= key) splitkey(t->r, r, t->r, key), l=t;
    else splitkey(l, t->l, t->l, key), r=t;
    upd(t);
}

void split (node *&l, node *&r, node *t, int pos) {
    if (!t) return void(l=r=NULL);
    if (size(t->l) < pos) split(t->r, r, t->r, pos-1-size(t->l)), l=t;
    else split(l, t->l, t->l, pos), r=t;
    upd(t);
}

void insert (node *&t, node *n) {
    if (!t) return void(t=n);
    if (t->pri < n->pri) splitkey(n->l, n->r, t, n->val), t=n;
    else if (t->val <= n->val) insert(t->r, n);
    else insert(t->l, n);
    upd(t);
}

int kth (node *&t, int k) {
    node *l, *r, *m;
    split(l, r, t, k-1);
    split(m, r, r, 1);
    // cerr << "size " << size(l) <<' ' <<  size(m) << ' ' << size(r) << endl;
    assert(size(m) == 1);
    int ret = m->val;
    merge(t, l, r);
    return ret;
} 

int p[100100];
int ans[100100];

int main(){
    srand(time(NULL));
    node *t = NULL;
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        int a;
        scanf("%d", &a);
        insert(t, new node(a));
    }
    for (int i = 0; i < n; i++) scanf("%d", &p[i]);
    for (int i = n-1; i >= 0; i--) {
        ans[i] = kth(t, p[i]+1);
        // printf("%d\n", ans[i]);
    }
    for(int i = 0; i < n; i++) printf("%d\n", ans[i]);
    return 0;
}