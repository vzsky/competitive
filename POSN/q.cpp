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

stack <int> s;
lli ans = 0;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        int a;
        scanf("%d", &a);
        if (s.empty()){
            s.push(a);
        }
        else {
            if (a == s.top()){
                ans += s.size();
                // cerr << s.size() <<
                s.push(a);
            }
            else if (a < s.top()){
                ans++;
                s.push(a);
                // cerr << 1 <<
            }
            else if (a > s.top()){
                ans += s.size();
                // cerr << s.size() <<
                while(!s.empty() && a > s.top()){
                    s.pop();
                }
                s.push(a);
                
            }
        }
    }

    printf("%lld\n", ans);

    return 0;
}