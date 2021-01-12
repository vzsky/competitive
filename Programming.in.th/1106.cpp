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

int fw[200200];

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        for(int j = i; j <= n; j+=(j&-j)){
            fw[j]++;
        }
    }

    int sum = 0;
    // for(int i = n; i > 0; i-=(i&-i)){
    //     sum+=fw[i];
    // } // how many behind
    // cerr << sum << endl;

    int now = k;
    int mx = 1;
    while(mx){
        for(int i = now; i <= n; i+=(i&-i)){
            fw[i]--;
        } // clear that person out
        sum = 0;
        for(int i = now; i > 0; i-=(i&-i)){
            sum+=fw[i];
        } // how many behind
        mx = 0;
        for(int i = n; i > 0; i-=(i&-i)){
            mx+=fw[i];
        } // how many left
        int l = 0, r = n, finding = sum+now;
        if (finding > mx)finding %= mx;
        if (finding == 0) finding += mx;
        while(l < r) {
            int mid = (l+r)/2;
            int cons = 0;
            for(int i = mid; i > 0; i-=(i&-i)){
                cons += fw[i];
            }
            if (cons >= finding) r = mid;
            else                 l = mid+1;
        }
        now = l;
        if (mx == 1) break;

    }
    printf("%d", now);
    return 0;
}