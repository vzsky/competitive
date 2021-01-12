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

int gcd(int a, int b){
    if (b == 0) return a;
    return gcd(b, a%b);
}

int arr[110];

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        int n;
        scanf("%d", &n);
        int mx = 1;
        for(int i = 0; i < n; i++){
            scanf("%d", &arr[i]);
            mx = max(mx, arr[i]);
        }
        int g = arr[0];
        for(int i = 1; i < n; i++){
            g = gcd(g, arr[i]);
            if (g == 1) break;
        }
        // cerr << g << endl;
        int num = (mx/g)-n;
        printf(num&1? "Alive\n":"Dead\n");
    }
    return 0;
}