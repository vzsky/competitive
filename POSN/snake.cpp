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

char tab[1010][1010];
bool walk = 1;
lli ans = 0;
int jelly, maxjelly;

int main(){
    int r, c;
    scanf("%d %d", &r, &c);
    for(int i = 0; i < r; i++){
        for(int j = 0; j < c; j++){
            scanf(" %c", &tab[i][j]);
            if (tab[i][j] == 'J') maxjelly++;
        }
    }

    int CurrentSnake = 0;

    for(int i = r-1; i >= 0; i--){

        if (tab[i][CurrentSnake] == 'J') jelly++;
        tab[i][CurrentSnake] = '.';

        if (walk) {
            for(int j = CurrentSnake+1; j < c; j++){
                if (tab[i][j] == 'J') {
                    jelly++;
                    ans += j-CurrentSnake;
                    CurrentSnake = j;
                    tab[i][j] = '.';
                }
                if (tab[i-1][j] == 'J') {
                    ans += j-CurrentSnake;
                    CurrentSnake = j;
                }
            }
        }
        else {
            for(int j = 0; j < CurrentSnake; j++){
                if (tab[i][j] == 'J') {
                    jelly++;
                    ans += CurrentSnake-j;
                    CurrentSnake = j;
                    tab[i][j] = '.';
                }
                if (tab[i-1][j] == 'J') {
                    ans += CurrentSnake-j;
                    CurrentSnake = j;
                }
            }
        }

        if (jelly == maxjelly) {
            printf("%lld", ans);
            return 0;
        }

        // cerr << ans << endl;
        walk^=1;
        ans++;
    }
    printf("%lld", ans);
    return 0;
}