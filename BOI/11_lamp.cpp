#include<bits/stdc++.h>
using namespace std;
 
struct A {
  int x, y, d;
  bool operator < (const A & o) const {return d > o.d;}
}; 
priority_queue<A> heap;
char a[510][510];
int vis[510][510];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
  heap.push({0, 0, 0});
  while (!heap.empty()) {
    auto [x, y, d] = heap.top(); heap.pop();
    if (vis[x][y]) continue;
    vis[x][y] = 1;
    if (x == n and y == m) {cout << d; return 0;}
    for (int i = -1; i <= 1; i+=2) for (int j = -1; j <= 1; j+=2) 
    if (x+i >= 0 and y+j >= 0 and x+i <= n and y+j <= m) { 
      int dis = a[x-(i==-1)][y-(j==-1)] == ((i+j==0)?'\\':'/');
      heap.push({x+i, y+j, d+dis});
    }
  }
  cout << "NO SOLUTION";
  return 0;
}