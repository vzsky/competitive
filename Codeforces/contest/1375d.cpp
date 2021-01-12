#include<bits/stdc++.h>
using namespace std;

int a[1010];
map <int,int> exist;
map <int,int> mex;
vector<int> ans;
int m = 0;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {

    exist.clear();
    mex.clear();
    ans.clear();

    int n; cin >> n;
    for (int i = 1; i <= n; i++) {
      cin >> a[i];
      mex[a[i]]++;
    }
    for (int i = 0; i <= n; i++) {
      if (mex[i] == 0) {m = i; break; }
    }
    for (int i = 1; i <= n; i++) {
      if (exist[a[i]] != 0 or a[i] >= n) {
        ans.push_back(i);
        mex[a[i]]--;
        a[i] = m;
        mex[a[i]]++;
        while (1) {
          if (mex[m] == 0) break;
          m++;
        }
      }
      exist[a[i]] = 1;
    }
    for (auto x : ans) {
      cerr << x << ' ';
    } cerr <<endl;
    for (int i = 1; i <= n; i++) {
      cerr << a[i] << ' ';
    }cerr << endl;

    m = n;

    for (int i = 0; i < n; i++) {
      if (a[i+1] != i) {
        for (int j = i+1;;) {
          ans.push_back(j);
          int o = a[j];
          a[j] = m;
          m = o;
          j = m+1;
          if (j == i+1) {
            ans.push_back(j);
          int o = a[j];
          a[j] = m;
          m = o;
            break;
          }
        }
      }
    }

    cout << ans.size() << endl;
    for (auto x : ans) {
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}