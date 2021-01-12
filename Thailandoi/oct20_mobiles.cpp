#include<bits/stdc++.h>
using namespace std;

int fw[1035][1035];
int s;

void update(int r, int c, int v) {
    for(int i = r; i <= s; i+=(i&-i)){
        for(int j = c; j <= s; j+=(j&-j)){
            fw[i][j] += v;
        }
    }
}
int query(int r, int c) {
    int sum = 0;
    for(int i = r; i > 0; i-=(i&-i)) {
        for(int j = c; j > 0; j-=(j&-j)) {
            sum += fw[i][j];
        }
    }
    return sum;
}

int main(){
    int q, r1, c1, v, r2, c2;
    scanf("%d %d", &q, &s);
    s++;
    assert(q == 0);
    while(1) {
        scanf("%d", &q);
        if (q == 1) {
            scanf("%d %d %d", &r1, &c1, &v);
            r1+=2; c1+=2;
            update(r1, c1, v);
        } 
        if (q == 2) {
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            r1+=2; r2+=2; c1+=2; c2+=2;
            printf("%d\n", query(r2,c2) - query(r2, c1-1) - query(r1-1, c2) + query(r1-1, c1-1));
        }
        if (q == 3) break;
    }
    return 0;
}