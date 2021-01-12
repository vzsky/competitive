#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	scanf("%d", &n);
	int l = n>>1;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			if (i+j >= l && j-i <= l && i-j <= l && i+j <= l+n-1)
				printf("*");
			else printf("-");
		}
		printf("\n");
	}
	return 0;
}
