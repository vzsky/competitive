#include<bits/stdc++.h>
using namespace std;
#define zero(x) for (int i = 0; i < x; i++) cout << 0;

int main(){
  ios_base::sync_with_stdio(0); cin.tie(0);
  string a, b; char o; cin >> a >> o >> b;
  int A = a.size()-1, B = b.size()-1;
  if (o == '+') {
    if (A < B) { swap(a, b); swap(A, B); }
    if (A == B){ cout << 2; zero(A); }
    else { cout << 1; zero(A-B-1); cout << 1; zero(B); }
  }
  if (o == '*') { cout << 1; zero(A+B); }
  return 0;
}