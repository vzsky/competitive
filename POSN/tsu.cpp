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

int a[1010][1010];
priority_queue<int> heap;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    lli ans = 0;
    for(int m = 2*n-2; m >= 1; m--){
        for(int i = 0; i < n ; i++){
            int j = m-i;
            if (j >= n || j < 0) continue;
            heap.push(a[i][j]);
            cerr << "push " << i << j << a[i][j] <<endl;
        }
        cerr << "pop " << heap.top() << endl;
        ans += heap.top();
        heap.pop();
    }
    printf("%lld", ans);
    return 0;
}