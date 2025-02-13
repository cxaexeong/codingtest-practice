#include <bits/stdc++.h>
using namespace std;

int n;
char node[101];  // 각 노드의 문자 저장
int leftChild[101], rightChild[101];  // 왼쪽, 오른쪽 자식 저장

void inorder(int cur) {
    if (cur == 0) return;  // 자식이 없으면 리턴
    inorder(leftChild[cur]);  // 왼쪽 자식 방문
    cout << node[cur];  // 현재 노드 출력
    inorder(rightChild[cur]);  // 오른쪽 자식 방문
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    for (int tc = 1; tc <= 10; tc++) {
        cin >> n;
        memset(leftChild, 0, sizeof(leftChild));
        memset(rightChild, 0, sizeof(rightChild));

        for (int i = 1; i <= n; i++) {
            int idx;
            char val;
            cin >> idx >> val;
            node[idx] = val;
            // 다음 입력 문자가 개행문자(\n)인지 확인
            if (cin.peek() != '\n') {
                int l;
                cin >> l;
                leftChild[idx] = l;
            }
            if (cin.peek() != '\n') {
                int r;
                cin >> r;
                rightChild[idx] = r;
            }
        }

        cout << "#" << tc << " ";
        inorder(1);
        cout << '\n';
    }
    return 0;
}
