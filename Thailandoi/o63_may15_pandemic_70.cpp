#include "pandelib.h"
#include <bits/stdc++.h>
using namespace std;

int digit;
map<int,int> rev, num;

vector<int> getbasefive (int n) { 
  vector<int> ans;
  for (int i = 0; i < digit; i++) {
    ans.push_back(n%5);
    n/=5;
  }
  assert(n == 0);
  reverse(ans.begin(), ans.end());
  return ans;
}

int getnumfrombasefive (vector<int> base) {
  int ans = 0;
  for (int i = 0; i < digit; i++) {
    ans *= 5;
    ans += base[i];
  }
  return ans;
}

bool checkDuplicate (int l, vector<int> base) {
  int cnt[5] = {0, 0, 0, 0, 0};
  for (int i = 0; i < digit; i++) cnt[base[i]]++;
  for (int i = 1; i <= 4; i++) if (cnt[i] > l) return false; // since there can be many 0
  return true;
}

vector<int> day[5][100];

void init (int N, int K, int L) {
  int i = 0, cnt = 1;
  while (++i) {
    if (cnt == N+1) break;
    auto base = getbasefive(i);
    if (!checkDuplicate(L, base)) continue;
    rev[i] = cnt; num[cnt] = i;
    for (int d = 0; d < digit; d++) {
      if (base[d] == 0) continue;
      day[base[d]][d].push_back(cnt);
    }
    cnt++;
  } 
}

int solve (int N, int K, int L) {
  vector<int> blank[digit];
  bool results[digit];

  for (int i = 1; i <= 4; i++) pandemic_assign(day[i], results);
  // wait
  for (int i = 5; i <= 30; i++) pandemic_assign(blank, results);
  // getResult 
  vector<int> date = vector<int>(digit, 0);
  for (int d = 1; d <= 4; d++) {
    pandemic_assign(blank, results); // get result day d;
    for (int i = 0; i < digit; i++) {
      if (results[i] == true and date[i] == 0) date[i] = d;
    } 
  }
  int ans = getnumfrombasefive(date);
  return rev[ans];
}


int main () {
  int N, K, L;
  pandemic_init(N, K, L);

  if (L == 4) digit = K;
  if (L == 3) digit = 8; // check all cases w/ manually written lib. all passed
  if (L == 2) digit = 8;
  if (L == 1) return 0; // to be implemented;

  init(N, K, L);
  int ans = solve(N, K, L);
  pandemic_answer(ans);

  return 0;
}