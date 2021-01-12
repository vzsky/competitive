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

int kids[10];
int quest[15][5];
char str[5];

int n;
int ch = 0;
void play(int d, int m, int f, int k){
    if (k > n) return;
    if (d == 0 && m == 0 && f == 0) {
        ch = 1; return;
    }
    if (kids[k] & 1) {
        play(d, m, f-1, k+1);
    }
    if (kids[k] & 2) {
        play(d, m-1, f, k+1);
    }
    if (kids[k] & 4) {
        play(d-1, m, f, k+1);
    }
}

int main(){
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        scanf("%d-%d-%d", &quest[i][0], &quest[i][1], &quest[i][2]);
    }
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf(" %s", str);
        int l = strlen(str);
        int lev = 0;
        for(int i = 0; i < l; i++){
            if (str[i] == 'D') lev+=4;
            if (str[i] == 'M') lev+=2;
            if (str[i] == 'F') lev+=1;
        }
        kids[i] = lev;
    }

    for(int i = 0; i < q; i++){
        ch = 0;
        play(quest[i][0], quest[i][1], quest[i][2], 0);
        printf(ch?"Yes\n":"No\n");
    }
    return 0;
}