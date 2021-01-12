#include<bits/stdc++.h>
using namespace std;

char a[20];

int main(){
    int q;
    scanf("%d", &q);
    for(int i = 0; i < q; i++){
        int ans = 0;
        cin >> a;
        for(int j = 0; j < strlen(a); j++){
            switch (a[j]) {
                case 'A' : ans +=1;
                case 'K' : ans +=1;
                case 'Q' : ans +=1;
                case 'J' : ans +=1;
                break;
            }
        }
        cout << ans;
    }
    return 0;
}