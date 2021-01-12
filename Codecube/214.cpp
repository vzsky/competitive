#include<bits/stdc++.h>
using namespace std;

const int mod = 1e9+7;

struct MAT {
	long long mat[3][3];
	MAT operator * (const MAT & o) const {
		MAT temp;
		for(int i = 0; i < 3; i++) {
			for(int j = 0; j < 3; j++) {
				temp.mat[i][j] = 0;
				for(int k = 0; k < 3; k++) {
					temp.mat[i][j] += (mat[i][k]*o.mat[k][j])%mod;
					temp.mat[i][j] %= mod;
				}
				temp.mat[i][j] %= mod;
			}
		}
		return temp;
	}
} m[65], ans;

void build (long long a) {
	m[0].mat[0][2] = 1;
	m[0].mat[0][0] = 2*a;
	m[0].mat[1][1] = 2*a;
	m[0].mat[2][2] = (4*a*a)%mod;
	m[0].mat[0][1] = m[0].mat[1][0] = m[0].mat[1][2] = m[0].mat[2][0] = m[0].mat[2][1] = 0;
	for(int i = 1; i < 62; i++) m[i] = m[i-1]*m[i-1];
	ans.mat[0][0] = ans.mat[1][1] = ans.mat[2][2] = 1;
	ans.mat[0][1] = ans.mat[0][2] = ans.mat[1][0] = ans.mat[1][2] = ans.mat[2][0] = ans.mat[2][1] = 0;
}

int main(){
	int t;
	scanf("%d", &t);
	while(t--) {
		long long n, a;
		scanf("%lld %lld", &n, &a);
		build(a);
		for(int i = 0; i < 62; i++) {
			// cerr << (1ll<<i) << endl;
			if ((1ll<<i)&n) ans = ans * m[i];
		}
		printf("%lld\n", (ans.mat[0][1] + ans.mat[0][2])%mod);
	}
	return 0;
}