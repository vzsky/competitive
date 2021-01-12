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

int a[300300];
int b[300300];
priority_queue<pii> heap;

int main(){
    int n ,k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

    heap.push({2e9,0});
    for(int i = 1; i <= n; i++){
        while (heap.top().y < i-k) heap.pop();
        b[i] = min(a[i], heap.top().x);
        heap.push({b[i],i});
    }
    while (heap.top().y < n+1-k) heap.pop();
    b[n+1] = heap.top().x;
    cout << b[n+1];
    return 0;
}