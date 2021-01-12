#include<bits/stdc++.h>
using namespace std;

int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
string day[] = {"Monday","Tuesday","Wednesday","Thursday","Friday","Saturday","Sunday"};

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  int d, m; cin >> d >> m;
  for(int i = 0; i < m-1; i++) d += days[i];
  d = (d+2) % 7;
  cout << day[d];
  return 0;
}