#include<bits/stdc++.h>
using namespace std;
#define x first
#define y second

pair<int, int> p[200];
int a[200][200];
int b[200][200];
int dis[200][200];
set<int> s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      cin >> a[i][j];
    }
  }

  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= n; j++) {
      dis[i][j] = (p[i].x-p[j].x)*(p[i].x-p[j].x) + (p[i].y-p[j].y)*(p[i].y-p[j].y);
      s.insert(dis[i][j]);
    }
  }

  // for (int i = 1; i <= n; i++) {
  //   for (int j = 1; j <= n; j++) {

  //   }
  // }

  int mn = 1e9;
  for (auto x : s) {
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (dis[i][j] <= x) b[i][j] = 1 ;
      }
    }
    int cnt = 0;
    for (int i = 1; i <= n; i++) {
      for (int j = 1; j <= n; j++) {
        if (a[i][j] != b[i][j]) cnt++;
      }
    }
    mn = min(cnt, mn);
  }
  cout << mn;

  return 0;
}