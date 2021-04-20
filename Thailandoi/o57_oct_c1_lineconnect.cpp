#include<bits/stdc++.h>
using namespace std;

int a[100100], s[100100], p[100100], c[100100];
int find (int u) { return u==p[u]?u:p[u]=find(p[u]); }
map<int,int> m;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    p[i] = i;
    cin >> a[i];
    s[i] = a[i];
  }
  for (int i = 0; i < n-2; i++) {
    int x, y; cin >> x >> y;
    p[find(x)] = find(y);
  }

  for (int i = 1; i <= n; i++) if (find(i) == find(1)) c[i] = 1;
  
  sort(s+1, s+1+n);
  for (int i = 1; i <= n; i++) {
    int ind = lower_bound(s+1, s+1+n, a[i]) - s;
    m[s[ind]] = i;
  }

  int mn = 2e9;
  int pc = -1, po = -1;
  for (int i = 1; i <= n; i++) {
    if (c[m[s[i]]]) pc = i;
    else po = i;
    if (pc != -1 and po != -1) {
      mn = min(mn, abs(s[pc]-s[po]));
    }
  }
  assert(mn != 2e9);
  cout << mn << endl;
  return 0;
}
