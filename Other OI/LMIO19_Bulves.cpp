#include<bits/stdc++.h>
using namespace std;

long long v[500100];
long long ans = 0;
priority_queue<long long> heap;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 1; i <= n; i++) {
    int a, b; cin >> a >> b;
    v[i] = a-b + v[i-1];
  }
  for (int i = 1; i <= n; i++) {
    if (v[i] > v[n]) {ans += v[i]-v[n]; v[i] = v[n];} // v[n] can't be changed
    if (v[i] < 0) {ans += 0-v[i]; v[i] = 0;} // v[i] >= 0
    heap.push(v[i]);
    heap.push(v[i]);
    ans += heap.top() - v[i];
    heap.pop();
  }
  cout << ans << endl;
  return 0;
}