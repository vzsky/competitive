#include<bits/stdc++.h>
using namespace std;

int n, fw[3][100100]; // height, up, down

void add (int t, int a, int v) {
  for (int i = a; i <= n; i+=(i&-i)) fw[t][i]+=v;
}

int ask(int t, int a) {
  int ans = 0;
  for (int i = a; i > 0; i-=(i&-i)) ans+=fw[t][i];
  return ans;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int m; cin >> n >> m;
  for (int i = 0; i < m; i++) {
    int t, a, b; cin >> t >> a >> b;
    if (t == 1) {
      if (ask(0, a) == ask(0, a-1)) add(1, a, 1);
      if (ask(0, b) == ask(0, b+1)) add(2, b+1, 1);
      if (ask(0, a)+1 == ask(0, a-1)) add(2, a, -1);
      if (ask(0, b)+1 == ask(0, b+1)) add(1, b+1, -1);
      add(0, a, 1); add(0, b+1, -1);
    }
    if (t == 2) {
      cout << ask(0, a) << ' ' << ask(0, b) << '\n';
    }
    if (t == 3) {
      cout << ask(0, a) << ' ' << ask(0, b) << ' ' << ask(1, b)-ask(1, a) << ' ' << ask(2, b)-ask(2, a) << '\n';
    }
  }
  return 0;
}