#include<bits/stdc++.h>
using namespace std;

int p[100100];

int find (int node){
    if (p[node] == node) return node;
    return p[node] = find(p[node]);
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 1; i <= n; i++){
        p[i] = i;
    }
    while(q--){
        char cmd; int a, b;
        scanf(" %c %d %d", &cmd, &a, &b);
        if (cmd == 'c') 
            p[find(a)] = p[find(b)];
        if (cmd == 'q') 
            printf(find(a) == find(b)? "yes\n":"no\n");
    }
return 0;
}