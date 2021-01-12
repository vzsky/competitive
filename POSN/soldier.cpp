#include<bits/stdc++.h>
using namespace std;

priority_queue < pair <int,pair<int,int>> > heap;

int main(){
    int n, r;
    scanf("%d %d", &n, &r);
    for(int i = 0; i < n; i++){
        int o;
        scanf("%d", &o);
        if (o==1){
            int id, rank;
            scanf("%d %d", &id, &rank);
            int q = -1 * i;
            heap.push ({rank, {q, id}});
        }
        else {
            if (heap.empty()) printf("-1\n");
            else { printf("%d\n", heap.top().second.second); heap.pop();}


        }
    }
    return 0;
}