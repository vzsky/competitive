#include<bits/stdc++.h>
using namespace std;

pair<int,int> sd[110];
int p[110];
int arr[110];

int find (int i){
    if (p[i] == i) return i;
    return p[i] = find(p[i]);
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        sd[i] = {x,y};
    }

    for(int i = 1; i <= n; i++) p[i] = i; //init

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n ; j++){
            if (sd[i].first == sd[j].first || sd[i].second == sd[j].second) p[find(j)] = find(i);
        }
    }

    for(int i = 1; i <= n; i++){
        arr[find(i)] = 1;
    }
    int cnt = 0;
    for(int i = 1; i <= n; i++){
        cnt+=arr[i];
    }
    printf("%d", cnt-1);
    return 0;
}