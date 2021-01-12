#include<bits/stdc++.h>
using namespace std;

typedef pair<int,int> point;
// vector<pair<point,point>> e;
vector<point> p;
int dis[80][80];

int main(){
    auto d = [](point a, point b) -> int { return abs(b.first-a.first)+abs(b.second-a.second);};
    int k, m;
    scanf("%d %d", &k, &m);

    for(int i = 0; i < k; i++){
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        // e.push_back({{x1, y1}, {x2, y2}});
        p.push_back({x1, y1});
        p.push_back({x2, y2});
    }
    for(int i = 0; i < p.size(); i++) for(int j = 0; j < p.size(); j++) dis[i][j] = d(p[i], p[j]);
    for(int i = 0; i < k; i++) dis[i*2][i*2+1] = dis[i*2+1][i*2] = 0;

    for(int k = 0; k < p.size(); k++) {
        for(int i = 0; i < p.size(); i++) {
            for(int j = 0; j < p.size(); j++) {
                dis[i][j] = min(dis[i][j], dis[i][k]+dis[k][j]);
            }
        }
    }

    for(int i = 0; i < m; i++){
        int x1, x2, y1, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
        int ss = d({x1,y1}, {x2, y2});
        for(int i = 0; i < p.size(); i++) {
            for(int j = 0; j < p.size(); j++) {
                ss = min(ss, d({x1, y1}, p[i])+dis[i][j]+d({x2, y2}, p[j]));
            }
        }
        printf("%d\n", ss);
    }
    return 0;
}