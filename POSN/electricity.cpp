#include<bits/stdc++.h>
using namespace std;

int mic[500500];
priority_queue <pair<int,int>> heap;

int main(){
    int n, k;
    int ans;
    int num;
    int dec;
    scanf("%d %d", &n, &k);
    scanf("%d", &dec);
    heap.push({-1*dec,1});
    for(int i = 2; i <= n; i++){
        scanf("%d", &dec);
        while (!heap.empty() && heap.top().second < i-k) heap.pop();
        num = dec + heap.top().first*-1;
        heap.push({-1*num, i});
    }
    printf("%d", num);
    return 0;
}