#include<bits/stdc++.h>
using namespace std;

int a[1000100];
priority_queue <pair<int,int>> heap;

int main(){
    int n, l, r;
    scanf("%d %d %d", &n, &l, &r);
    for(int i = 0; i < l+r; i++){
        char o;
        scanf(" %c", &o);
        if (o == 'L'){
            int x, y;
            scanf("%d %d", &x, &y);
            a[y]++; heap.push({a[y], y});
        }
        if (o == 'C'){
            int x, y;
            scanf("%d %d", &x, &y);
            a[y]+=3; heap.push({a[y], y});
        }
        if (o == 'D'){
            while(!heap.empty() && a[heap.top().second] == -1 ) heap.pop();
            a[heap.top().second]=-1;
        }
        if (o == 'R'){
            while(!heap.empty() && a[heap.top().second] == -1 ) heap.pop();
            printf("%d\n", heap.top().second);
        }
    }
    return 0;
}