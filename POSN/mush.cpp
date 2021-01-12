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

int h[100100];
int v[100100];
map <int,int> d;
map <int, int> d2;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        int x, y;
        scanf("%d %d", &x, &y);
        h[x]++;
        v[y]++;
        d[x-y]++;
        d2[x+y]++;
        if (h[x] >= k || v[y] >= k || d[x-y] >= k || d2[x+y]>=k) {
            printf("%d", i+1);
            return 0;
        }
    }
    printf("-1");
    return 0;
}