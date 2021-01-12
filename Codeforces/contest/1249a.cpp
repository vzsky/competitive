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

int a[110];
int main(){
    int q;
    int n;
    scanf("%d", &q);
    while(q--)  {
        scanf("%d", &n);
        for(int i = 0; i < n; i++){
            scanf("%d", &a[i]);
        }
        sort(a, a+n);
        int cnt = 0;
        for(int i = 0; i < n-1; i++){
            if (a[i] == a[i+1]-1) cnt=1;
        }
        assert(cnt <= 1);
        printf("%d\n", 1+cnt);
    }
    return 0;
}