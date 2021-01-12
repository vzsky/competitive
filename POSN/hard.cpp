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

int a[150100][3];

int main(){
    int n;
    scanf("%d", &n);
    for(int k = 0; k < 3; k++){
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i][k]);
            a[i][k] += a[i-1][k];
        }
    }

    lli mn = 1e18;

    
    for(int i = 1; i <= n; i++){
        lli temp = 0;
        for(int j = i; j <= n; j++){
            temp = a[j][0] - a[i-1][0];
            temp += min(a[i-1][1]-a[0][1]+a[n][2]-a[j][2], a[i-1][2]-a[0][2]+a[n][1]-a[j][1]);
            mn = min(mn, temp);
        }
    }
    for(int i = 1; i <= n; i++){
        lli temp = 0;
        for(int j = i; j <= n; j++){
            temp = a[j][1] - a[i-1][1];
            temp += min(a[i-1][0]-a[0][0]+a[n][2]-a[j][2], a[i-1][2]-a[0][2]+a[n][0]-a[j][0]);
            mn = min(mn, temp);
        }
    }
    for(int i = 1; i <= n; i++){
        lli temp = 0;
        for(int j = i; j <= n; j++){
            temp = a[j][2] - a[i-1][2];
            temp += min(a[i-1][0]-a[0][0]+a[n][1]-a[j][1], a[i-1][1]-a[0][1]+a[n][0]-a[j][0]);
            mn = min(mn, temp);
        }
    }

    printf("%lld\n", mn);

    return 0;
}