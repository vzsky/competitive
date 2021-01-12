#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> p;
#define x first
#define y second

int f[1010][1010];
p s[5010];

int six = 0;

int valid (p a, p b){
    if (a.x == b.x || a.x == b.y || a.y == b.x || a.y == b.y) return 0;
    if (f[a.x][b.x] + f[a.x][b.y] + f[a.y][b.x] + f[a.y][b.y] == 4) return 2;
    if (f[a.x][b.x] + f[a.x][b.y] + f[a.y][b.x] + f[a.y][b.y] == 3) return 3;
    return 0;
}

int main(){
    int n, m;
    scanf("%d %d",&n, &m);
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);       
        f[a][b] = f[b][a]= 1;
        s[i] = {a, b};
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = i+1; j < m; j++){
            // if (valid(s[i], s[j])) cerr << i << j << endl;
            ans += valid(s[i], s[j]);       
        }
    }
    printf("%d", ans/6);

    return 0;
}