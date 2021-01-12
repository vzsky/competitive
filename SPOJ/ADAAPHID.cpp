#include<bits/stdc++.h>
using namespace std;

struct node {
    long long id, val, sum, pri;
    node *l, *r;
    node (long long v, long long i) {val = sum = v; id = i; pri = rand();}
};

long long sum(node *t) {return t?t->sum:0ll;}
void upd(node *t) { if (t) t->sum = t->val+sum(t->l)+sum(t->r); }

void merge (node *&t, node *l, node *r) {
    if (!l) return void(t = r);
    if (!r) return void(t = l);
    if (l->pri > r->pri) merge(l->r, l->r, r), t=l;
    else merge(r->l, l, r->l), t=r;
    upd(t);
}

void split (node *&l, node *&r, node *t, long long key) {
    if (!t) return void(l=r=NULL);
    if (t->id <= key) split(t->r, r, t->r, key), l = t;
    else split(l, t->l, t->l, key), r = t;
    upd(l), upd(r);
}

void insert(node *&t, long long pos, long long val){
    node *l, *r;
    split(l, r, t, pos);
    merge(t, l, new node(val, pos));
    merge(t, t, r);
}

long long query(node *&t, long long b) {
    node *l, *r;
    split(l, r, t, b);
    long long ans = sum(l);
    merge(t, l, r);
    return ans;
}

int main(){
    srand(time(NULL));
    node * t = NULL;
    long long q;
    scanf("%lld", &q);
    long long l = 0ll;
    while(q--) {
        long long a, b;
        scanf("%lld %lld", &a, &b);
        a^=l; b^=l;
        insert(t, a, b);
        l = query(t, a);
        printf("%lld %lld\n",a, l);
    }
    return 0;
}