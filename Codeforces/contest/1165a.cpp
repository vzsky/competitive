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

string s;

int ans;
int main(){
    int n, x, y;
    scanf("%d %d %d", &n, &x, &y);
    cin >> s;
    for(int i = n-1, j = 0; i >= 0; i--, j++){
        if (j == y && s[i] != '1') { ans++; continue; }
        if (j == y) continue;
        if (j >= x) break;
        if (s[i] != '0')  ans++; //cerr << "ans++ " << j << ' ' << i << endl; }
    }
    printf("%d", ans);
    return 0;
}