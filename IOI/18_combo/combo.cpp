#include <bits/stdc++.h>
#include "combo.h"
using namespace std;

int n;
string ans;

char c[] = "ABXYABX";
int s = -10;
void g(string S1, string S2, string S3);
void f(string S) {
  if (n <= S.size()) return void (ans = S);
  // assert(3*S.size()+6 <= 4*n);
  int coin = press(S+c[s+2]+c[s+2]+S+c[s+3]+c[s+3]+S+c[s+2]+c[s+1]);
  if (coin == S.size()) f(S+c[s+1]);
  if (coin == S.size()+1) g(S+c[s+2]+c[s+3], S+c[s+3]+c[s+2], S+c[s+3]+c[s+1]);
  if (coin == S.size()+2) g(S+c[s+3]+c[s+3], S+c[s+2]+c[s+2], S+c[s+2]+c[s+1]);
}
void g(string S1, string S2, string S3) {
  // cout << "g " << S1 << ' ' << S2 << ' ' << S3 << endl;
  // assert S1.size() == S2.size() == S3.size()
  int coin = press(S3);
  if (coin == S3.size()) f(S3);
  if (coin == S3.size()-1) f(S2);
  if (coin == S3.size()-2) f(S1);
}

string guess_sequence(int N) {
  n = N;
  string S = "";
  if (press("AB")) {
    if (press("AX")) S = "A", s = 0;
    else S = "B", s = 1;
  } 
  else {
    if (press("AX")) S = "X", s = 2;
    else S = "Y", s = 3;
  }
  if (N == 1) return S;
  if (N == 2) {
    if (press(S+c[s+1]) == 2) return S+c[s+1];
    else if (press(S+c[s+2]) == 2) return S+c[s+2];
    else return S+c[s+3];
  }
  f(S);
  // cout << ans << endl;
  string realans = "";
  for (int i = 0; i < n; i++) realans += ans[i];
  // cout << realans << endl;
  return realans;
}
