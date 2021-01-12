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


int main(){
    int n;
    lli a;
    scanf("%d", &n);
    for(int i = 0; i < n; i++) {
        scanf("%lld", &a);
    }
    n--;
        if (abs(a-((a/n)*n)) < abs(a-(((a/n)+1)*n))){
            printf("%lld\n", (a/n));
            if (a-((a/n)*n) >= 0)printf("+%lld",a-((a/n)*n));
            else printf("%lld",a-((a/n)*n));
        }
        else if (abs(a-((a/n)*n)) == abs(a-(((a/n)+1)*n))){
            printf("%lld\n", (a/n));
            if (a-((a/n)*n) == a-(((a/n)+1)*n)){

                if (a-((a/n)*n) >= 0)printf("+%lld",a-((a/n)*n));
                else printf("%lld",a-((a/n)*n));
            }
            else {
                printf("%lld", -abs(a-((a/n)*n)));
            }
        }
        else {
            printf("%lld\n", (a/n)+1);

            if (a-(((a/n)+1)*n) >= 0)printf("+%lld",(a-(((a/n)+1)*n)));
            else printf("%lld",(a-(((a/n)+1)*n)));
        }
    return 0;
}