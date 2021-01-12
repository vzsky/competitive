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

int fw[2010][2010];

int que (int x, int y){
    int ans = 0;
    for(int i = x; i > 0; i-= (i&-i)){
        for(int j = y; j > 0; j-=(j&-j)){
            ans += fw[i][j];
            //cerr << i << ' ' << j << endl;
        }
    }
    return ans;
}

int n;

int main(){
    int n, cmd;
    while(1){
        scanf("%d", &cmd);
        if (cmd == 0){
            scanf("%d", &n);
            continue;
        }
        if (cmd == 1){
            int a, b, c;
            scanf("%d %d %d", &a, &b, &c);
            a++; b++;
            //cerr << c;
            for(int i = a; i <= n; i+= (i&-i)){
                for(int j = b; j <= n; j+= (j&-j)){
                    fw[i][j] += c;
                    //cerr << i << j << endl;
                }
            }

        }
        if (cmd == 2){
            int x1, x2, y1, y2;
            scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
            x2++;y2++;
            printf("%d\n", que(x2,y2) - que(x2, y1) - que(x1, y2) + que(x1,y1));
            //cerr << que(x2,y2)  <<  que(x2, y1) <<  que(x1, y2) << que(x1,y1);
        }
        if (cmd == 3) break;
    }
    return 0;
}