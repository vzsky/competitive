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

int g[4][100100];

int main(){
    int t;
    scanf("%d", &t);
    for(int abc = 1; abc <= t; abc++){
        memset(g, 0, sizeof g);
        printf("Case #%d: ", abc);
        int a, b;
        scanf("%d %d", &a, &b);
        for(int i = 0; i < a; i++){
            int x, y; char c;
            scanf("%d %d %c", &x, &y, &c);
            
            switch(c){
                case 'N' : g[0][y+1]++; break;
                case 'E' : g[1][x+1]++; break;
                case 'W' : g[2][x-1]++; break;
                case 'S' : g[3][y-1]++; break;
            }
        }
        for(int i = 1; i <= b; i++){
            g[0][i] +=g[0][i-1];
            g[1][i] +=g[1][i-1];
        }
        for(int i = b; i > 0; i--){
            g[2][i-1] += g[2][i];
            g[3][i-1] += g[3][i];
        }
        // logarr(g[0], g[0]+b);
        // logarr(g[1], g[1]+b);
        // logarr(g[2], g[2]+b);
        // logarr(g[3], g[3]+b);
        int ansx= 0, ansy= 0, mxx = -1, mxy = -1;
        for(int i = 0; i <= b; i++){
            int ax = g[0][i] + g[3][i];
            if (ax > mxx) {
                mxx = ax;
                ansx = i;
            }
            int ay = g[1][i] + g[2][i];
            if (ay > mxy) {
                mxy = ay;
                ansy = i;
            }
        }
        printf("%d %d\n", ansy, ansx);
    }
    return 0;
}