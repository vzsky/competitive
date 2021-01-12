#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  int a[5];
  for (int i = 0; i < 4; i++) cin >> a[i];
  sort(a, a+4);
  cout << a[0] * a[2] << endl;
  return 0;
}