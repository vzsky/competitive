#include<bits/stdc++.h>	
using namespace std;		

bool is_vowel (char c) {	  
  for (char vowel : "aeiou") {	    
    if (c == vowel) return true;	  
  } 	  
  return false;	
}	

int main () {		 
  string encoded;
  getline(cin, encoded);
  for (int i = 0; i < encoded.size(); i++) {
    if (is_vowel(encoded[i])) i += 2;	   
    cout << encoded[i];	 
  }	  	
  return 0;	
}	
