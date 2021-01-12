#include<bits/stdc++.h>
using namespace std;

#define pb push_back
typedef long long int lli;

#define MAXN 12000

struct A {
    lli a, b, c;
};

A arr[4005];
vector<int> ss;
lli mic[MAXN+5][MAXN+5], inp[MAXN+5][MAXN+5];
map<int,int> m;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int a, b, c;
        scanf("%d %d %d", &a, &b, &c);
        arr[i] = {a, b, c};
        ss.pb(a); ss.pb(b); ss.pb(c);
    }
    int cnt = 1;
    sort(ss.begin(), ss.end());
    for(auto x : ss){
        if (m.count(x)) continue;
        // cerr << x << " : " << cnt << ' ' ;
        m[x] = cnt++;
    }
    for(int i = 0; i < n; i++){
        inp[m[arr[i].a]][m[arr[i].b]] = inp[m[arr[i].b]][m[arr[i].a]] = max(inp[m[arr[i].a]][m[arr[i].b]], arr[i].c);
        inp[m[arr[i].a]][m[arr[i].c]] = inp[m[arr[i].c]][m[arr[i].a]] = max(inp[m[arr[i].a]][m[arr[i].c]], arr[i].b);
        inp[m[arr[i].c]][m[arr[i].b]] = inp[m[arr[i].b]][m[arr[i].c]] = max(inp[m[arr[i].c]][m[arr[i].b]], arr[i].a);
    }
    for(int i = 1; i <= MAXN; i++){
        for(int j = i; j <= MAXN; j++){
            mic[i][j] = mic[j][i] = max(mic[i-1][j], mic[i][j-1]);
            mic[i][j] = mic[j][i] = max(mic[i][j], mic[i-1][j-1]+inp[i][j]);
            //cerr << i << ' ' << j << ' ' << mic[i][j] << endl;
        }
    }
    printf("%lld", mic[MAXN][MAXN]);
    return 0;
}