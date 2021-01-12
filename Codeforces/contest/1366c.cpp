#include<bits/stdc++.h>
using namespace std;

int arr[35][35];
int cnt[100][3];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  for (int tt = 0; tt < t; tt++) {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        cin >> arr[i][j];
      }
    }

    for (int i = 0; i < 100; i++) {
      cnt[i][0] = cnt[i][1] = 0;
    }

    for (int i = 0; i < n+m-1; i++){
      for (int a = 0; a < n; a++) {
        int b = i - a;
        if (b < 0 or b >= m) continue;
        // i == n+m-2-i
        if (i == n+m-2-i) continue;
        int idx = min(i, n+m-2-i);
        cnt[idx][arr[a][b]]++;
      }
    }
    int ans = 0;
    for (int i = 0; i < n+m-1; i++){
      if (i >= n+m-2-i) break;
      ans += min(cnt[i][0], cnt[i][1]);
    }
    cout << ans << endl;
  }
  return 0;
}