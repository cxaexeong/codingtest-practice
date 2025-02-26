#include <bits/stdc++.h>
using namespace std;

int n, s;
vector<int> arr;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> s;
    arr.resize(n);
    for (int i = 0; i < n; i++) cin >> arr[i];

    int st = 0, en = 0, sum = 0;
    int min_len = INT_MAX;  // 최소 길이 저장

    while (en < n) {
        sum += arr[en];  // 구간 확장
        while (sum >= s) {  // S 이상이 되면 최소 길이 갱신
            min_len = min(min_len, en - st + 1);
            sum -= arr[st];  // st를 오른쪽으로 이동하여 합 줄이기
            st++;
        }
        en++;
    }

    cout << (min_len == INT_MAX ? 0 : min_len);  // 가능한 길이가 없으면 0 출력
}
