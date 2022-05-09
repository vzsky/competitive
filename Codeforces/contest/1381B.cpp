#include<bits/stdc++.h>
using namespace std;

vector<int> v;
int sum[2100];
int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int t; cin >> t;
  while (t--) {
    int n; cin >> n;
    int block = 1, head;
    for (int i = 0; i < 2050; i++) sum[i] = 0;
    sum[0] = 1; 
    cin >> head;
    for (int i = 1; i < 2*n; i++) {
      int a; cin >> a;
      if (a < head) block++;
      else {
        for (int i = 2010; i > 0; i--) if (i >= block) sum[i] |= sum[i-block];
        head = a; block = 1;
      }
    }
    for (int i = 2010; i > 0; i--) if (i >= block) sum[i] |= sum[i-block];
    cout << (sum[n]?"YES\n":"NO\n");
  }
  return 0;
}
