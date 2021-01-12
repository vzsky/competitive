#include<bits/stdc++.h>
using namespace std;

int main(){
    int n, s;
    scanf("%d %d", &n, &s);
    double arrive = 0;
    for(int i = 0; i < n; i++){
        double t, u;
        scanf("%lf %lf", &t, &u);
        double time = arrive-t;
        double v;
        if (time < 0) {
            printf("0\n");
            goto term;
        }
        v = floor(s/(arrive-t));
        if (v > u) printf("0\n");
        else {printf("%.0lf\n", u-v); u =v;}
        term :
        arrive = s/u + t;
    }
    return 0;
}