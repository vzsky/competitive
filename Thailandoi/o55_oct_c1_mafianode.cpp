#include<bits/stdc++.h>
using namespace std;

int p[1000100];
set<pair<int,int>> s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, l, r; cin >> n >> l >> r; 
  for (int i = 1; i <= n; i++) s.insert({0, i});
  for (int i = 0; i < l+r; i++) {
    char o; cin >> o;
    int a, b;
    if (o == 'L') {
      cin >> a >> b;
      s.erase({p[b], b});
      p[b]++;
      s.insert({p[b], b});
    } 
    if (o == 'C') {
      cin >> a >> b;
      s.erase({p[b], b});
      p[b]+=3;
      s.insert({p[b], b});
    }
    if (o == 'R') {
      auto x = s.end();
      x--;
      cout << x->second << '\n';
    }
    if (o == 'D') {
      auto x = s.end();
      x--; 
      s.erase({p[x->second], x->second});
      p[x->second] = -1;
    }
  }
  return 0;
}