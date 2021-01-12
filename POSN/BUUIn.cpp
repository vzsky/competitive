#include<bits/stdc++.h>
using namespace std;

int arr[110];
int n, m;
int main(){
    int l = 0;
    scanf("%d %d", &n, &m);
    for(int i = 0 ; i < m; i++){
        scanf("%d", &arr[i]);
        l = max(l, arr[i]);
    }
    int r = 2e9;
    while (l < r){
        int mid = (l + r)/2;
        int cnt = 0;
        int count = 1;
        for(int i = 0; i < m; i++){
            if (arr[i] >= mid) {cnt = 0; count++; continue;}
            cnt += arr[i];
            if (cnt > mid) {
                count++;
                cnt = arr[i];
            }
        }
        if (count > n) l = mid+1;
        else r = mid;
        //cout << count << ' ' << l << ' ' << r << endl;
    }
    printf("%d", l);
return 0;
}