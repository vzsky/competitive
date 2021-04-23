#include<bits/stdc++.h>
using namespace std;

int a[100100];

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    int ind = 0;
    for (int i = 0; i < k; i++) {
      while (a[ind] == 0) {
        ind++;
        if (ind == n-1) goto end;
      }
      a[ind]--;
      a[n-1]++;
    }
    end:
    for (int i = 0; i < n; i++) {
      cout << a[i] << ' ';
    } cout << endl;
  }
  return 0;
}