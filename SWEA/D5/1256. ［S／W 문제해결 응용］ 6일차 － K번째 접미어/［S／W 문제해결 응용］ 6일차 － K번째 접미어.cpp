#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int T;
    cin >> T;

    for (int tc = 1; tc <= T; tc++) {
        int K;
        string str;
        cin >> K >> str;

        vector<string> suffixes;

        // 접미어 생성
        for (int i = 0; i < str.length(); i++)
            suffixes.push_back(str.substr(i));

        // 사전 순 정렬
        sort(suffixes.begin(), suffixes.end());

        cout << "#" << tc << " ";
        if (K > suffixes.size()) cout << "none";
        else cout << suffixes[K - 1];
        cout << '\n';
    }
    return 0;
}
