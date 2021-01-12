#include<bits/stdc++.h>
using namespace std;

int str[1010], mic[26][26][1010];

int dis(int a, int b) {
    return min((b-a+26)%26, 26-(b-a+26)%26);
}
int main(){
    int t, ans;
    scanf("%d", &t);
    while(t--){
        string s;
        cin >> s;
        for(int i = 0; i <= s.size(); i++){
            for(int j = 0; j < 26; j++){
                for(int k = 0; k < 26; k++){
                    mic[j][k][i] = 2e9;
                }
            }
        }
        mic[0][0][0] = 0;
        for(int i = 0; i < s.size(); i++){
            str[i+1] = s[i]-'A';
        }
        // cerr << s << endl;
        for(int i = 1; i <= s.size(); i++){
            // cerr << dis(0, str[i]) << endl;
            for(int j = 0; j < 26; j++){
                for(int k = 0; k < 26; k++){
                    mic[str[i]][j][i] = min(mic[str[i]][j][i], mic[k][j][i-1]+dis(k, str[i]));
                    mic[j][str[i]][i] = min(mic[j][str[i]][i], mic[j][k][i-1]+dis(k, str[i]));
                }
                // cerr << str[i] << ' ' << j << ' ' << mic[str[i]][j][i] << endl;
            }
        }
        ans = 2e9;
        for(int i = 0; i < 26; i++){
            for(int j = 0; j < 26; j++){
                ans = min(ans, mic[i][j][s.size()]);
            }
        }
        printf("%d\n", ans);
    }
    return 0;
}