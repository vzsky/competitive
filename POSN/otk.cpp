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

char m[1010], n[1010], test[2020];
int k;
int l;
int ch;

int play (int cn, int cm, int i){
    if (i > l) {ch = 1; return 1;}
    if (test[i] == m[cm] && m[cm] == n[cn]){
        return play(cn, cm+1, i+1) | play(cn+1, cm, i+1);
    }
    else if (test[i] == m[cm]) {
        return play(cn, cm+1, i+1);
    }
    else if (test[i] == n[cn]) {
        return play(cn+1, cm, i+1);
    }
    else {
        return 0;
    }
}

int main(){
    cin >> m >> n;
    scanf("%d", &k);
    while(k--){
        cin >> test;
        l = strlen(test);
        
        printf(play(0,0,0)?"Yes\n":"No\n");

    }
    return 0;
}

// like lcs
// -> 2 Dimension O(N^2)