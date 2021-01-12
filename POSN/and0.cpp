#include<bits/stdc++.h>
using namespace std;

int a[1000100];
int qs[1000100];

int main(){
   int n, q;
   scanf("%d %d",&n, &q);
   for(int i = 0; i < n; i++){
       scanf("%d", &a[i]);
   }
   for(int i = 0; i < q; i++){
       int l, r;
       scanf("%d %d", &l, &r);
       qs[l-1]++;qs[r]--;
   }
   for(int i = 1; i < n; i++){
       qs[i]+=qs[i-1];
   }
   for(int i = 0; i < n; i++){
       if (qs[i] > 0) printf("0 ");
       else printf("%d ", a[i]);
   }

   return 0;
}