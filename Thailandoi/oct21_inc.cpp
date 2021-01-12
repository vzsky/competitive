#include<bits/stdc++.h>
using namespace std;
int a[100100], b[100100], p[100100];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  memset(p, -1, sizeof p);
  for (int i = 0; i < n; i++) cin >> a[i];
  pair<int,int> mx = {0, 0};
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < i; j++) if (a[j] < a[i]) {
      if (b[j]+1 > b[i]) {
        b[i] = b[j]+1;
        p[i] = j;
      }
    }
    if (b[i] > mx.first) mx = {b[i], i};
  }
  stack<int> st;
  cout << mx.first+1 << endl;
  for (int i = mx.second; i != -1; i = p[i]) st.push(a[i]);
  while (!st.empty()) { cout << st.top() << ' '; st.pop(); }
  return 0;
}