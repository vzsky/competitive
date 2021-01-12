#include<stdio.h>
#define max(a, b) a>b?a:b
#define min(a, b) a<b?a:b

int main(){
	int n, a, mx = -2e9, mn = 2e9;
	scanf(" %d", &n);
	while(n--){
		scanf("%d", &a);
		mx = max(mx, a);
		mn = min(mn, a);
	}
	printf("%d\n%d", mx, mn);
	return 0;
}
