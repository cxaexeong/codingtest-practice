#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

map<int, map<char, int>> nxt;  // Trie를 사전순 정렬 가능한 map으로 저장
map<int, bool> chk;
int unused = 1;  // Root는 0번 노드

// Trie에 접미사 삽입
void insert(const string& s) {
    int cur = 0;  // Root 노드부터 시작
    for (char c : s) {
        if (nxt[cur].find(c) == nxt[cur].end()) {
            nxt[cur][c] = unused++;
        }
        cur = nxt[cur][c];
    }
    chk[cur] = true;
}

// 사전순 정렬을 위해 Trie 탐색
vector<string> suffixes;
void dfs(int node, string s) {
    if (chk[node]) suffixes.push_back(s);  // 단어 끝에 도달하면 추가
    for (auto& p : nxt[node]) {  // map은 자동으로 키 기준 정렬됨
        dfs(p.second, s + p.first);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    int tc;  // 테스트 케이스 개수
    cin >> tc;
    for (int t = 1; t <= tc; t++) {
        nxt.clear();
        chk.clear();
        unused = 1;
        suffixes.clear();

        int k;
        string s;
        cin >> k >> s;

        // 모든 접미사 Trie에 삽입
        for (size_t i = 0; i < s.size(); i++) {
            insert(s.substr(i));
        }

        // Trie를 DFS 탐색하여 사전순 정렬된 접미사 찾기
        dfs(0, "");
        // 이미 DFS에서 사전순으로 삽입되므로 sort 생략 가능하지만 안전하게 유지
        sort(suffixes.begin(), suffixes.end());

        // K번째 접미사 출력
        cout << "#" << t << " ";
        if (k > suffixes.size()) cout << "none\n";
        else cout << suffixes[k - 1] << '\n';
    }
    return 0;
}
