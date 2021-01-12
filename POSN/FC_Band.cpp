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

pii s[5100];
int g[1010][1010];

bool fourpoint (pii a, pii b){
    if (a.x == b.x || a.x == b.y || a.y == b.x || a.y == b.y) return 0;
    return 1;
}

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &s[i].x, &s[i].y);
        g[s[i].x][s[i].y] = 1;
        g[s[i].y][s[i].x] = 1;
    }
    int ans = 0;
    for(int i = 0; i < m; i++){
        for(int j = i+1 ; j < m; j++){
            if (fourpoint(s[i], s[j])){
                if (g[s[i].x][s[j].y] + g[s[i].x][s[i].y] + g[s[i].x][s[j].x] + g[s[j].x][s[j].y] + g[s[j].x][s[i].y] + g[s[i].y][s[j].y] == 5){
                    //cerr << s[i].x << ' ' << s[i].y << ' ' << s[j].x << ' ' << s[j].y << endl;
                    ans+=3;
                }
                if (g[s[i].x][s[j].y] + g[s[i].x][s[i].y] + g[s[i].x][s[j].x] + g[s[j].x][s[j].y] + g[s[j].x][s[i].y] + g[s[i].y][s[j].y] == 6){
                    //cerr << "6 " << s[i].x << ' ' << s[i].y << ' ' << s[j].x << ' ' << s[j].y << endl;
                    ans+=2;
                }
            }
        }
    }
    printf("%d", ans/6);
    return 0;
}