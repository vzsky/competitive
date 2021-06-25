#include "cards.h"
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end() 

int n, k, fact[10], fw[10010];
int ask (int u) { int a = 0; for (int i = u; i > 0; i-=(i&-i)) a += fw[i]; return a; }
void add (int u) { for (int i = u; i <= 10000; i+=(i&-i)) fw[i]++; }
void init (int N, int K) {
  n=N; k=K; fact[0] = 1;
  for (int i = 1; i <= 8; i++) fact[i] = fact[i-1]*i;
}

void init_magician(int N, int K)  { init(N, K); }
void init_assistant(int N, int K) { init(N, K); }

vector<int> choose_cards(vector<int> cards) {
  int cnt = 1;
  int p = cards[k-1]-cards[k-2] <= fact[k-1] ? cards[k-1]-cards[k-2] : n-cards[k-1]+cards[0];
  int s = cards[k-1]-cards[k-2] <= fact[k-1] ? k-1 : 0;
  cards.erase(cards.begin()+s);
  do { if (cnt++ == p) break; } 
  while ((next_permutation(all(cards))));
  return cards;
}

int find_discarded_card(vector<int> cards) {
  int ans = 1, mx = 0;
  memset(fw, 0, sizeof fw);
  for (int i = cards.size()-1; i >= 0; i--) {
    ans += ask(cards[i]) * fact[cards.size()-1-i];
    add(cards[i]);
    mx = max(mx, cards[i]);
  }
  if (mx+ans <= n) return mx+ans;
  return mx+ans-n;
}