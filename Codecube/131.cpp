#include<bits/stdc++.h>
using namespace std;

char str[30];

int main(){
	int n, m, a, mxa=1e4, mxa2=1e4, mxb=1e4, mxb2=1e4;
	scanf("%d %d", &n, &m);
	for(int i = 0; i < n; i++){
		scanf("%d", &a);
		if (a < mxa) {mxa2 = mxa; mxa = a;}
		else if (a < mxa2) {mxa2 = a;}
	}
	for(int j = 0; j < m; j++){
		scanf("%d", &a);
		if (a < mxb) {mxb2 = mxb; mxb = a;}
		else if (a < mxb2) {mxb2 = a;}
	}
	//cerr << mxa << mxa2 << mxb << mxb2 << endl;
	printf("%d", min(mxa+mxa2, min(mxb+mxb2, mxa+mxb+100)));
	return 0;
}
