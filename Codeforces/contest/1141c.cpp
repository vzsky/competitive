#include<bits/stdc++.h>
using namespace std;

long long int arr[200100];
long long int mn = 0;

map<int,int> m;

int main(){
    int n;
    scanf("%d", &n);
    for(int i = 1; i < n; i++){
        int a;
        scanf("%d", &a);
        arr[i] = arr[i-1]+a;
        mn = min(mn, arr[i]);
    }
    for(int i = 0; i < n; i++){
        int k = abs(mn)+1+arr[i];
        if (k > n||m.count(k)){
            printf("-1");
            return 0;
        }
        m[k] = 1;
        arr[i] += abs(mn)+1;
    }
    for(int i = 0; i < n; i++){
        cout << arr[i] << ' ';
    }
    return 0;
}