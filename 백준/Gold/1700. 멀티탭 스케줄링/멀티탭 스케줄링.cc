#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n, k;
    cin >> n >> k;
    
    vector<int> schedule(k);
    for (int i = 0; i < k; i++) {
        cin >> schedule[i];
    }
    
    set<int> plugged_in; // 현재 멀티탭에 꽂혀 있는 기기들
    int unplug_count = 0;

    for (int i = 0; i < k; i++) {
        int current_device = schedule[i];

        // 이미 꽂혀 있다면 넘어감
        if (plugged_in.count(current_device)) continue;

        // 멀티탭에 빈 자리가 있으면 그냥 꽂음
        if (plugged_in.size() < n) {
            plugged_in.insert(current_device);
            continue;
        }

        // 멀티탭이 가득 찼다면, 뺄 기기를 찾음
        int device_to_remove = -1, farthest_use = -1;
        
        for (int device : plugged_in) {
            // 현재 꽂혀 있는 기기가 다음에 언제 사용되는지 탐색
            int next_use = INT_MAX;
            for (int j = i + 1; j < k; j++) {
                if (schedule[j] == device) {
                    next_use = j;
                    break;
                }
            }

            // 가장 나중에 사용되거나, 사용되지 않는 기기를 선택
            if (next_use > farthest_use) {
                farthest_use = next_use;
                device_to_remove = device;
            }
        }

        // 기기를 제거하고 새로운 기기 꽂기
        plugged_in.erase(device_to_remove);
        plugged_in.insert(current_device);
        unplug_count++;
    }

    cout << unplug_count << '\n';
    return 0;
}
