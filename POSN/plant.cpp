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

pii plant[10010];

lli q = -2e9;

int main(){
    int n, a, b;
    scanf("%d %d %d", &n, &a, &b);

    for(int i = 0; i < n; i++){
        scanf("%d %d", &plant[i].x, &plant[i].y);
    }

    sort(plant, plant+n);

    for(int j = 0; j < n; j++){
        lli sigmar = 0;
        lli loq = -2e9;
        int mn = 2e9, mx = -2e9;

        for(int i = j ; i < n ; i++){
            sigmar += plant[i].y;
            mn = min(mn, plant[i].x);
            mx = max(mx, plant[i].x);

            lli now = a*(sigmar) - b*(mx-mn);
            loq = max(loq, now);
        }
        q = max(q, loq);
    }

    // sigmar = 0;
    // mn = 2e9; mx = -2e9;
    // for(int i = n-1 ; i >= 0 ; i--){
    //     sigmar += plant[i].y;
    //     mn = min(mn, plant[i].x);
    //     mx = max(mx, plant[i].x);

    //     lli now = a*(sigmar) - b*(mx-mn);
    //     if (now >= q) q = now;
    //     else break;
    // }

    printf("%lld", q);

    return 0;
}