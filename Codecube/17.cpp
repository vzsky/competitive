#include<stdio.h>

char c[1010], d[1010];
int l = 0;
int cnt= 0;

int main(){
	int n,m;
	scanf(" %d %d", &n, &m);
	scanf(" %s %s", c, d);
	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			if (c[i+j]==d[j]){
				l++;
			}
			else break;
		}
		//printf("%d\n", l);
		if (l==m) cnt++;
		l = 0;
	}
	printf("%d", cnt);
	return 0;
}
