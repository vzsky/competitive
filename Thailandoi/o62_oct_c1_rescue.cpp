#include <bits/stdc++.h>
#include "rescuelib.h"
// #include "rescuelib.cpp"

using namespace std;

int r,c;

int main() {
    get_size(r,c);

    int d1 = drop_robot(1, 1);
    int d2 = drop_robot(1, c);
    int d3 = drop_robot(r, 1);
    int d4 = drop_robot(r, c);

    int cnt = (d1==-1)+(d2==-1)+(d3==-1)+(d4==-1);
    int yes;
    if (d1 != -1) yes = 1;
    if (d2 != -1) yes = 2;
    if (d3 != -1) yes = 3;
    if (d4 != -1) yes = 4;
    if (cnt < 3) {
        for(int i = 1; i <= r; i++) {
            for(int j = 1; j <= c; j++) {
                if (abs(i-1)+abs(j-1) == d1 || d1==-1)
                if (abs(i-1)+abs(j-c) == d2 || d2==-1) 
                if (abs(i-r)+abs(j-1) == d3 || d3==-1)
                if (abs(i-r)+abs(j-c) == d4 || d4==-1) 
                answer(i, j);
            }
        }
    }

    if (cnt == 3) {
        int L = 1, R = c, sure = 1;
        if (yes == 1 || yes == 2) {
            if (yes == 1) sure = 1;
            else sure = r;
            while(L < R) {
                int mid = (L+R+1)/2;
                int d = drop_robot(mid, sure);
                if (d != -1) L = mid;
                else         R = mid-1;
            }
        }
        if (yes == 3 || yes == 4) {
            if (yes == 3) sure = 1;
            else sure = r;
            while(L < R) {
                int mid = (L+R)/2;
                int d = drop_robot(mid, sure);
                if (d != -1) R = mid;
                else         L = mid+1;
            }
        }
        int x = L;
        L = 1, R = r;
        if (yes == 1 || yes == 3) {
            if (yes == 1) sure = 1;
            else sure = c;
            while(L < R) {
                int mid = (L+R+1)/2;
                int d = drop_robot(sure, mid);
                if (d != -1) L = mid;
                else         R = mid-1;
            }
        }
        if (yes == 2 || yes == 4) {
            if (yes == 2) sure = 1;
            else sure = c;
            while(L < R) {
                int mid = (L+R)/2;
                int d = drop_robot(sure, mid);
                if (d != -1) R = mid;
                else         L = mid+1;
            }
        }
        int y = L;

        if (yes == 1) {
            int D1 = drop_robot(1, 1);
            int D2 = drop_robot(1, x);
            int D3 = drop_robot(y, 1);
            int D4 = drop_robot(y, x);
            for(int i = 1; i <= r; i++) {
                for(int j = 1; j <= c; j++) {
                    if (abs(i-1)+abs(j-1) == D1 || D1==-1)
                    if (abs(i-1)+abs(j-x) == D2 || D2==-1) 
                    if (abs(i-y)+abs(j-1) == D3 || D3==-1)
                    if (abs(i-y)+abs(j-x) == D4 || D4==-1) 
                    answer(i, j);
                }
            }
        }
        if (yes == 2) {
            swap(x, y);
            int D1 = drop_robot(1, x);
            int D2 = drop_robot(1, c);
            int D3 = drop_robot(y, x);
            int D4 = drop_robot(y, c);
            for(int i = 1; i <= r; i++) {
                for(int j = 1; j <= c; j++) {
                    if (abs(i-1)+abs(j-x) == D1 || D1==-1)
                    if (abs(i-1)+abs(j-c) == D2 || D2==-1) 
                    if (abs(i-y)+abs(j-x) == D3 || D3==-1)
                    if (abs(i-y)+abs(j-c) == D4 || D4==-1) 
                    answer(i, j);
                }
            }
        }
        if (yes == 4) {
            swap(x, y);
            int D1 = drop_robot(y, x);
            int D2 = drop_robot(y, c);
            int D3 = drop_robot(r, x);
            int D4 = drop_robot(r, c);
            for(int i = 1; i <= r; i++) {
                for(int j = 1; j <= c; j++) {
                    if (abs(i-y)+abs(j-x) == D1 || D1==-1)
                    if (abs(i-y)+abs(j-c) == D2 || D2==-1) 
                    if (abs(i-r)+abs(j-x) == D3 || D3==-1)
                    if (abs(i-r)+abs(j-c) == D4 || D4==-1) 
                    answer(i, j);
                }
            }
        }
        if (yes == 3) {
            int D1 = drop_robot(y, 1);
            int D2 = drop_robot(y, x);
            int D3 = drop_robot(r, 1);
            int D4 = drop_robot(r, x);
            for(int i = 1; i <= r; i++) {
                for(int j = 1; j <= c; j++) {
                    if (abs(i-y)+abs(j-1) == D1 || D1==-1)
                    if (abs(i-y)+abs(j-x) == D2 || D2==-1) 
                    if (abs(i-r)+abs(j-1) == D3 || D3==-1)
                    if (abs(i-r)+abs(j-x) == D4 || D4==-1) 
                    answer(i, j);
                }
            }
        }


    }

    return 0;
}