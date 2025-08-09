#include<bits/stdc++.h>
#include <queue>
using namespace std;

struct A {
  int t, r, c;
  bool operator < (const A & o) const {
    return t > o.t;
  }
};

priority_queue<A> heap;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
 
int space[110][110]; // holds min time a ghost takes
int pac[110][110]; // holds pacman's arrival
int wall[110][110]; // bool for wall 


int R, C, n, T, r, c; 

bool valid (int x, int y) {
  if (x < 0 || y < 0) return false;
  if (x >= R || y >= C) return false;
  if (wall[x][y]) return false;
  return true;
}

int main () {
  int k; cin >> k;
  while (k--) {
    cin >> R >> C >> n >> T >> r >> c;
    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        space[i][j] = -1;
        wall[i][j] = 0;
        pac[i][j] = -1;
      }
    }
    while (!heap.empty()) heap.pop();

    for (int i = 0; i < n; i++) {
      int ghost_t, ghost_r, ghost_c;
      cin >> ghost_t >> ghost_r >> ghost_c;
      heap.push({ghost_t, ghost_r, ghost_c});
    }

    for (int i = 0; i < R; i++) {
      string s; cin >> s;
      for (int j = 0; j < C; j++) {
        if (s[j] == '#') wall[i][j] = 1;
      } 
    }

    while (!heap.empty()) {
      auto tp = heap.top(); heap.pop();
      if (space[tp.r][tp.c] != -1) continue; 
      space[tp.r][tp.c] = tp.t;
      
      for (int d = 0; d < 4; d++) {
        if (valid(tp.r+dx[d], tp.c+dy[d]))
          heap.push({tp.t+1, tp.r+dx[d], tp.c+dy[d]});
      }
    }

    // for (int i = 0; i < R; i++) {
    //   for (int j = 0; j < C; j++) {
    //     cout << space[i][j];
    //   } cout << endl;
    // }

    bool answer = false;
    heap.push({0, r, c});
    while(!heap.empty()) {
      auto tp = heap.top(); heap.pop();

      if (pac[tp.r][tp.c] != -1) continue;
      if (space[tp.r][tp.c] == -1 || space[tp.r][tp.c] > tp.t) {

        pac[tp.r][tp.c] = tp.t;
        if (tp.t == T) {
          answer = true;
          break;
        }

        for (int d = 0; d < 4; d++) {
          int des_x = tp.r+dx[d], des_y = tp.c+dy[d];
          if (valid(des_x, des_y) && (space[des_x][des_y] == -1 || space[des_x][des_y] > tp.t))
            heap.push({tp.t+1, des_x, des_y});
        }
        heap.push({tp.t+1, tp.r, tp.c});
      }
    }

    for (int i = 0; i < R; i++) {
      for (int j = 0; j < C; j++) {
        if (pac[i][j] != -1 && space[i][j] > T)   answer = true;
        if (pac[i][j] != -1 && space[i][j] == -1) answer = true;
      }
    }


    cout << (answer ? "YES\n" : "NO\n");
  }
  return 0;
}
