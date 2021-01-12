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

int a[10000100];
int p[10000100];

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        char c;
        scanf(" %c", &c);
        a[i] = c-'0';
    }
    for(int i = 1; i <= n; i++){
        a[i+n] = a[i];
    }
    int j = 0;
    for(int i = 2; i <= 2*n; i++){
        while(j > 0 && a[i] != a[j+1]) j = p[j];
        if (a[i] == a[j+1]) j++;
        p[i] = j;
        if (j == n) {printf("%d", i-n);return 0;}
    }
    return 0;
}