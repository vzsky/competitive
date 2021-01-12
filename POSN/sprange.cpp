#include<bits/stdc++.h>
using namespace std;

deque <int> mn, mx;
int a[1000100];

int main(){
    int n, p, q;
    int first = 0;
    long long ans = 0;
    scanf("%d %d %d", &n, &p, &q);
    for(int i = 1; i <= n; i++){
        scanf(" %d", &a[i]);
    }
    for(int i = 1; i <= n; i++){
        while(!mn.empty() && a[mn.back()] >= a[i]) mn.pop_back();
        while(!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();

        mn.push_back(i);
        mx.push_back(i);

        int range = a[mx.front()] - a[mn.front()];
        while (range > q && !mx.empty() && !mn.empty()){
            first++;
            while(!mx.empty() && mx.front() <= first) mx.pop_front();
            while(!mn.empty() && mn.front() <= first) mn.pop_front();
            if (mn.empty() || mx.empty()) break;
            range = a[mx.front()] - a[mn.front()];
        }
        ans += i-first;
    }
    mn.clear(); mx.clear();
    first = 0;
    for(int i = 1; i <= n; i++){
        while(!mn.empty() && a[mn.back()] >= a[i]) mn.pop_back();
        while(!mx.empty() && a[mx.back()] <= a[i]) mx.pop_back();

        mn.push_back(i);
        mx.push_back(i);

        int range = a[mx.front()] - a[mn.front()];
        while (range > p-1 && !mx.empty() && !mn.empty()){
            first++;
            while(!mx.empty() && mx.front() <= first) mx.pop_front();
            while(!mn.empty() && mn.front() <= first) mn.pop_front();
            if (mn.empty() || mx.empty()) break;
            range = a[mx.front()] - a[mn.front()];
        }
        ans -= i-first;
    }
    printf("%lld", ans);
    return 0;
}