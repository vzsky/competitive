#include<bits/stdc++.h>
using namespace std;

#define x first
#define y second
typedef long long int lli;
typedef pair<int,int> pii;

struct song {
    int t, b;
    bool operator < (const song & o) const {
        return b > o.b;
    }
};

song s[300300];
lli mic[1000100];
lli sum[300300];

priority_queue<int> heap;

int main(){
    int n, k;
    scanf("%d %d", &n, &k);
    for(int i = 1; i <= n; i++){
        int a, b;
        scanf("%d %d", &a, &b);
        s[i] = {a,b};
    }
    sort(s+1, s+n+1);

    for(int i = 1; i <= k-1; i++)
    {
        sum[i] = s[i].t+sum[i-1];
        heap.push(-1*s[i].t);
    }
    for(int i = k; i <= n; i++)
    {
        heap.push(-1*s[i].t);
        int tp = heap.top(); heap.pop();
        sum[i] = sum[i-1]+tp+s[i].t;
    }

    for(int i = 1; i <= n; i++)
    {
        mic[s[i].b] = max( sum[i-1] + s[i].t ,mic[s[i].b]);
    }

    lli mx =0;
    for(int i = 1; i <= 1000000; i++)
    {
        mx = max(mx, (lli) i*mic[i]);
        //cout << i << ' ' << mic[i] << ' ' << i*mic[i] << endl;
    }
    
    cout << mx;
    return 0;
}