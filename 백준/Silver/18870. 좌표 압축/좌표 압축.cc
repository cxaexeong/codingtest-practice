#include <bits/stdc++.h>
using namespace std;

int n;
vector<int> x, sorted_x;
unordered_map<int,int> compressed;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    x.resize(n);
    
    for (int i = 0; i < n; i++) cin >> x[i];
    
    // 1. 배열 복사 및 정렬 
    sorted_x = x;
    sort(sorted_x.begin(), sorted_x.end());
    
    // 2. 중복 제거 후 압축된 좌표 매핑
    sorted_x.erase(unique(sorted_x.begin(), sorted_x.end()), sorted_x.end());
    for (int i = 0; i < sorted_x.size(); i++) {
        compressed[sorted_x[i]] = i;
    }
    
    // 3. 변환된 좌표 출력
    for (int i = 0; i < n; i++) {
        cout << compressed[x[i]] << ' ';
    }
}