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

int pos[110];
vi g[110];
int visited[110];

int num;
void play(int n) {
    if (visited[n]) return;
    visited[n] = 1;
    num++;
    for(auto x : g[n]) play(x);
} 

int GCD (int a, int b) {
    // a > b;
    if (b == 0) return a;
    return GCD(b, a%b);
}

int LCM (int a, int b) {
    return (a*b)/GCD(a, b);
}

int main(){
    int lcm = 1;
    int n, m;
    scanf("%d %d", &n, &m);
    for(int i = 1; i <= n; i++) pos[i] = i;
    for(int i = 0; i < m; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        swap(pos[a], pos[b]);
    }
    for(int i = 1; i <= n; i++){
        g[pos[i]].pb(i);
        //cerr << pos[i] << ' ' << i  <<endl;
    }

    for(int i = 1; i <= n; i++){
        if (!visited[i]) {
            num = 0;
            play(i);
            lcm = LCM(lcm, num);
            //cerr << i << ' ' << num << endl;
        }
    }
    printf("%d", lcm);
    return 0;
}