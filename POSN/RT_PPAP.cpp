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

int find (long long n){

    //cerr << '\t' << n << endl;
    //if (n <= 0) return 0;
    if (n == 1 || n == 2 || n == 4) return 0;
    if (n == 3) return 1;

    int i = 1;
    while(i < n) i = i*3+1;
    i-=1; i/=3;

    if (n - i == 1) return 0;
    if (n <= i+1+i) return find(n-i-1) ^ 1;
    return find(n-i-i-1);

}

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        long long n;
        scanf("%lld", &n);
        printf(find(n)?"A\n":"P\n");
    }
    return 0;
}