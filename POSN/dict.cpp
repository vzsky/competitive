#include<bits/stdc++.h>
using namespace std;

int a[310];
int qs[310];

int h[310][310];

int n;

#define log(x) cerr << x << endl;

int play(int l, int r){

    if (h[l][r]!=-1) return h[l][r];

    int mn = 2e9;
    if (l > r) return 0;
    if (l == r) {
        return h[l][r] = a[l];
    }

    for(int i = l; i <= r; i++){ // i as node at level $level;
        int hard = 0;

        hard += play(l, i-1);
            //log("call " << l << ' ' << r);
        hard += play(i+1, r);
            //log("call " << l << ' ' << r);
        hard += qs[r]-qs[l-1];

        
        mn = min(mn, hard);
    }
    return h[l][r] = mn;
}

int main(){
    memset(h, -1, sizeof h);
   scanf("%d", &n);
   for(int i = 1; i <= n; i++){
       scanf("%d", &a[i]);
       qs[i]=a[i]+qs[i-1];
   }

//    for(int s = 1; s <= n; s++){
//        for(int v = 1; v <= n; v++){
//            for(int l = 0; l < n; l++){
//                int r = s-l-1;
//                if (r >= n) continue;
//                if (l == r) { h[l][r][v] = a[l]*level; continue; }
               
//                for(int i = )
//            }
//        }
//    }
   cout << play(1, n) << endl;
   return 0;
}
/* 5 10 5 17 2 6 */