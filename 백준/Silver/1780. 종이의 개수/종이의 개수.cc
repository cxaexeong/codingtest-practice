#include <bits/stdc++.h>
using namespace std;

int n;
int paper[2200][2200];
int cnt[3]; // -1, 0, 1의 개수 저장

bool check(int x, int y, int size) {
    int first = paper[x][y];
    for (int i = x; i < x + size; ++i) {
        for (int j = y; j < y + size; ++j) {
            if (paper[i][j] != first) {
                return false; // 하나라도 다르면 false
            }
        }
    }
    return true;
}

void recursive(int x, int y, int size) {
    // 주어진 구역(x,y)에서 size x size 크기의 종이가 모두 같은 숫자로 이루어져 있는지 확인
    // 단일 숫자라면, 해당 숫자를 카운트(cnt)에 반영하고 함수 종료
    if (check(x, y, size)) {
        cnt[paper[x][y] + 1]++; // 현재 구역의 숫자 개수 증가
        return;                 // 더 이상 분할하지 않고 종료
    }
  
    // 그렇지 않다면, 구역을 나눠 재귀적으로 처리
    int newSize = size / 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            recursive(x + i * newSize, y + j * newSize, newSize);
        }
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> paper[i][j];
    
    recursive(0, 0, n);
    
    for (int i = 0; i < 3; i++) 
        cout << cnt[i] << '\n';
    
    return 0;
}
