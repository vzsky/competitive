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

int a[200200];
vector <int> ans;

int main(){
    int n;
    scanf("%d", &n);
    For(i, 0, n-1){
        scanf("%d", &a[i]);
    }
    int l = 0, r = n-1;
    int last = -1;
    while (l <= r){
        if (last == -1){
            if (a[l] < a[r]){
                last = a[l];
                ans.pb(1);
                l++;
                continue;
            }
            else {
                last = a[r];
                ans.pb(0);
                r--;
                continue;
            }
        }

        if (a[l] < a[r]) {
            if(a[l] > last){
                last = a[l];
                ans.pb(1);
                l++;
                continue;
            }
            else if (a[r]>last) {
                last = a[r];
                ans.pb(0);
                r--;
                continue;
            }
        }
        else {
            if (a[r]>last) {
                last = a[r];
                ans.pb(0);
                r--;
                continue;
            }
            else if(a[l] > last){
                last = a[l];
                ans.pb(1);
                l++;
                continue;
            }
        }
        break;
    }
    cout << ans.size() << endl;
    for(auto x : ans){
        printf(x?"L":"R");
    }
    return 0;
}