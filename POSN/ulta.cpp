#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define For(i, start, en) for(auto i = start; i <= en; i++)
#define log(x) cerr << #x << " is " << x << endl;
#define logarr(start, en) cerr << #start << " : "; For(it, start, en) cerr << *it << ' '; cerr << endl;
#define logvec(v) cerr << #v << " : "; for(auto x : v) cerr << x << ' '; cerr << endl;
#define logmat(a, m, n) For(i, 0, m) { For(j, 0, n) cerr << a[i][j] << ' '; cerr << endl; }


int mat[1010][1010];
int mic[4][1010][1010];
int a[1010][1010];

int di[] = {0,0,1,-1}; int dj[]={1,-1,0,0};

int mx = 0;
void dfs(int i, int j, int s){
    if (s==mx) return;
    //cerr << i << ' ' << j << endl;
    mat[i][j] = 1;
    for(int d = 0; d < 4; d++){
        //cerr << "in loop " << i << ' ' << j << ' ' << i+di[d] << ' ' << j+dj[d] << endl;
        if (mat[i+di[d]][j+dj[d]] == 1) continue;
        dfs(i+di[d], j+dj[d], s+1);
    }
}

int main(){
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
           char ch;
           scanf(" %c", &ch);
           if (ch=='#') mat[i][j] = -1;
        }
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if (mat[i][j] == -1) { mic[0][i][j]=0; continue; }
            mic[0][i][j] = min(mic[0][i-1][j], mic[0][i][j-1])+1;
        }
    }
    for(int i = 1; i <= r; i++){
        for(int j = c; j > 0; j--){
            if (mat[i][j] == -1) { mic[1][i][j]=0; continue; }
            mic[1][i][j] = min(mic[1][i-1][j], mic[1][i][j+1])+1;
        }
    }
    for(int i = r; i > 0; i--){
        for(int j = 1; j <= c; j++){
            if (mat[i][j] == -1) { mic[2][i][j]=0; continue; }
            mic[2][i][j] = min(mic[2][i+1][j], mic[2][i][j-1])+1;
        }
    }
    for(int i = r; i > 0; i--){
        for(int j = c; j > 0; j--){
            if (mat[i][j] == -1) { mic[3][i][j]=0; continue; }
            mic[3][i][j] = min(mic[3][i+1][j], mic[3][i][j+1])+1;
        }
    }

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            a[i][j] = min(min(mic[0][i][j], mic[1][i][j]), min(mic[3][i][j], mic[2][i][j]));
            mx = max(mx, a[i][j]);
        }
    }

    // logmat(mic[0], r+1, c+1); cerr << endl;
    // logmat(mic[1], r+1, c+1); cerr << endl;
    // logmat(mic[2], r+1, c+1); cerr << endl;
    // logmat(mic[3], r+1, c+1); cerr << endl;


    //cout << mx;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if (a[i][j] == mx) {
                //cout << i << ' ' << j << endl;
                dfs(i, j, 0);
                goto label;
            }
        }
    }

    label : //cout << endl;

    for(int i = 1; i <= r; i++){
        for(int j = 1; j <= c; j++){
            if (mat[i][j]==1) printf("x");
            else if (mat[i][j]==-1)printf("#");
            else printf(".");
        }
        printf("\n");
    }

   return 0;
}

/*
10 10
..#....#..
..........
.#....#...
.....#....
..........
.........#
....#.....
..#..#....
..........
.......#..
*/