#include <bits/stdc++.h>
using namespace std;

int n,a,b;
pair<int,int> p[100004];

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> p[i].second >> p[i].first;
    }
    
    //sort(p, p+n, [](const pair<int,int> &x, const pair<int,int> &y) {
    //    if (x.second == y.second) return x.first < y.first; // y가 같으면 x기준 정렬
    //    return x.second < y.second; // y좌표 기준 정렬
    //});
    sort(p, p+n);
    
    for (int i = 0; i < n; i++) {
        cout << p[i].second << ' ' << p[i].first << '\n';
    }
    return 0;        
}

/*
pair의 정렬 순서는 first를 먼저 비교하기 때문에 둘의 자리를 바꿔서 집어넣은 후 정렬함.
*/