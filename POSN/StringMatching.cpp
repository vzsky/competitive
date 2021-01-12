/*
String Matching Algo

problem : given string a of length n, pattern b of length m. how many b in a and where?

Algorithms :
    - Bruteforce O(n x m)
    - Rabin Karp O(n + m)
    - Knutt Morris Pratt (KMP) O(n + m)

    - Rabin Karp :
        - Using hash

        - Let each character refers a number in base 26++
        - Translate pattern base 26++ -> Dec.
        - Hash each str in string a of length m
        - If Hash str == Hash pattern :
            Run Bruteforce of O(m) to check or else Continue
        - To continue hashing each str:
            First str is hashed in O(m)
            Next strs are hashed in O(1):
                012 B26 -> X Dec
                123 B26 -> X - ((0*26^2)*26) + 3*26^0

    - RMP :
        - a prefix function array of pattern
            - how many of first elem is = to last elem at i
            - i run every char in pattern
            - j stores number of prefix at i-1
            - for every loop :
                first j == last j at i-1
                if (char[j+1] == char[i]) // j+1th and ith 
                    j++; since j+1th == ith
                else
                    while(j > 0 && b[i+1]!=b[j]) {
                        j = p[j]
                    }
                    if (b[i+1]!=b[j]) j++
                then -> p[i] = j


        - let example b[] = {-,a,b,a,b,a,c,a}
            i = 2;
            check b[2] == b[1]
            -> No j = 0
            i = 3
            check b[3] == b[1]
            -> Yes j = 1
            i = 4
            check b[4] == b[2]
            -> Yes j = 2
            i = 5
            check b[5] == b[3]
            -> Yes j = 3
            i = 6
            check b[6] == b[4]
            -> No check[6] == b[2] // since b[5] == b[3] == b[p[3]] == b[1]
            -> No j = 0
            i = 7
            check b[7] == b[1]
            j = 1

*/

#include<bits/stdc++.h>
using namespace std;

#define HashMod 100003
#define BASE 29

char text[1000100], pattern[1000100];

void rabinkarp (char text[], char pattern[]){
    int len_text, len_pattern, hash_text=0, hash_pattern=0, shift = 1;
    len_text = strlen(text);
    len_pattern = strlen(pattern);
    // Hashing pattern and first set of length m of text
    // Initing
    for(int i = 0; i < len_pattern; i++){
        hash_text = (hash_text*BASE)+(text[i]-'0');
        hash_text %= HashMod;
        hash_pattern = (hash_pattern*BASE)+(pattern[i]-'0');
        hash_pattern %= HashMod;
    }
    for(int i = 1; i < len_pattern; i++){
        shift = (shift*BASE)%HashMod;
    }
    // RabinKarp Loop
    for(int i = 0; i < len_text-len_pattern; i++){
        if (hash_text == hash_pattern){
            for(int j = 0; j < len_pattern; j++){
                if (text[i+j] != pattern[j]) break;
                if (j == len_pattern-1){
                    printf("Lucky\n"); return;
                }
            }
        }
        hash_text -= ((text[i]-'0')*(shift))%HashMod;
        hash_text = (hash_text + HashMod) % HashMod;
        hash_text = (hash_text * BASE) % HashMod;
        hash_text += (text[i+len_pattern]-'0');
        hash_text %= HashMod;
    }
    printf("Unlucky\n");
    return;
}

void KMP (char text[], char pattern[]) {
    int len_text = strlen(text+1);
    int len_pattern = strlen(pattern+1);
    int p[1000100];
    int j = 0;
    for(int i = 2; i <= len_pattern; i++){
        while(j > 0 && pattern[j+1] != pattern[i]) j = p[j];
        if (pattern[j+1] == pattern[i]) j++;
        p[i] = j;
    }
    j = 0;
    for(int i = 1; i <= len_text; i++){
        while(j > 0 && pattern[j+1] != text[i]) j = p[j];
        if (pattern[j+1] == text[i]) j++;
        if (j == len_pattern) { printf("Lucky\n"); return ;}
    }
    printf("Unlucky\n");
}

int main(){
    // scanf(" %s %s", text+1, pattern+1);
    // rabinkarp(text, pattern)

    scanf(" %s %s", text, pattern);
    KMP(text, pattern);
    return 0;
}