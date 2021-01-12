#include<bits/stdc++.h>
using namespace std;
int a[200100];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < 2*n; i++) cin >> a[i];
  sort(a, a+n+n); cout << a[n-1];
  return 0;
}