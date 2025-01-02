#include <bits/stdc++.h>
using namespace std;

int main(){
    int t;
    cin >> t;
    while (t--){
        string input;
        cin >> input;
        list<char> L;
        auto cursor = L.begin();

        for (char c : input){
            if (c == '<'){
                if (cursor != L.begin()) cursor--;
            } else if (c == '>') {
                if (cursor != L.end()) cursor++;
            } else if (c == '-'){
                if (cursor != L.begin()){
                    cursor--;
                    cursor = L.erase(cursor);
                }
            } else {
                L.insert(cursor, c);
            }
        }
        for (char c : L) cout << c;
        cout << '\n';
    }
    return 0;
}