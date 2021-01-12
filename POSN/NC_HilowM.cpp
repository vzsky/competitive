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

int a[1000100], del[1000100];

deque <pii> dq;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 0; i < n; i++){
        scanf("%d", &a[i]);
    }
    sort(a, a+n);

    int num = n-k;
    int mn = 2e9;

    for(int i = 0; i < n-1; i++){
        while(!dq.empty() && dq.front().y < i-num) dq.pop_front(); 
        while(!dq.empty() && dq.back().x > a[i+1]-a[i]) dq.pop_back();
        dq.push_back({a[i+1]-a[i], i});

        if (i >= num-1) {
            int c = a[i]-a[i-num+1] + dq.front().x;
            //cerr << c << endl;
            mn = min(mn, c);
        }
    }
    printf("%d", mn);
    return 0;
}