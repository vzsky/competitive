#include<bits/stdc++.h>
using namespace std;

int main(){
	int n, m;
	scanf("%d %d", &n, &m);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			printf("%c", 'A'+(j+(m*i))%26);
		}
		printf("\n");
	}

	return 0;
}
