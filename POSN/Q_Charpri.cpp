#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
#define pb push_back
#define For(a,b) for(int a = 0; a < b; a++)
#define _cerrheader(a) cerr << #a << " : "
#define log(a) _cerrheader(a) << a
#define logarr(a, b) { _cerrheader(a); For(i, b) cerr << a[i] << ' ';}
#define logvec(v) { _cerrheader(a); for(auto i : v) cerr << v[i] << ' ';}
#define logmat(a,b,c) For(i,b) { For(j,c) cerr << a[i][j] << ' ';  cerr << endl;}
typedef pair<int,int> pii;
typedef long long lli;
typedef vector<int> vi;

deque<int> alpha[30];
lli fw[300300];

int main(){
    int mode;
    char list[300100];
    char word[100100];
    scanf("%d %s %s", &mode, list, word);
    int l = strlen(list);
    for(int i = 0; i < l; i++){
        alpha[list[i]-'a'].pb(i);
    }
    // sorted
    if (mode == 0) {
        lli ans = 0;
        int lw = strlen(word);
        for(int i = 0; i < lw; i++){
            if (alpha[word[i]-'a'].empty()) {
                printf("-1");
                return 0;
            }
            ans += 1+alpha[word[i]-'a'].front();
            alpha[word[i]-'a'].pop_front();
        }
        printf("%lld", ans);
        return 0;
    } 
    if (mode == 1) {
        lli ans = 0;
        int lw = strlen(word);
        for(int i = 0; i < lw; i++){
            if (alpha[word[i]-'a'].empty()) {
                printf("-1");
                return 0;
            }
            lli f = alpha[word[i]-'a'].front();
            alpha[word[i]-'a'].pop_front();
            // cout << f << endl;
            ans += 1+f;
            for(int j = f+1; j > 0; j-=(j&-j)) {
                ans-=fw[j];
            }
            for(int j = f+1; j <= l+1; j+=(j&-j)) {
                fw[j]++;
            }
        }
        printf("%lld", ans);
        return 0;
    } 
    return 1;
}