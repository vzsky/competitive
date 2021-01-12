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

int mic[100100];

int main(){
    int q;
    scanf("%d", &q);

    mic[0] = mic[1] = mic[2] = mic[3] = 1;
    mic[4] = 2;

    for(int i = 5; i <= 100000; i++) {
        mic[i] = mic[i-1] + mic[i-4];
        mic[i]%=100003;
    }

    while(q--){
        int a;
        scanf("%d", &a);
        printf("%d\n", mic[a]);
    }
    return 0;
}