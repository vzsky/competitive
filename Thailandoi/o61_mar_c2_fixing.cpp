#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second

pair<int,int> a[100100];

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    if (k >= m) { printf("0"); return 0; }
    for(int i = 0; i < m; i++) scanf("%d", &a[i].x);
    sort(a, a+m);
    a[0].y = 0;
    int size = a[m-1].x - a[0].x - m+1;
    for(int i = 1; i < m; i++) a[i].y = a[i].x-a[i-1].x;
    sort(a, a+m, [](const pair<int,int> &a, const pair<int,int> &b) {return a.y > b.y;});
    for(int i = 0; i < k-1; i++) size -= a[i].y-1;
    printf("%d", size);
    return 0;
}