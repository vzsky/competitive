#include<bits/stdc++.h>
using namespace std;

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int a, b, c;
  cin >> a >> b >> c;
  int t = a+b+c;
  if (t >= 80) { cout << "A"; return 0; }
  if (t >= 75) { cout << "B+"; return 0; }
  if (t >= 70) { cout << "B"; return 0; }
  if (t >= 65) { cout << "C+"; return 0; }
  if (t >= 60) { cout << "C"; return 0; }
  if (t >= 55) { cout << "D+"; return 0; }
  if (t >= 50) { cout << "D"; return 0; }
  cout << "F";
  return 0;
}