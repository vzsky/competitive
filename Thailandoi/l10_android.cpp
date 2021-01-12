#include<bits/stdc++.h>
using namespace std;

queue<int> q;
int inq[1010], a[1010];
int mem;

int main(){
    int p, s, m;
    scanf("%d %d %d", &p, &s, &m);
    mem = m;
    for(int i = 1; i <= p; i++){
        scanf("%d", &a[i]);
    }
    for(int i = 0; i < s; i++){
        int c;
        scanf("%d", &c);

        if (inq[c]) {
            q.push(c);
            inq[c]++;
        }
        else {
            while (mem < a[c]) {

                while(!q.empty()) {
                    auto t = q.front();
                    if (inq[t] > 1) {
                        q.pop();
                        inq[t]--;
                    }
                    break;
                }

                auto t = q.front();
                q.pop();
                assert(inq[t] == 1);
                // if (inq[t] > 1) cerr << "fuck" << endl;
                mem += a[t];
                inq[t]--;
                // cerr << "-> pop " << t << endl;
            }
            q.push(c);
            inq[c]++;
            mem -= a[c];
        }

        while(!q.empty()) {
            auto t = q.front();
            if (inq[t] > 1) {
                q.pop();
                inq[t]--;
            }
            break;
        }

        // cerr << "mem " << i+1 << ' ' << mem << endl;
    }

    printf("%d", mem);

    return 0;
}