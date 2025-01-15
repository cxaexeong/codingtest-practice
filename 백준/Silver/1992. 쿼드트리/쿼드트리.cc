#include <bits/stdc++.h>
using namespace std;

string board[65];
string result;
int n;

bool check(int x, int y, int size) {
    char first = board[x][y];    // 시작 위치의 값
    for (int i = x; i < x + size; i++)
        for (int j = y; j < y + size; j++) {
            if (board[i][j] != first) 
                return false;
        }
    return true;
}

void recursive(int x, int y, int size) {
    if (check(x, y, size)) {
        result += board[x][y];    // 현재 영역이 하나의 숫자로 구성된 경우 추가
        return;
    }
    
    result += "(";                // 영역을 나눌 때 괄호 시작
    int newSize = size / 2;
    // 왼쪽 위
    recursive(x, y, newSize);
    // 오른쪽 위
    recursive(x, y+newSize, newSize);
    // 왼쪽 아래
    recursive(x+newSize, y, newSize);
    // 오른쪽 아래
    recursive(x+newSize, y+newSize, newSize);
    result += ")";
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; i++)
        cin >> board[i];
    
    recursive(0, 0, n); // 쿼드 트리 압축 시작
    cout << result;     // 결과 출력
    return 0;      
}