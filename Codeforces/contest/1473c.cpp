#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    int x = ((2*n)-(2*k)+1);
    for (int i = 1; i <= n-x; i++) {
      cout << i << ' ';
    }
    for (int i = n-x+1; i <= k; i++) {
      cout << (n-x+k+1)-i << ' ';
    }
    cout << endl;
  }
  return 0;
}