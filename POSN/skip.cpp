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

int a[1000100];

int main(){
    int n, k, p;
    scanf("%d %d %d", &n, &k, &p);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    int l = 1; int r = 1e9;
    while(l < r) {
        int mid = (l+r)>>1;

        int j = 0;
        for(int i = 0; i < n;){
            if (a[i] > mid) { i+=p; j++; }
            else i++;
        }

        if (j > k) l = mid+1;
        else r = mid;
    }
    printf("%d", l);
    return 0;
}