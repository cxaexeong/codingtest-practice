#include <bits/stdc++.h>
using namespace std;

int N;
vector<vector<int>> room;
map<int, vector<int>> like_map;
vector<int> order;

int dx[4] = {1,0,-1,0};
int dy[4] = {0,1,0,-1};

struct Student {
    int id;
    vector<int> likes;
};

void place(int student) {
    vector<vector<int>> like_count(N, vector<int>(N,0));
    vector<vector<int>> empty_count(N, vector<int>(N,0));

    int max_like = -1, max_empty = -1;
    pair<int,int> best_pos = {N,N};
    
    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            if (room[x][y] != 0) continue; // 이미 학생이 있음

            int like_cnt = 0, empty_cnt = 0;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                if (room[nx][ny] == 0) empty_cnt++; // 빈자리 카운트
                else if (find(like_map[student].begin(), like_map[student].end(), room[nx][ny]) != like_map[student].end()) {
                    like_cnt++; // 좋아하는 학생 카운트
                }
            }
            // 자리 선택 조건 갱신
            if (like_cnt > max_like || (like_cnt == max_like && empty_cnt > max_empty) ||
                (like_cnt == max_like && empty_cnt == max_empty && (x < best_pos.first || (x == best_pos.first && y < best_pos.second)))) {
                    max_like = like_cnt;
                    max_empty = empty_cnt;
                    best_pos = {x,y};
                }
        }
    }
    // 최적의 자리에 학생 배치
    room[best_pos.first][best_pos.second] = student;
}

int cal() {
    int score[5] = {0, 1, 10, 100, 1000};   // 인접한 좋아하는 학생 수에 따른 점수
    int total_score = 0;

    for (int x = 0; x < N; x++) {
        for (int y = 0; y < N; y++) {
            int student = room[x][y];
            int like_cnt = 0;

            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d], ny = y + dy[d];
                if (nx < 0 || nx >= N || ny < 0 || ny >= N) continue;

                if (find(like_map[student].begin(), like_map[student].end(), room[nx][ny]) != like_map[student].end()) {
                    like_cnt++;
                }
            }
            total_score += score[like_cnt];
        }
    }
    return total_score; 
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> N;
    room.assign(N, vector<int>(N,0));

    for (int i = 0; i < N*N; i++) {
        int student, a, b, c, d;
        cin >> student >> a >> b >> c >> d;
        order.push_back(student);
        like_map[student] = {a, b, c, d};
    }

    for (int student : order) {
        place(student);
    }

    cout << cal() << endl;
    return 0;  
}