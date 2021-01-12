#include<bits/stdc++.h>
using namespace std;

bool check () {
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  if (a == c && (b+d) == a) return true;
  if (a == d && (b+c) == a) return true;
  if (b == c && (a+d) == b) return true;
  if (b == d && (a+c) == b) return true;
  return false;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    cout << (check()? "Yes" : "No") << endl;
  }
  return 0;
}