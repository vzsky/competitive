#include<bits/stdc++.h>
using namespace std;

int n, m;
int win[35][35];
vector<int> teams;

vector<int> nextRound(vector<int> teams) {
  vector<int> next;
  for (int i = 0; i < teams.size(); i+=2) {
    int a = teams[i];
    int b = teams[i+1];
    if (win[a][b] == a) { // a wins
      if (b == m) {
        next.push_back(b);
        m = 0;
      }
      else next.push_back(a);
    }
    else { // b wins
      if (a == m) {
        next.push_back(a);
        m = 0;
      }
      else next.push_back(b);
    }
  }
  return next;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  
  cin >> n >> m;
  for (int i=1; i<=n; i++) {
    for (int j=1; j<=n; j++) {
      cin >> win[i][j];
    }
  }

  for (int i=1; i<=n; i++) {
    teams.push_back(i);
  }

  while(teams.size() != 1) {
    teams = nextRound(teams);
  }
  cout << teams[0] << endl;

  return 0;
}