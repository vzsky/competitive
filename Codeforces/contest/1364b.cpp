#include<bits/stdc++.h>
using namespace std;

int a[100100];
vector<int> ans;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t;
  cin >> t;
  while (t--) {
    ans.clear();
    int n;
    cin >> n;
    for (int i = 0;i < n; i++) {
      cin >> a[i];
    } 
    ans.push_back(a[0]);
    ans.push_back(a[1]);
    int way = a[1] - a[0]; // - means dec
    for (int i = 2; i < n; i++) {
      if (way < 0 and a[i] < ans.back()) {
        ans.pop_back();
        ans.push_back(a[i]);
      }
      else if (way > 0 and a[i] > ans.back()) {
        ans.pop_back();
        ans.push_back(a[i]);
      }
      else {
        way = -way;
        ans.push_back(a[i]);
      }
    }
    cout << ans.size() <<endl;
    for (auto x : ans ){
      cout << x << ' ';
    }
    cout << endl;
  }
  return 0;
}