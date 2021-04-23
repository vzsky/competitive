#include<bits/stdc++.h>
using namespace std;

tuple<string,int,int> gates[10000];
int A[10000];
int B[10000];
int ans[100];

int cnt = 0;

int OR (int a, int b) {
  gates[++cnt] = {"OR", a, b};
  return cnt;
}

int AND (int a, int b) {
  gates[++cnt] = {"AND", a, b};
  return cnt;
}

int NOT (int a) {
  gates[++cnt] = {"NOT", a, -1e9};
  return cnt;
}

int XOR(int a, int b) {
  int orgate = OR(a, b);
  int andgate = AND(a, b);
  int notgate = NOT(andgate);
  int xorresult = AND(notgate, orgate);
  return xorresult;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int n, m; cin >> n >> m;
  for (int i = 0; i < n; i++) {
    A[i] = -(i+1);
    B[i] = -(i+1)-n;
  }
  int tod = 0;
  for (int i = 0; i < n; i++) {
    int aorb = OR(A[i], B[i]);
    int aandb = AND(A[i], B[i]);
    ans[i] = XOR(AND(NOT(aandb), aorb), tod);
    tod = OR(aandb, AND(tod, aorb));
  }
  ans[n] = tod;

  cout << cnt << endl;
  for (int i = 0; i <= n; i++) {
    cout << ans[i] << ' ';
  } cout << endl;
  for (int i = 1; i <= cnt; i++) {
    if (get<2>(gates[i]) == -1e9) cout << get<0>(gates[i]) << ' ' << get<1>(gates[i]) << endl;
    else cout << get<0>(gates[i]) << ' ' << get<1>(gates[i]) << ' ' << get<2>(gates[i]) << endl;
  }
  return 0;
}