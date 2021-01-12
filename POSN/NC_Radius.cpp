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

int a[200100];
int ans[200100];
int ans1[200100];
stack<int> s;

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        int n;
        scanf("%d", &n);
        for(int i = 1; i <= n; i++){
            scanf("%d", &a[i]);
            a[i+n] = a[i];
        }
        a[2*n+1] = a[0] = 2e9;
        for(int i = 0; i <= 2*n+1; i++){
            while(!s.empty() && a[s.top()] < a[i]) {
                ans[s.top()] = i-s.top()-1;
                //cerr << s.top() << ' ' << i-s.top()-1 << endl;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = 2*n+1; i >= 0; i--){
            while(!s.empty() && a[s.top()] < a[i]) {
                ans1[s.top()] = s.top()-i-1;
                //cerr << s.top() << ' ' << s.top()-i << endl;
                s.pop();
            }
            s.push(i);
        }
        while(!s.empty()) s.pop();
        for(int i = 1; i <= n; i++){
            int an = min(ans1[i+n], ans[i]);
            printf("%d ", an>((n-1)>>1)?((n-1)>>1):an);
        }
        printf("\n");
        memset(ans, 0, sizeof ans);
        memset(ans1, 0, sizeof ans1);
    }
    return 0;
}