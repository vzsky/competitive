#include<bits/stdc++.h>
using namespace std;


int p;
int cnt = 0;
int ch;

vector <int> let[4];

void play(int state, int from, int to){

    if (ch) return;
    if (cnt == p){
        for(int i = 1; i < 4; i++){
            printf("%c: ", i+'A'-1);
            if (let[i].empty()) printf("X");
            for(auto x : let[i]) printf("%d ", x);
            printf("\n");
            ch = 1;
        }
        return;
    }
    
    if (state == 1) {
        let[to].push_back(let[from].back());
        let[from].pop_back();
        cnt++;
        if (cnt == p){
            for(int i = 1; i < 4; i++){
                printf("%c: ", i+'A'-1);
                if (let[i].empty()) printf("X");
                for(auto x : let[i]) printf("%d ", x);
                printf("\n");
                ch = 1;
            }
            return;
        }
        return;
    }

    //cout << "play " << state-1 << ' ' << from << ' ' << 6-to-from << endl;
    play(state-1, from, 6-to-from);
    play(1, from, to);
    play(state-1, 6-to-from, to);
}

int main(){
    int q;
    scanf("%d", &q);
    for(int i = 1; i <=  q; i++){
        int n;
        cnt =ch= 0;
        scanf("%d %d", &n, &p);
        for(int i = n; i > 0; i--){
            let[1].push_back(i);
        }
        printf("Case %d:\n", i);
        play(n, 1, 3);
        let[1].clear(); let[2].clear(); let[3].clear();
    }
return 0;
}