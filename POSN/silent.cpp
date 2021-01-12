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

deque <int> mnwd, mxwd;
int a[1000100];

int main(){
    int n, m, c;
    scanf("%d %d %d", &n, &m, &c);
    int ch = 1;
    for(int i = 1; i <= n; i++){
        scanf("%d", &a[i]);
        while(!mxwd.empty() && a[i] >= a[mxwd.back()]) mxwd.pop_back();
        while(!mnwd.empty() && a[i] <= a[mnwd.back()]) mnwd.pop_back();

        while(!mxwd.empty() && mxwd.front() <= i-m) mxwd.pop_front();
        while(!mnwd.empty() && mnwd.front() <= i-m) mnwd.pop_front();

        mxwd.push_back(i);
        mnwd.push_back(i);
        int range = a[mxwd.front()] - a[mnwd.front()];
        if ( i >= m && range <= c) {
            printf("%d\n", i-m+1);
            ch = 0;
        }
    }
    if (ch) printf("NONE");
    return 0;
}