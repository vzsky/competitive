#include<bits/stdc++.h>
using namespace std;

int a[100100], b[100100], n;

long long inv(int l, int r){
    if (l == r) return 0;
    long long mid = (l + r)/2;
    long long cnt = inv(l, mid) + inv(mid+1, r);

    int i = l, j = mid+1, c = l;
    while(i <= mid and j <= r){
      if (a[i] < a[j]) b[c++] = a[i++];
      else { b[c++] = a[j++]; cnt += mid-i+1; }
    } 
    while(i <= mid) b[c++] = a[i++];
    while(j <= r) b[c++] = a[j++]; 

    for(int i = l; i <= r; i++) a[i] = b[i];
    
    return cnt;
}

int main(){
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);
  cin >> n;
  for (int i = 0; i < n; i++) { cin >> a[i]; }
  cout << inv(0, n-1) << endl;
  return 0;
}