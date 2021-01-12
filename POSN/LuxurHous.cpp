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

priority_queue <int> heap;
vector <int> g[100100];
int ans = 0;
long long sum = 0;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i <n ;i++){
        int a, b;
        scanf("%d %d", &a, &b);
        g[a].pb(b);
    }
    for(int i = 100000; i >= 1; i--){
        for(auto x : g[i]){
            heap.push(x);
        }
        if (!heap.empty()){
            sum+=heap.top(); heap.pop();
            ans++;
        }
    }
    printf("%lld\n%d", sum, ans);
    return 0;
}