#include<bits/stdc++.h>
using namespace std;

int n, m;
int mic[100100], a[100100];
stack<int> s;

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i++){
        while(!s.empty() && a[s.top()] >= a[i]) s.pop();
        if (!s.empty()) mic[i] = max(mic[s.top()], a[i]-a[s.top()]);
        s.push(i);
    }
    sort(mic, mic+n);
    for(int i = 0; i < m; i++){
        int x;
        scanf("%d", &x);
        printf("%d\n", n-(int)(upper_bound(mic,mic+n,x)-&mic[0]));
    }
    return 0;
}