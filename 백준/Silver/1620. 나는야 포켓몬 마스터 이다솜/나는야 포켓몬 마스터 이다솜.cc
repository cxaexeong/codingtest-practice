#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, m;
    cin >> n >> m;
    
    vector<string> pokemonByNumber(n+1);
    unordered_map<string, int> pokemonByName;
    
    for (int i = 1; i <= n; i++) {
        string name;
        cin >> name;
        pokemonByNumber[i] = name;    // 번호 -> 이름
        pokemonByName[name] = i;      // 이름 -> 번호
    }
        
    for (int i = 0; i < m; i++) {
        string query;
        cin >> query;
        
        // 숫자인지 판별
        if (isdigit(query[0])) {
            int num = stoi(query);
            cout << pokemonByNumber[num] << '\n';
        } else {
            cout << pokemonByName[query] << '\n';
        }
    }
    return 0;
}