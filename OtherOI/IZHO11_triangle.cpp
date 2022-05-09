#include<bits/stdc++.h>
using namespace std;
 
int x[300100], y[300100];
map<int,long long> mx, my;
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n; cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    mx[x[i]]++; my[y[i]]++;
  }
  long long ans=0;
  for (int i = 0; i < n; i++) ans+=(mx[x[i]]-1)*(my[y[i]]-1);
  cout << ans;
  return 0;
}