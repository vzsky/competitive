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

int dev (int n){
    if (n < 10) return 9;
    int cnt = 0;
    int ch = 0;
    while(n++){
        int last = n%10;
        while (last == 0) {
            n/=10;
            last = n%10;
            ch = 1;
        }
        cnt++;
        if (ch) { cnt+=dev(n); break; }
    }
    return cnt;
}

int n;

int main(){
    scanf("%d", &n);
    
    cout << dev(n);
    return 0;
}