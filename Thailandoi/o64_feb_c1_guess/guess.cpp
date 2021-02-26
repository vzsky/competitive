#include "guess.h"
#include <bits/stdc++.h>
using namespace std;

int find_answer(int N, int K) {
  vector<int> num, black, red, yellow, blue;
  vector<pair<int,char>> check;
  for (int i = 0; i < N; i++) num.push_back(i);

  if (K == 1) {
    // XCRRCX
    while (num.size() != 1) {
      if (num.size() == 2) {
        char res = ask({{num[0], 'R'}});
        if (res == 'R') return num[0];
        return num[1];
      }
      for (int i = 0; i < num.size(); i++) {
        // red
        if (i % 6 == 2 or i % 6 == 3) {
          red.push_back(num[i]);
          check.push_back({num[i], 'R'});
        }
        // black
        if (i % 6 == 0 or i % 6 == 5) black.push_back(num[i]);
        // yellow
        if (i % 6 == 1) {
          if (i+1 == num.size() or num[i+1] != num[i]+1) {
            if (num[i]+1 >= N) { black.push_back(num[i]); continue; }
            check.push_back({num[i]+1, 'R'});
          }
          yellow.push_back(num[i]);
        }
        if (i % 6 == 4) {
          if (num[i-1] != num[i]-1) {
            check.push_back({num[i]-1, 'R'});
          }
          yellow.push_back(num[i]);
        }
      }
      
      char res = ask(check);
      check.clear();
      num.clear();
      if (res == 'X') num = black;
      if (res == 'C') num = yellow;
      if (res == 'R') num = red;
      black.clear();
      yellow.clear();
      red.clear();
    }
    return num[0];
  }

  if (K == 2) {
    // XCRRBBCX
    while (num.size() != 1) {
      if (num.size() == 4) {
        check = {{num[0], 'R'}, {num[1], 'B'}};
        if (num[2]-1 != num[1]) check.push_back({num[2]-1, 'R'});
        char res = ask(check);
        if (res == 'R') return num[0];
        if (res == 'B') return num[1];
        if (res == 'C') return num[2];
        if (res == 'X') return num[3];
      }
      for (int i = 0; i < num.size(); i++) {
        // red
        if (i % 8 == 2 or i % 8 == 3) {
          red.push_back(num[i]);
          check.push_back({num[i], 'R'});
        }
        // blue
        if (i % 8 == 4 or i % 8 == 5) {
          blue.push_back(num[i]);
          check.push_back({num[i], 'B'});
        }
        // black
        if (i % 8 == 0 or i % 8 == 7) black.push_back(num[i]);
        // yellow
        if (i % 8 == 1) {
          if (i+1 == num.size() or num[i+1] != num[i]+1) {
            check.push_back({num[i]+1, 'R'});
          }
          yellow.push_back(num[i]);
        }
        if (i % 8 == 6) {
          if (i-1 != num.size() and num[i-1] != num[i]-1) {
            check.push_back({num[i]-1, 'R'});
          }
          yellow.push_back(num[i]);
        }
      }

      char res = ask(check);
      check.clear();
      num.clear();
      if (res == 'X') num = black;
      if (res == 'C') num = yellow;
      if (res == 'R') num = red;
      if (res == 'B') num = blue;
      black.clear();
      yellow.clear();
      red.clear();
      blue.clear();
    }
    return num[0];
  }
  return -1;
}