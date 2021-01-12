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

int fw[3][1000100];
int color[1000100];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j+=(j&-j)){
            fw[i%3][j]++;
        }
        color[i] = i%3;
    }
    while(m--){
        int cmd, a, b; char c;
        scanf("%d", &cmd);
        if (cmd == 1) {
            scanf("%d %c", &a, &c);
            int col;
            switch(c){
                case 'R' : col = 1; break;
                case 'G' : col = 2; break;
                case 'B' : col = 0; break;
            }
            for(int j = a; j <= n; j+=(j&-j)){
                fw[color[a]][j]--;
            }
            for(int j = a; j <= n; j+=(j&-j)){
                fw[col][j]++;
            }
            color[a] = col;
        }
        else {
            int rr = 0, gg = 0, bb = 0;
            scanf("%d %d", &a, &b);
            for(int i = b; i > 0; i-=(i&-i)){
                rr+=fw[1][i];
                gg+=fw[2][i];
                bb+=fw[0][i];
            }
            if (a != 1){
                for(int i = a-1; i > 0; i-=(i&-i)){
                    rr-=fw[1][i];
                    gg-=fw[2][i];
                    bb-=fw[0][i];
                }
            }
            //logarr(color+1, color+n+1);
            //log(rr << gg << bb);
            int mx = max(rr, max(gg, bb));
            if ((rr == gg && rr == mx) || (rr == bb && rr == mx) || (bb == gg && bb == mx)) printf("None\n");
            else if (rr > gg){
                if (rr > bb){
                    printf("R\n");
                }
                else {
                    printf("B\n");
                }
            }
            else {
                if (gg > bb){
                    printf("G\n");
                }
                else {
                    printf("B\n");
                }
            }
        }
    }
    return 0;
}