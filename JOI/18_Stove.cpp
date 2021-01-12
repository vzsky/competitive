#include<bits/stdc++.h>
using namespace std;

int t[100100];
priority_queue<int> heap;
long long sum;

int main(){
    int n, k;
    scanf("%d %d", &n, &k); k--;
    for (int i = 0; i < n; i++) scanf("%d", &t[i]);
    for (int i = 1; i < n; i++) heap.push(t[i]-t[i-1]-1);
    sum = t[n-1] - t[0] + 1;
    while (k--) sum -= heap.top(), heap.pop();
    printf("%lld", sum);
    return 0;
}