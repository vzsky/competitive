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

char tab[550][550];
int visited[550][550][2][2][2];

int sx, sy, ex, ey;

int di[] = {0,0,1,-1}; int dj[]={1,-1,0,0};

struct A {
    int x, y, dis, s, b, j;
};

queue<A> q;

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            scanf(" %c", &tab[i][j]);
            if (tab[i][j] == 'S') {
                sx = i; sy = j;
            }
            if (tab[i][j] == 'E') {
                ex = i; ey = j;
            }
        }
    }

    int dis = 2e9;

    q.push({sx, sy, 0, 0, 0, 0});

    while(!q.empty()){
        auto t = q.front();
        q.pop();

        if (t.x == ex && t.y == ey) {
            dis = min(dis, t.dis);
        }

        if (visited[t.x][t.y][t.s][t.b][t.j]) continue;
        visited[t.x][t.y][t.s][t.b][t.j] = 1;
        //cerr <<  tab[t.x][t.y] << endl;
        if (tab[t.x][t.y] == 'b') t.b = 1;
        if (tab[t.x][t.y] == 'p') t.s = 1;
        if (tab[t.x][t.y] == 'j') t.j = 1;
        for(int d = 0; d < 4; d++){
            if(t.x+di[d] < 0 || t.x+di[d] >= n || t.y+dj[d] < 0 || t.y+dj[d] >= m) continue;
            if (tab[t.x+di[d]][t.y+dj[d]] == '#') continue;
            if (tab[t.x+di[d]][t.y+dj[d]] == 'B' && t.b == 0) continue;
            if (tab[t.x+di[d]][t.y+dj[d]] == 'J' && t.j == 0) continue;
            if (tab[t.x+di[d]][t.y+dj[d]] == 'P' && t.s == 0) continue;
            q.push({t.x+di[d], t.y+dj[d], t.dis+1, t.s, t.b, t.j});
        }
    }
    printf("%d",dis==2e9?-1:dis);
    return 0;
}