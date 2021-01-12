#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a[5];
  cin >> a[0] >> a[1] >> a[2];
  sort(a, a+3);
  string s;
  cin >> s;
  cout << a[s[0]-'A'] << ' ' << a[s[1]-'A'] << ' ' << a[s[2]-'A'] << endl;
  return 0;
}