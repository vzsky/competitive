#include<bits/stdc++.h>
using namespace std;

int p[500100];
int dead[500100];
int find (int u) { return u == p[u]? u: p[u] = find(p[u]); }

const int mod = 1e9+7;

long long two(long long n) {
  if (n == 1) return 2;
  if (n == 0) return 1;
  long long half = two(n/2);
  if (n&1) return (((half*half)%mod)*2)%mod;
  else return (half*half)%mod;
}

vector<int> ans;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;

  for (int i = 0; i <= m; i++) {
    p[i] = i;
  }
  
  for (int i = 1; i <= n; i++) { 
    int k; cin >> k;
    if (k == 1) {
      int a; cin >> a;
      a = find(a);
      if (dead[a]) {continue;}
      dead[a] = 1;
    }
    if (k == 2) {
      int a, b; cin >> a >> b;
      a = find(a); b = find(b);
      if (a == b) {
        continue;
      }
      if (dead[a] and dead[b]) {
        p[a] = b;
        continue; 
      }
      if (dead[a] or dead[b]) {
        dead[a] = dead[b] = 1;
      }
      // assert(dead[a] ^ dead[b] == 0);
      p[a] = b;
    }
    ans.push_back(i);
  }
  cout << two(ans.size()) << ' ' << ans.size() << endl;
  for (auto x : ans) {
    cout << x << ' ';
  }
  return 0;
}