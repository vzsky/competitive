#include <bits/stdc++.h>
using namespace std;
#define rep(n) for (int i = 1; i <= n; i++)
#define R(n) rep(n) cout << "R"; 
#define L(n) rep(n) cout << "L";
#define U(n) rep(n) cout << "U";
#define D(n) rep(n) cout << "D";
#define r R(1)
#define l L(1)
#define u U(1)
#define d D(1)

int main() {
  ios_base::sync_with_stdio(0); cin.tie(0);
  U(11) L(11) D(23) rep(23) { r U(23) D(23) } r U(23) u rep(11) { L(30) d rep(10) {l u d} R(10) u R(30) u } L(30);
  d l U(3) D(3) l u r u l r r u u l l d l l d d u l d u u R(3) D(3) l l d L(4) u u r d d r u d r u d L(3) U(4) D(3) l l u l u r r l d r
}