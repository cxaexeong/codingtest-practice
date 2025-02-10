#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;
    cin >> tc;

    for (int t = 1; t <= tc; t++) {
        int n, m;
        cin >> n >> m;

        unordered_set<string> setA;
        string word;

        for (int i = 0; i < n; i++) {
            cin >> word;
            setA.insert(word);
        }

        int cnt = 0;
        for(int i = 0; i < m; i++) {
            cin >> word;
            // word가 setA에도 존재하면, 그 위치의 반복자 반환/ 존재안하면 setA.end() 반환 (즉, 찾지못했음 의미)
            if (setA.find(word) != setA.end()) cnt++;
        }
        cout << "#" << t << " " << cnt << '\n';
    }
    return 0;
}