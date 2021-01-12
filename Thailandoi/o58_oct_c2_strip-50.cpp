#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define For(a,b) for(int a = 0; a < b; a++)
#define _cerrheader(a) cerr << #a << " : "
#define log(a) _cerrheader(a) << a
#define logarr(a, b) { _cerrheader(a); For(i, b) cerr << a[i] << ' ';}
#define logvec(v) { _cerrheader(a); for(auto i : v) cerr << v[i] << ' ';}
#define logmat(a,b,c) For(i,b) { For(j,c) cerr << a[i][j] << ' ';  cerr << endl;}
typedef pair<int,int> pii;
typedef long long lli;
typedef vector<int> vi;

int fw[25][101000];

void update(int t, int ind, int val){
    for(int i = ind; i <= 100100; i+=(i&-i)){
        fw[t][i] += val;
    }
}

int query(int t, int ind){
    int ans = 0;
    for(int i = ind; i > 0; i-=(i&-i)){
        ans += fw[t][i];
    }
    return ans;
}

int main(){
    int n, m, k;
    scanf("%d %d %d", &n, &m, &k);
    for(int i = 0; i < n; i++){
        int a, b, c, d;
        scanf("%d %d %d %d", &a, &b, &c, &d);
        for(int j = b; j <= d; j++) {
            int board = 10+j-a;
            if (board < 0 || board > 20) continue;
            update(board, 1+j, 1);
        }
        for(int j = a+1; j <= c; j++) {
            int board = 10+b-j;
            if (board < 0 || board > 20) continue;
            update(board, 1+b, 1);
        }
        for(int j = b; j <= d; j++) {
            int board = 10+j-c;
            if (board < 0 || board > 20) continue;
            update(board, 1+j+1, -1);
        }
        for(int j = a; j < c; j++) {
            int board = 10+d-j;
            if (board < 0 || board > 20) continue;
            update(board, 1+d+1, -1);
        }
    }

    // for(int i = 0; i <= 20; i++) {
    //     for(int j = 0; j <= 10; j++){
    //         cerr << query(i, j+1) << ' ';
    //     }
    //     cerr << endl;
    // }

    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", query(b-a+10, 1+b));
    }
    return 0;
}