// Slope trick
#include<bits/stdc++.h>
using namespace std;

int a[3010];
priority_queue<int> heap; // store changing points

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> a[i]; a[i] -= i;
  }
  long long ans = 0;
  for (int i = 0; i < n; i++) {
    heap.push(a[i]);  // curve + |x-a[i]| 
    heap.push(a[i]);  // ignore right tail
    ans += heap.top() - a[i];
    heap.pop();       // ignore right tail
  }
  cout << ans;
  return 0;
}