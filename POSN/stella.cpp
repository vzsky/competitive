#include<bits/stdc++.h>
using namespace std;

struct stone {
    long long int p, h, q, l;
    bool operator < (const stone & o) const {
        if (p != o.p) return p < o.p;
        return q > o.q;
    }
};

priority_queue <stone> heap;

long long int ans = 0 ,amount = 0;

int main(){
    long long int k;
    long long int i;
    scanf("%lld", &k);
    for(i = 1; i <= k; i++){
        char o;
        scanf(" %c", &o);
        if (o == 'c') { // Collect
            char t;
            scanf(" %c", &t);
            if (t == 'n') { // Normal
                long long int point;
                scanf("%lld", &point);
                heap.push({point, 1000100, i, 0});
                //cout << "addn " << point << endl;
            }
            else if (t == 'r') { //Radioactive
                long long int point, half;
                scanf("%lld %lld", &point, &half);
                heap.push({point, half, i, i});
                //cout << "addr " << point << endl;
            }
        }
        else if (o=='u') { // Use 
            //cout << "trying ";
                while (1){
                    if (heap.empty()) break;
                    auto pre = heap.top();
                    heap.pop();
                    if (pre.h > 1000000 || !(i-pre.l >= pre.h)) {
                        ans += pre.p; break;
                    }
                    //cout << pre.q << " top : " << pre.p << endl;
                    while (i-pre.l >= pre.h) {
                        pre.p = pre.p /2;
                        pre.l += pre.h;
                    }
                    if (pre.p != 0){
                        heap.push(pre);
                        continue;
                    }
                }
        }
    }

    i--;
    amount = 0;


    while (!heap.empty())
    {
        auto t = heap.top();
        heap.pop();

        // int per =  ( k-1-t.l -t.h ) / t.h ;
        // t.p = t.p >> per;
        while (k-1-t.l >= t.h) {
            t.p = t.p /2;
            t.l += t.h;
        }

        if (t.p == 0) continue;
        amount++;
    }

    printf("%lld\n%lld",ans, amount);
    return 0;
}