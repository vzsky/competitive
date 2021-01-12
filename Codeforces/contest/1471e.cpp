#include<bits/stdc++.h>
using namespace std;

int ask (int n) {
  cout << "? " << n << endl;
  cout.flush();
  int A; cin >> A;
  return A;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, k; cin >> n >> k;
  assert(ask(1) == k);
  int now = 1;
  int add = 1;
  int v;
  while (1) {
    if (now >= n+1) now %= n;
    if (now == 0) now = n;
    v = ask(now);
    if (v == k) {
      now+=add;
      add++;
    }
    else {break;}
  }
  if (v < k) {
    for (int i = now+1; ; i++) {
      if (i == n+1) i = 1;
      if (ask(i) == k) {
        cout << "! " << i << endl;
        cout.flush();
        return 0;
      }
    }
  }
  if (v > k) {
    for (int i = now-1; ; i--) {
      if (i == 0) i = n;
      if (ask(i) == k) {
        cout << "! " << i << endl;
        cout.flush();
        return 0;
      }
    }
  }
  return 0;
}