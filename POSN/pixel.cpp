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

int a[515][515];

#define area(a, b, c, d) qs[c][d]-qs[c][b-1]-qs[a-1][d]+qs[a-1][b-1];
#define mx(a, b, c, d) (a>b?0:1)
#define mn(a, b, c, d) min(min(a, b), min(c, d))


int paint (int a, int b, int aa, int bb){
    if (a==aa && b==bb) return 0;

    int ma = (a+aa)/2;
    int mb = (b+bb)/2;

    int Mx = mx(area(a, b, ma, mb), area(ma+1, b, aa, mb), area(a, mb+1, ma, bb), area(ma+1, mb+1, aa, bb));
    int Mn = mn(area(a, b, ma, mb), area(ma+1, b, aa, mb), area(a, mb+1, ma, bb), area(ma+1, mb+1, aa, bb));

    if (area(a, b, ma, mb) == Mx) {
        if 
        if 
        if
    }
    if {
        if
        if
        if
    }

    paint(a, b, ma, mb);
    paint(ma+1, b, aa, mb);
    paint(a, mb+1, ma, bb);
    paint(ma+1, mb+1, aa, bb);
    
}

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &qs[i][j]);
            qs[i][j] += qs[i-1][j] + qs[i][j-1] - qs[i-1][j-1];
        }
    }

    paint(1,1,n,n);

    return 0;
}