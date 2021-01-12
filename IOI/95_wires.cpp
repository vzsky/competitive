#include<bits/stdc++.h>
#include "wirelib.h"
using namespace std;

vector<int> A;
int ANS[100];
vector<int> lamp(100);

int m;
int cnt = 0;

void solve (vector<int> &A, int l, int r) {
    if (l == r) {
        for(auto x : A){
            ANS[x] = l;
        }
        return;
    }
    int mid = (l+r)/2;
    for(int i = l; i <= mid; i++){
        if (lamp[i] == 0) {
            lamp[i] = 1;
            bool s = cmd_C(i);
        }
    }
    for(int i = mid+1; i <= r; i++){
        if (lamp[i] == 1) {
            lamp[i] = 0;
            bool s = cmd_C(i);
        }
    }
    vector<int> Y, N;
    for(int x : A){
        if (cmd_T(x))   Y.push_back(x);
        else            N.push_back(x);
    }
    solve(N, mid+1, r);
    solve(Y, l, mid);
}

int main(){
    m = wire_init();
    for(int i = 1; i <= m; i++){
        A.push_back(i);
    }
    solve(A, 1, m);
    cmd_D(ANS);
    return 0;
}