#include <bits/stdc++.h>

using namespace std;

vector<int> leftChild, rightChild;
vector<char> nodeData;

void inorderTraversal(int nodeIdx) {
    if (nodeIdx == -1) return;
    inorderTraversal(leftChild[nodeIdx]);
    cout << nodeData[nodeIdx];
    inorderTraversal(rightChild[nodeIdx]);
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    for (int tc = 1; tc <= 10; ++tc) {
        int n;
        cin >> n;
        
        leftChild.assign(n + 1, -1);
        rightChild.assign(n + 1, -1);
        nodeData.assign(n + 1, ' ');
        
        for (int i = 1; i <= n; ++i) {
            int index;
            char data;
            cin >> index >> data;
            
            nodeData[index] = data;
            
            if (2 * index <= n) cin >> leftChild[index];  // 왼쪽 자식
            if (2 * index + 1 <= n) cin >> rightChild[index]; // 오른쪽 자식
        }
        
        cout << "#" << tc << " ";
        inorderTraversal(1);
        cout << "\n";
    }
    
    return 0;
}
