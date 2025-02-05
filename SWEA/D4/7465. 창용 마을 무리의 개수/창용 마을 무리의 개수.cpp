#include <iostream>
#include <vector>
#include <unordered_set> 

using namespace std;

const int MAX_N = 101;
int parent[MAX_N], rank_[MAX_N]; // 부모 배열 & 랭크 배열

// 경로 압축을 적용한 find 함수
int find(int x) { 
    if (parent[x] != x) 
        parent[x] = find(parent[x]); // 경로 압축
    return parent[x];
}

// Union By Rank를 적용한 union 함수
void union_set(int a, int b) {
    int rootA = find(a);
    int rootB = find(b);
    
    if (rootA != rootB) {
        if (rank_[rootA] > rank_[rootB]) {
            parent[rootB] = rootA;
        } else if (rank_[rootA] < rank_[rootB]) {
            parent[rootA] = rootB;
        } else {
            parent[rootB] = rootA;
            rank_[rootA]++;
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int tc;
    cin >> tc;
    
    for (int t = 1; t <= tc; t++) { 
        int n, m;
        cin >> n >> m;

        for (int i = 1; i <= n; i++) {
            parent[i] = i;
            rank_[i] = 1;
        }

        for (int i = 0; i < m; i++) {
            int a, b;
            cin >> a >> b;
            union_set(a, b);
        }

        unordered_set<int> root;
        for (int i = 1; i <= n; i++) {
            root.insert(find(i));
        }

        cout << "#" << t << " " << root.size() << '\n';
    }

    return 0;
}
