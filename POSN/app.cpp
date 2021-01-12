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


int di [] = {1, -1, 0, 0};
int dj [] = {0, 0, 1, -1};

int tab[510][510];
queue <pii> q;
int visited[510][510];

int main(){
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++){
        for(int j = 0; j <m; j++){
            char c;
            scanf(" %c", &c);
            if (c == 'x') tab[i][j] = 1;
        }
    }
    int que;
    scanf("%d", &que);
    for(int i = 0; i < que; i++){
        int x, y;
        scanf("%d %d", &x, &y);

        if (tab[x][y]) {
            printf("0\n");
            continue;
        }
        memset(visited, 0, sizeof visited);

        while(!q.empty()){
            q.pop();
        }

        cerr << x << ' ' << y << endl;
        q.push({x, y});

        while(!q.empty()){
            auto t = q.front(); q.pop();

            if (visited[t.x][t.y]) continue;
            visited[t.x][t.y] = 1;

            if (tab[t.x][t.y] == 1) {
                printf("%d\n", (int)pow((t.x-x),2) + (int)pow((t.y-y), 2));
                break;
            }

            for(int d= 0; d < 4; d++){
                if (!visited[t.x+di[d]][t.y+dj[y]]){
                    q.push({t.x+di[d], t.y+dj[y]});
                }
            }
        }
        tab[x][y] = 1;
    }
    return 0;
}