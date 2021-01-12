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

int a[6000100];

int main(){
    int n, w;
    scanf("%d %d", &n, &w);
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 1; i <= n+w; i++){
        a[i]+=a[i-1];
    }
    int mx = -2e9;
    int len = w;
    //logarr(a, a+n);
    for(int i = 1; i <= n+w-1; i++){ //end at i;
        for(int j = 1; j <= w; j++){ // long j
            if (i-j < 0 || i-j >= n) continue;
            if (a[i]-a[i-j] == mx) {
                len = min(len, j);
            }
            if (a[i]-a[i-j] > mx) {
                mx = a[i]-a[i-j];
                len = j;
            }
        }
    }

    if (mx <= 0) {
        printf("0\n0");
    }
    else {
        printf("%d\n%d", mx, len);
    }
    return 0;
}

// Dynamic programming + sliding window