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

char str[500500];
deque<int> wd;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    cin >> (str+1);
    int next = k+1;
    int expire = 1;
    for(int i = 1; i <= n; i++){
        while(!wd.empty() && str[wd.back()]-'0' < str[i]-'0') wd.pop_back();
        while(!wd.empty() && wd.front() < expire) wd.pop_front();
        wd.push_back(i);
        if (i == next){
            printf("%c", str[wd.front()]);
            k-=wd.front()-expire;
            expire = wd.front()+1;
            // cerr << next << ' ' << k << endl;
            next =wd.front()+k+1;
        }
    }
    return 0;
}