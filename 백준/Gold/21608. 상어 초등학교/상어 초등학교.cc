#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> rooms;
vector<int> order;
map<int, vector<int>> like_student;

int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};

void place(int student) {
    int like_max = -1, empty_max = -1;
    pair<int,int> best_pos = {N,N};

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (rooms[x][y] != 0) continue;

            int empty_cnt = 0, like_cnt = 0;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                if (rooms[nx][ny] == 0) empty_cnt++;
                else if (find(like_student[student].begin(), like_student[student].end(), rooms[nx][ny]) != like_student[student].end()) {
                    like_cnt++;
                }
            }
            // 자리 선택 조건
            if (like_cnt > like_max || (like_cnt == like_max && empty_cnt > empty_max) ||
                (like_cnt == like_max && empty_cnt == empty_max && (x < best_pos.first || (x == best_pos.first && y < best_pos.second)))) {
                    like_max = like_cnt;
                    empty_max = empty_cnt;
                    best_pos = {x,y};
                }
        }
    }
    // 최적의 자리에 학생 배치
    rooms[best_pos.first][best_pos.second] = student;
}

int cal() {
    int scores[5] = {0, 1, 10, 100, 1000};
    int total = 0;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            int student = rooms[x][y];
            int cnt = 0;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;
                if (find(like_student[student].begin(), like_student[student].end(), rooms[nx][ny]) != like_student[student].end()) {
                    cnt++;
                }
            }
            total += scores[cnt];
        }
    }
    return total;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    rooms.assign(N, vector<int>(N,0));
    
    for (int i = 0; i < N*N; i++) {
        int student, a, b, c, d;
        cin >> student >> a >> b >> c >> d;
        order.push_back(student);
        like_student[student] = {a,b,c,d};
    }

    for (int o : order) {
        place(o);
    }

    cout << cal() << '\n';
    return 0;
}