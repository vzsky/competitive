#include<bits/stdc++.h>
using namespace std;

vector <pair<int,int>> es;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        int s, e;
        scanf("%d %d", &s, &e);
        es.push_back({e,s});
    }
    sort(es.begin(), es.end());
    int lasten = 0;
    int cnt=0;
    for(auto x : es){
        int start = x.second;
        int en = x.first;
        if (start >= lasten){
            lasten = en;
            cnt++;
        }
    }
    printf("%d", cnt);
return 0;
}