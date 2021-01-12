#include<bits/stdc++.h>
using namespace std;

vector <int> g[1010];
int visited[1010];

int ch = 0;

int call = 0;

void dfs (int n){
    //cerr << call << ' ' << n <<endl;
    if (n == call) {ch = 1; return;}
    if (visited[n]) return;
    visited[n] = 1; 
    for(auto x : g[n])  dfs(x); 
}

queue<int> q;


int main(){
   int n;
   scanf("%d", &n);
   for(int i = 0; i < n; i++){
       int a, b;
       scanf("%d %d", &a, &b);
       g[a].push_back(b);
   }   
   for(int i = 0; i <= 999; i++){
        call = i;
        memset(visited, 0, sizeof visited);
        for(auto x : g[i]){
            dfs(x);
            if (ch) break;
        }
        if (ch) break;
   }
   if (ch) printf("BUG");
   else printf("OK");
   return 0;
}