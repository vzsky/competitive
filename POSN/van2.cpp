#include<bits/stdc++.h>
using namespace std;

priority_queue < pair <int,int> > heap;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= k; i++){
        heap.push({0, -1*i});
    }
    for(int  i = 0; i < n; i++){
        int t; scanf("%d", &t);
        auto top = heap.top();
        //cout << top.first << top.second << endl;
        printf("%d\n", -1*top.second);
        heap.pop();
        heap.push({-1*t + top.first, top.second});
    }
    return 0;
}