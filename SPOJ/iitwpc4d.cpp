#include<bits/stdc++.h>
using namespace std;

struct node {
    int val, size, pri;
    node *l, *r;
    node (int v) {val = v; size = 1; pri = rand();}
};

int size (node *t) {return t?t->size:0;}
void upd (node *t) {if (t) t->size = size(t->l)+size(t->r)+1;}

void merge (node *&t, node *l, node *r) {
    if (!l || !r) return void(t=l?l:r);
    if (l->pri > r->pri) merge (l->r, l->r, r), t=l;
    else merge (r->l, l, r->l), t=r;
    upd(t);
}

void split (node *&l, node *&r, node *t, int val) {
    if (!t) return void(l=r=NULL);
    if (t->val <= val) split(t->r, r, t->r, val), l=t;
    else split(l, t->l, t->l, val), r=t;
    upd(t);
}

void splitat (node *&l, node *&r, node *t, int pos) {
    if (!t) return void(l=r=NULL);
    if (size(t->l) < pos) splitat(t->r, r, t->r, pos-1-size(t->l)), l=t;
    else splitat(l, t->l, t->l, pos), r=t;
    upd(t);
}

void erase (node *&t, int key) {
    node *l, *r, *m;
    split(l, r, t, key-1);
    split(m, r, r, key);
    assert(size(m) == 1);
    merge(t, l, r);
}

int kth (node *&t, int k) {
    node *l, *r, *m;
    splitat(l, r, t, k-1);
    splitat(m, r, r, 1);
    assert(size(m) == 1);
    int ret = m?m->val:0;
    merge(t, l, m);
    merge(t, t, r);
    return ret;
}

int a[100100], ans[100100];

int main(){
    srand(time(NULL));
    int q;
    scanf("%d", &q);
    for (int T = 1; T <= q; T++) {
        printf("Test : %d\n", T);
        int n;
        scanf("%d", &n);
        int K = n;
        node *t = NULL;
        for(int i = 1; i <= n; i++) merge(t, t, new node (i));
        bool check = true;
        for(int i = 0; i < n; i++) { scanf("%d", &a[i]); if(a[i] > i) check = false; }
        if (!check) {
            printf("-1\n");
            continue;
        }
        for (int i = n-1; i >= 0; i--) {
            int kthnum = kth(t, K-a[i]);
            ans[i] = kthnum;
            erase(t, kthnum);
            K--;
        }
        for(int i = 0; i < n; i++) printf("%d ", ans[i]);
        printf("\n");
    }
    return 0;
}