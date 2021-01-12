#include<bits/stdc++.h>
using namespace std;

#define hs 5000011
#define md 99999989

int hast[hs];

int main(){
    memset(hast, -1, sizeof(hast));
    int ans = 0;
    int p, wp, s, ws;
    scanf("%d %d %d %d", &p, &wp, &s, &ws);
    for(int i = 0; i < p; i++){
        int a;
        scanf("%d", &a);
        for(int j = 0; j < wp; j++){
            int t = a;
            t += ((int)pow(j, 2)%md);
            t%=md;
            while (hast[t] != -1){
                t++;
                t%=md;
            }
            hast[t] = t;
        }
    }
    for(int i = 0; i < s; i++){
        int a;
        scanf("%d", &a);
        for(int j = 0; j < wp; j++){
            int t = a;
            t += ((int)pow(j, 3)%md);
            t%=md;
            int f = t;

            while (hast[t] != -1){
                if (hast[t] == f){
                    ans++;
                    cerr << "ans++" << endl;
                    break;
                }
                t++;
                t%=md;
            }
        }
    }
    printf("%d", ans);
    return 0;
}