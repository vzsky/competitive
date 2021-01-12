#include<bits/stdc++.h>
using namespace std;

int a[300100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {

    int n;
    cin >> n;
    bool ans = true;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    if (a[0] > a[n-1]) ans = false;

    cout << (ans ? "YES" : "NO") << endl;
  }
  return 0;
}