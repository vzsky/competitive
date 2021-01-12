#include<bits/stdc++.h>
using namespace std;

struct A{ 
    int s, e;
    bool operator < (const A & o)const{
        if (s == o.s) return e > o.e;
        return s < o.s;
    }
};
vector <A> car;

int main(){
    int q;
    scanf("%d", &q);
    while(q--){
        int cnt = 0;
        int n, t;
        scanf("%d %d", &n, &t);
        while(n--){
            int a, b;
            scanf("%d %d", &a, &b);
            int e = b*t + a;
            car.push_back({a,e});
        }
        sort(car.begin(), car.end());
        int st = 0; int ls = 0;
        for(auto x : car){

            // if (x.e >= ls && (x.e!=ls || x.s <= st))
            // ( x.e > ls || x.e == ls ) && (!x.e == ls || x.s <= st)

            // x.s <= st while x.e == ls
            // x.e > ls while x.e != ls

            // if 

            if (x.e > ls || (x.e==ls && x.s <= st)) {
                cnt++;
                ls = x.e;
                st = x.s;
            }
        }
        printf("%d\n", cnt);
        car.clear();
    }
return 0;
}