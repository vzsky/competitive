#include<bits/stdc++.h>
using namespace std;

int a[100100];
int b[100100];
set<int> s;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n;
  cin >> n;
  for (int i = 1; i <= n;i ++) {
    cin >> a[i];
    if (a[i] > i) {
      cout << -1;
      return 0;
    }
  }
  int num = -5;
  for (int i = n; i > 0; i--) {
    if (a[i-1] != a[i]) {
      b[i] = a[i-1];
      s.insert(a[i-1]);
      if (num == -5) num = a[i]-1;
    }
    else {
      while (num != 0 and s.find(num) != s.end()) {
        // cerr << i << "pop" << num << endl;
        num--;
      }
      if (num <= 0 and a[i] == 0) {
        b[i] = a[n]+1;
      }
      if (num > a[i]) {
          b[i] = num;
          num--;
      }
      else {
b[i] = a[n]+1;
      }
    }
  }

  for (int i = 1; i <= n; i++) {
    cout << b[i] << ' ';
  }
  return 0;
}