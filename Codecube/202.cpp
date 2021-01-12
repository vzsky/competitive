#include<bits/stdc++.h>
using namespace std;

int a[1001000];

int main(){
	int n, ans = 0;
	scanf("%d %d", &n, &a[0]);
	for(int i = 1; i < n; i++) {
		scanf("%d", &a[i]);
		if (a[i]-a[i-1] > 0) ans += a[i]-a[i-1];
	}
	printf("%d", ans);
	return 0;
}