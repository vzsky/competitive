#include<bits/stdc++.h>
using namespace std;

int now = 0;

struct pak {
    int type, bea, date, c;
    bool operator < (pak o) const {
        // if (now > date || type == 1) bea = 0;
        // if (now > date || type == 3) bea = c;
        if (bea != o.bea) return bea > o.bea;
        return type < o.type;
    }
};

priority_queue <pak> heap;
priority_queue <int> d;

int main(){
    int n; 
    int ans = 0;
    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        now = i;

        if (!d.empty()){
        if (now >= d.top()*-1){
            //cout << "d" << heap.top().date << ' ' << now;
            while(!heap.empty() && heap.top().date <= now){
                auto pre = heap.top();
                //cout << pre.type;
                if (pre.type == 1) heap.pop();
                else if (pre.type == 3) {
                    pre.bea = pre.c;
                    pre.date = n+1;
                    heap.pop();
                    heap.push(pre);
                }
            }
        }
        }

        int o;
        scanf("%d", &o);{
            if (o==1){
                int a, b;
                scanf("%d %d", &a, &b);
                heap.push({1, a, b, 0});
                d.push(-1*b);
            }
            if (o==2){
                int a;
                scanf("%d", &a);
                heap.push({2, a, n+1, 0});
            }
            if (o==3){
                int a, b, c;
                scanf("%d %d %d", &a, &b, &c);
                heap.push({3, a, b, c});
                d.push(-1*b);
            }
            if (o==4){
                if (heap.empty()) printf("GREAN");
                else {
                    printf("%d", heap.top().bea);
                    heap.pop();
                }
            }
        }
    }
    return 0;
}