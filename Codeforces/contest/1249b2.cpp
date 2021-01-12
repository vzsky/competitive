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

int p[200100], s[200100], a[200100], d[200100];
int find(int u) {return u==p[u]?u:p[u]=find(p[u]);}

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        int n;
        scanf("%d", &n);
        iota(p, p+n+1, 0);
        for(int i = 1; i <= n; i++) s[i] = 1;
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            if (find(i) == find(a[i])) continue;
            // cerr << i << ' '<< s[find(i)] << ' ' << s[find(a[i])] << endl;
            s[find(a[i])] += s[find(i)];
            p[find(i)] = find(a[i]);
        }
        for(int i = 1; i <= n; i++){
            printf("%d ", s[find(i)]);
        }
        printf("\n");
    }
    return 0;
}