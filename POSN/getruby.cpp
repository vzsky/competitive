#include<bits/stdc++.h>
using namespace std;
#define inp(a, b) b a; cin >> a;
#define x first
#define y second
#define pb push_back
#define For(i, start, en) for(auto i = start; i <= en; i++)
#define log(x) cerr << #x << " is " << x << endl;
#define logarr(start, en) cerr << #start << " : "; For(it, start, en) cerr << *it << ' '; cerr << endl;
#define logvec(v) cerr << #v << " : "; for(auto x : v) cerr << x << ' '; cerr << endl;
#define logmat(a, m, n) For(i, 0, m) { For(j, 0, n) cerr << a[i][j] << ' '; cerr << endl; }
typedef long long int lli;
typedef pair<int,int> pii;
typedef vector<int> vi;

int fw[750100];
int n, m;

int main(){
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        char cmd[10];
        cin >> cmd;
        if(cmd[0] == 'B'){
            int a, b;
            scanf("%d %d", &a, &b);
            for(int i = b; i <= n; i+= (i&-i)){
                fw[i] += a;
            }
        }
        else if(cmd[0] == 'F'){
            int a, b;
            scanf("%d %d", &a, &b);
            int ans = 0;
            for(int i = b; i > 0; i-= (i&-i)){
                ans += fw[i];
            }
            for(int i = a-1; i > 0; i-= (i&-i)){
                ans -= fw[i];
            }
            printf("%d", ans);
        } 
    }
    return 0;
}