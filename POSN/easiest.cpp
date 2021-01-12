#include<bits/stdc++.h>
using namespace std;

priority_queue<int> h;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        char c;
        scanf(" %c", &c);
        if (c == 'A') {
            int a;
            scanf("%d", &a);
            h.push(-1*a);
        }
        else {
            if (h.empty()) { printf("-1"); continue; }
            printf("%d", -1*h.top());
            h.pop();
        }
    }
    return 0;
}