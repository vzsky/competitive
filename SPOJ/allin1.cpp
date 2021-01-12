#include<bits/stdc++.h>
using namespace std;

struct node {
    int val, size, pri;
    node *l, *r;
    node (int v) {val = v; size = 1; pri = rand();}
};

int size (node * t) {return t?t->size:0;}
void upd (node * t) {if (t) t->size = size(t->l)+size(t->r)+1;}

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

void insert (node *&t, node *n) {
    if (!t) return void(t = n);
    if (n->pri > t->pri) split(n->l, n->r, t, n->val), t=n;
    else if (t->val <= n->val) insert(t->r, n);
    else insert(t->l, n);
    upd(t);
}

void erase (node *&t, int val) {
    if (!t) return;
    if (t->val == val) merge(t, t->l, t->r);
    else if (t->val <= val) erase(t->r, val);
    else erase(t->l, val);
    upd(t);
}

int kth (node *t, int k) {
    if (!t) return -1;
    if (size(t->l) == k-1) return t->val;
    if (size(t->l) < k-1) return kth(t->r, k-size(t->l)-1);
    else return kth(t->l, k); 
}

bool found;
int find (node *t, int key) {
    if (!t) return 0;
    if (t->val == key) found = true;
    if (t->val <= key) return size(t->l)+1+find(t->r, key);
    else return find(t->l, key);
}

int main(){
    srand(time(NULL));
    node * t = NULL;
    while(1) {
        int o, a;
        scanf("%d", &o);
        if (o == -1) return 0;
        scanf("%d", &a);
        if (o == 1) insert(t, new node(a));
        else if (o == 2) erase(t, a);
        else if (o == 3) {
            found = false;
            int ans = find(t, a);
            printf("%d\n", found?ans:-1);
        }
        else if (o == 4) printf("%d\n", a==0?-1:kth(t, a));
        else assert(false);
    }
    return 0;
}