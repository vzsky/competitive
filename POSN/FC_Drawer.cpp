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

int p[300100];
int amn[300100];

int find(int n){
    if (p[n] == n) return n;
    return p[n] = find(p[n]); 
}

int main(){
    int n, l;
    scanf("%d %d", &n, &l);

    for(int i = 0; i <= l; i++) { p[i] = i; amn[i] = 1; }

    for(int i = 0; i < n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        if (amn[find(a)] == 0 &&amn[find(b)] == 0) { printf("No\n"); continue; }
        if (find(a) != find(b)){
            amn[find(b)] += amn[find(a)];
            p[find(a)] = p[find(b)];
        }
        amn[find(b)]--;
        //cerr << amn[find(b)] << endl;
        printf("Yes\n");
    }
    return 0;
}