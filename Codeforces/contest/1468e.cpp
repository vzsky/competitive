#include<bits/stdc++.h>
using namespace std;
int a[4];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while(t--) {
    for (int i = 0; i < 4; i++) cin >> a[i];
    sort(a, a+4);
    // cout << a[0] << a[1] << a[2] << a[3] <<endl;
    cout << a[0]*a[2] << endl;
  }
  return 0;
}