#include<bits/stdc++.h>
using namespace std;

map<int,int> m;
int n, q, inp, cou = 1, l, r, col, low, up;
vector<int> cnt[100100];

int main(){
	scanf("%d %d", &n, &q);
	for(int i = 1; i <= n; i++){
		scanf("%d", &inp);
		if (m[inp] == 0) {
			m[inp] = cou++;
		}
		cnt[m[inp]].push_back(i);
	}
	while(q--){
		scanf("%d %d %d", &l, &r, &col);
		col = m[col];
		low = lower_bound(cnt[col].begin(), cnt[col].end(), l) - cnt[col].begin();
		up = upper_bound(cnt[col].begin(), cnt[col].end(), r) - cnt[col].begin();
		printf("%d\n", up-low);
	}
	return 0;
}