#include<bits/stdc++.h>
using namespace std;

int a[100];
set<int> s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    s.clear();
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a, a+n);
    for (int i = 0; i < n; i++) {
      for (int j = i+1; j < n; j++) {
        s.insert(a[j]-a[i]);
      }
    }
    cout << s.size() << endl;
  }
  return 0;
}