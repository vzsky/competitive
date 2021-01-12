#include <bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;
int p[600100], cou;
long long pw[600100];

int find(int u) { return u == p[u] ? u : p[u] = find(p[u]); }
void merge (int a, int b) {
  if (find(a)==find(b)) return;
  p[find(a)] = find(b); cou--;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n, m; pw[0] = 1;
  iota(p, p + 600100, 0); 
  cin >> n >> m;
  for (int i = 1; i <= n; i++) pw[i] = pw[i - 1] * 2 % mod;
  cou = 2 * n; bool flag = false; 
  
  for (int i = 1; i <= m; i++) {
    int t, a, b; cin >> t >> a >> b;
    if (flag) goto end;
    if (!t) merge(a, b + n), merge(b, a + n);
    else    merge(a, b), merge(a + n, b + n);
    if (find(a) == find(a + n) || find(b) == find(b + n)) flag = true; 
    end :
    cout << (flag ? 0 : pw[cou/2]) << "\n";
  }
  return 0; }
