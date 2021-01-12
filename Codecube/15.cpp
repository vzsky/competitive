#include<stdio.h>

int main(){
	int n, i, j;
	scanf(" %d", &n);
	if (!(n&1)){
		 printf("error");
		 return 0;
	}
	for(i = 0; i < n; i++){
		for(j = 0; j < n; j++)
			if ((j<i&&(i+j)< n-1) || (j>i&&(i+j)>n-1))
				printf(" ");
			else printf("*");
		printf("\n");
	}
	return 0;
}
