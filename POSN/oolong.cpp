#include<bits/stdc++.h>
using namespace std;

int bought[50100];
long long  m;

struct A {
    int cost, id, coupons;
    bool operator < (const A & o) const {
        if (cost == o.cost) return coupons > o.coupons;
        return cost > o.cost;
    }
};
priority_queue<A> heap;

int ans = 0;

int main(){
    int n, k;
    scanf("%d %d %lld", &n, &k, &m);
    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        heap.push({a, i, 0});
        heap.push({b, i, 1});
    }
    while(!heap.empty()){
        auto tp = heap.top();
        heap.pop();

       if (!bought[tp.id] && m >= tp.cost && tp.coupons<=k){
            m-=tp.cost;
            ans++;
            k-=tp.coupons;
            bought[tp.id] = 1;
        }

    }
    printf("%d", ans);
return 0;
}