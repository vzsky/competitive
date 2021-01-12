#include<bits/stdc++.h>
using namespace std;
#include"alienslib.h"
// #include "alienslib.cpp"

// int examine(int x, int y) {
//     string res;
//     cout << "examine " << x << ' ' << y << endl;
//     cin >> res;
//     return res == "true";
// }
// void solution (int x, int y) {
//     cout << "solution " << x << ' ' << y << endl;
// }
// void get_size_and_start(int &N, int &X0, int &Y0){
//     scanf("%lld %lld %lld", &N, &X0, &Y0);
// }

long long n;

long long bsearch (bool axis, bool high, long long l, long long r, int st){
    if (l == r) return l;
    int res;
    if (high) {
        long long mid = (l+r+1)/2;
        if (axis) res = examine(mid, st);
        else      res = examine(st, mid);
        assert(res != -1);
        if (res) return bsearch(axis, high, mid, r, st);
        else     return bsearch(axis, high, l, mid-1, st);
    }
    else {
        long long mid = (l+r)/2;
        if (axis) res = examine(mid, st);
        else      res = examine(st, mid);
        assert(res != -1);
        if (res) return bsearch(axis, high, l, mid, st);
        else     return bsearch(axis, high, mid+1, r, st);
    }
}

long long bound (bool axis, bool high, long long x, long long y, long long a = 1) {
    // if axis == 1, y must be static and vice versa
    if (x > n) return n;
    if (x <= 0) return 0;
    
    if (high) {
        // operator +
        if (axis) {
            int res = examine(x+a, y);
            assert(res != -1);
            if (res) return bound(axis, high, x+a, y, a<<1);
            else     return bsearch(axis, high, x, x+a, y);
        }
        else {
            int res = examine(x, y+a);
            assert(res != -1);
            if (res) return bound(axis, high, x, y+a, a<<1);
            else     return bsearch(axis, high, y, y+a, x);
        }
    }
    else {
        // operator -
        if (axis) {
            int res = examine(x-a, y);
            assert(res != -1);
            if (res) return bound(axis, high, x-a, y, a<<1);
            else     return bsearch(axis, high, x-a, x, y);
        }
        else {
            int res = examine(x, y-a);
            assert(res != -1);
            if (res) return bound(axis, high, x, y-a, a<<1);
            else     return bsearch(axis, high, y-a, y, x);
        }
    }
}

int main(){
    long long x, y;
    int N, X, Y;
    get_size_and_start(N, X, Y);
    n = N; x = X, y = Y;
    long long xh = bound(1, 1, x, y);
    long long yh = bound(0, 1, x, y);
    long long xl = bound(1, 0, x, y);
    long long yl = bound(0, 0, x, y);
    long long xc = (xh+xl+1)/2;
    long long yc = (yh+yl+1)/2;
    // cerr << xc << ' ' << yc << endl;
    long long size = xh-xl+1;
    assert(size == yh-yl+1);
    
    vector<pair<int,int>> around, twostep;
    for(int i = -1; i <= 1; i+=2){
        for(int j = -1; j <= 1; j+=2){
            if (examine(xc+i*size, yc+j*size) == 1) around.push_back({i, j});
            if (examine(xc+i*size*2, yc+j*size*2)) twostep.push_back({i, j});
        }
    }

    if (around.size() == 1) {
        solution(xc+around[0].first*size*2, yc+around[0].second*size*2);    
        return 0;
    }
    if (around.size() == 2) {
        if (around[0].first == around[1].first) {
            solution(xc+around[0].first*2*size, yc);
            return 0;
        }
        if (around[0].second == around[1].second) {
            solution(xc,around[0].second*2*size+yc);
            return 0;
        }
    }
    if (twostep.size() == 1) {
        solution(xc+twostep[0].first*size, yc+twostep[0].second*size);
        return 0;
    }
    else {
        solution(xc, yc);
        return 0;
    }
    assert(false);
    return 0;
}