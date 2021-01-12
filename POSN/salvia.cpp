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

int words[30];

int ans=0;
int n;

void play(int state, int b){
    if (state == n) {
        // ans++;
        if (b == (1<<26)-1) ans++;
        return;
    }
    play(state+1, b);
    play(state+1, b|words[state]);
}

char w[110];
int main(){
    int q;
    scanf(" %d", &q);
    while(q--) {
        scanf(" %d", &n);

        memset(words, 0, sizeof words);

        for(int i = 0; i < n; i++){
            scanf(" %s", w);
            int l = strlen(w);
            for(int j = 0; j < l; j++){
                words[i] |= (1 << (w[j]-'a'));
            }
        }
        ans = 0;
        play(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}