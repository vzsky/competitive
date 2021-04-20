#include<bits/stdc++.h>
using namespace std;

int n, k;
int a[400], qs[400];
int dp[400][400], trace[400][400], sz[400][400];

int cost (int i, int j) { return (qs[j]-qs[i-1]) * (j-i); }

int findsize(int i, int j) {
  int goal = 2*k-i+1, last = j, table = i-1;
  while (table != 0) {
    int first = trace[table][last];
    if (table == goal) return last-first+1;
    last = first-1; table -= 1;
  }
  return 1e9;
}

void solve (int i, int l = 1, int r = n, int a = 1, int b = n) {
  if (l > r) return;
  int mid = (l+r)/2;
  dp[i][mid] = 1e9;
  for (int l = a; l <= min(mid, b); l++) {
    int pairing = (i >= k+1) ? 2*(mid-l)*findsize(i, l) : 0;
    if (dp[i-1][l] + cost(l+1, mid) + pairing <= dp[i][mid]) {
      dp[i][mid] = dp[i-1][l] + cost(l+1, mid) + pairing;
      trace[i][mid] = l+1;
    }
  }
  solve(i, l, mid-1, a, trace[i][mid]-1);
  solve(i, mid+1, r, trace[i][mid]-1, b);
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n >> k;
  for (int i = 1; i <= n; i++) cin >> a[i];
  sort(a+1, a+n+1);
  for (int i = 1; i <= n; i++) qs[i] = qs[i-1] + a[i];

  for (int j = 1; j <= n; j++) {
    dp[1][j] = cost(1, j);
    trace[1][j] = 1;
  } 
  for (int i = 2; i <= 2*k; i++) solve(i);
  cout << dp[2*k][n] << endl;
  return 0;
}