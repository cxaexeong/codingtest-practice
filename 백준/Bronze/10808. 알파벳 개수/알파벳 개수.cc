#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    int counts[26] = {0};
    
    for (char c : s){
        counts[c - 'a']++;
    }
    
    for (int i = 0; i < 26; i++){
        cout << counts[i] << " ";
    }
    return 0;
}