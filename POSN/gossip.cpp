#include<bits/stdc++.h>
using namespace std;
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

char temp[110];
char inp[110];

int main(){
    int n;
    scanf("%d", &n);
    cin >> temp;
    int tl = strlen(temp);

    if (tl == 1 && temp[0] == '*'){
        for(int i = 0; i < n; i++) printf("Yes\n");
        return 0;
    }

    for(int i = 0; i < n; i++){

        cin >> inp;
        int l = strlen(inp);

        int ch = 0, chk = 0;

        if (l < tl-1) { printf("No\n"); continue; }

        //cerr << l-1;
        for(int j = l-1, k = tl-1; j >= 0 && k >= 0; j--, k--){
            //cerr << temp[k] << ' ' << inp[j] << endl;
            if (j == 0 && temp[k-1] == '*') { ch = 1; break; }
            if (temp[k] != inp[j] && temp[k] != '*') break;
            if (temp[k] == '*') { ch = 1; break; }
        }
        for(int j = 0, k = 0; j <= l && j-l+tl <= tl; j++, k++){
            //cerr << temp[k] << ' ' << inp[j] << endl;
            if (temp[k] != inp[j] && temp[k] != '*') break;
            if (temp[k] == '*') { chk = 1; break; }
        }

        //cerr << ch << ' ' << chk ;

        if (temp[0] == '*'){
            if (ch == 1) printf("Yes\n");
            else printf("No\n");
        }
        else if (temp[l-1] == '*'){
           if (chk == 1) printf("Yes\n");
           else printf("No\n");
        }
        else {
            if (ch && chk) printf("Yes\n");
            else printf("No\n");
        }
        
    }
    return 0;
}