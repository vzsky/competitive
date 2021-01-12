#include<bits/stdc++.h>
using namespace std;

#define pb push_back

int l[200100], r[200100];
map<int,vector<int>> pos;

void normalize(int root = 0, int now = 1){
    pos[now].pb(root);
    if (l[root] == -1 and r[root] == -1) {
        pos[now*2].pb(-1);
        pos[now*2+1].pb(-1);
        return;
    }
    if (r[root] == -1) {
        normalize(l[root], now);
        return;
    }
    if (l[root] == -1) {
        normalize(r[root], now);
        return;
    }
    normalize(l[root], now*2);
    normalize(r[root], now*2+1);
}

int s, a, b;
int dir() {
    int res = ((s & 8) >> 3);
    s = (s * a + b) % 40507;
    return res;
}

int tour(int l, int now = 1) {
    // cerr << "\t" << l << ' ' << now << ' ' << pos[now].size() << endl;
    if (l <= pos[now].size()-1) return pos[now][l];
    if (pos[now*2][0] == -1 and pos[now*2+1][0] == -1) return pos[now][pos[now].size()-1];
    if (dir())  return tour(l-pos[now].size(), now*2+1);
    else        return tour(l-pos[now].size(), now*2);
}

int main(){
    int n, q;
    scanf("%d %d", &n, &q);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &l[i], &r[i]);
    }
    //cerr << "scanned" << endl;
    normalize();
    // return 0;
    for(int i = 0; i < q; i++){
        int l;
        scanf("%d %d %d %d", &l, &s, &a, &b);
        // cerr << l << ' ' << endl;
        printf("%d\n", tour(l));
    }
    return 0;
}

/*
9 5 3 -1 -1 -1 1 8 6 7 -1 -1 -1 -1 5 4 -1 2 -1 -1
2 100 1 1 4 8 10 10 4 8 1 8 10 8 1 8 10 100 10 1
*/
