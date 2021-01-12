#include<bits/stdc++.h>
using namespace std;

string a = "ABC";
string b = "BABC";
string c = "CCAABB";

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int n; cin >> n;
  string s; cin >> s;
  int A=0, B=0, C=0;
  for (int i = 0; i < n; i++) {
    if (s[i] == a[i%3]) A++;
    if (s[i] == b[i%4]) B++;
    if (s[i] == c[i%6]) C++;
  }
  int ans = max(A, max(B, C));
  cout << ans << endl;
  if (ans == A) cout << "Adrian" << endl;
  if (ans == B) cout << "Bruno" << endl;
  if (ans == C) cout << "Goran" << endl;

  return 0;
}