#include<bits/stdc++.h>
using namespace std;

int a[1000100];
priority_queue<int> heap;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

	int n, m; cin >> n >> m;
  int odd = 0, ans = 0;
  for (int i = 1; i <= n; i++) cin >> a[i];
  for (int i = 1; i <= n; i++) {
    odd+=(a[i]&1);
    if (i%2==0 && odd==(i/2) && i != n) heap.push(-abs(a[i+1]-a[i]));
  }
  while (!heap.empty()) {
    m += heap.top(); heap.pop(); ans++;
    if (m < 0) { ans--; break; }
  }
  cout << ans;
}

