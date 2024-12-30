#include <iostream>
using namespace std;

int main(){
    int n, k, s, y, count = 0;
    cin >> n >> k;
    
    int rooms[6][2] = {0}; // 학년별(0~5), 성별(0:남자, 1:여자)
    
    for (int i = 0; i < n; i++){
        cin >> s >> y;    // 성별, 학년
        rooms[y-1][s]++;  // 학년은 1부터 시작하므로 y - 1
    }
    
    for (int i = 0; i < 6; i++){        // 학년 반복
        for (int j = 0; j < 2; j++){    // 성별 반복
            count += (rooms[i][j] + k - 1) / k; // 올림 계산
        }
    }
    
    cout << count << endl;
    return 0;
}