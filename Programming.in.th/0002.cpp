#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  int m = 2e9+1, M = -2e9-1;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    m = min(m, a);
    M = max(M, a);
  }
  cout << m << endl << M << endl;
  return 0;
}